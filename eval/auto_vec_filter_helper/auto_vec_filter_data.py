import numpy as np
import pandas as pd
from pathlib import Path
import matplotlib.pyplot as plt
import seaborn as sns
import math

import sys

# Path to the data
data_path = Path('./auto_vec_filter_results')
aggregate_result_path = data_path.joinpath('aggregate_results.tsv')
masked_aggregate_result_path = data_path.joinpath('masked_aggregate_results.tsv')

def get_width(tuple_count: int) -> float:
    width = 0.8 / tuple_count
    if width > 0.2:
        return 0.2
    return width

def get_offsets(tuple_count: int) -> list:
    width = get_width(tuple_count)
    x_offsets = []
    """ Calculate x-offsets based on even or odd number of bars """
    if tuple_count % 2 == 0:
        for i in range(0, int(tuple_count / 2)):
            x_offsets.append((-0.5 - i) * width)
        for i in range(0, int(tuple_count / 2)):
            x_offsets.append((0.5 + i) * width)
    else:
        for i in range(0, int(tuple_count / 2)):
            x_offsets.append((-1 - i) * width)
        x_offsets.append(0.0)
        for i in range(0, int(tuple_count / 2)):
            x_offsets.append((1 + i) * width)
    return sorted(x_offsets)

def beautify_data_size(size: int, appendStr = True) -> str:
  def ending(s):
     if appendStr:
        return f" {s}"
     else:
        return ""
  def divide(s, d):
     if s%d == 0:
        return f"{int(s//d)}"
     else:
        return f"{int(round(s/d, 2))}"
  if size < 1024:
    return f"{divide(size, 1)}{ending('B')}"
  elif size < 1024*1024:
    return f"{divide(size, 1024)}{ending('KiB')}"
  elif size < 1024*1024*1024:
    return f"{divide(size, (1024*1024))}{ending('MiB')}"
  else:
    return f"{divide(size, (1024*1024))}{ending('MiB')}"

# define a easy distinguishable custom color palette for the element_size
custom_palette = sns.color_palette("bright", 4)
color_dict = { 1: custom_palette[0], 2: custom_palette[1], 4: custom_palette[2], 8: custom_palette[3] }
new_labels = ['ui8', 'ui16', 'ui32', 'ui64']
datatype_dict = { 1: new_labels[0], 2: new_labels[1], 4: new_labels[2], 8: new_labels[3]}
label_to_datatype_dict = { new_labels[0]: 1, new_labels[1]: 2, new_labels[2]: 4, new_labels[3]: 8}
arch_labels = { "noArch": "No Arch-Flags", "sse": "SSE Arch-Flags", "avx": "AVX(2) Arch-Flags", "avx512": "AVX512 Arch-Flags"}

def read_aggregate_data():
  aggregate_result_df = pd.read_csv(aggregate_result_path, sep='\t')
  print("Head of aggregate result:")
  print("Number of rows in aggregate result: ", len(aggregate_result_df))
  return aggregate_result_df

def slice_aggregate_data(df, cpu, compiler):
  new_df = df.loc[(df['cpu'] == cpu) & (df['compiler'] == compiler)]
  # Calculate the average time for each function, variant, SIMD-elementCount, byte_size and element_size
  mean_aggregate_result_df = new_df.groupby(['cpu', 'compiler', 'version', 'arch-flags', 'function', 'variant', 'SIMD-elementCount', 'byte_size', 'element_size']).mean()["time_mus"].reset_index()
  # Calculate the throughput in GiB/s
  mean_aggregate_result_df["throughput (GiB/s)"] = (mean_aggregate_result_df["byte_size"] /(1024*1024*1024)) / (mean_aggregate_result_df["time_mus"]/1e9)
  # Beautify the byte_size column, so that it is displayed as KiB, MiB, GiB, ..
  mean_aggregate_result_df["beautified_byte_size"] = mean_aggregate_result_df["byte_size"].apply(lambda x: beautify_data_size(x))
  # Get the "variant" with the hightest throughput depending on the compiler, the version, the arch-flags, the SIMD-elementCount, the byte_size and the element_size
  max_throughput_df = mean_aggregate_result_df.loc[mean_aggregate_result_df.groupby(['cpu', 'compiler', 'version', 'arch-flags', 'SIMD-elementCount', 'byte_size', 'element_size'])["throughput (GiB/s)"].idxmax()]
  return (new_df, mean_aggregate_result_df, max_throughput_df)

def plot_aggregate_data(df):
  # for arch_flag in df["arch-flags"].unique():
  
  arch_dict = dict()

  for arch_flag in ["noArch", "sse", "avx", "avx512"]:
    arch_df = df.loc[df["arch-flags"] == arch_flag]
    # for every distinct variant get the number of occurences in max_throughput_df
    distinct_variants_count = arch_df["variant"].value_counts()
    # debug stuff
    # print("Variants producing the highest throughput for each function, SIMD-elementCount, byte_size and element_size:")
    # print(distinct_variants_count)

    # Plot the throughput as a bar plot using the SIMD-ElementCount as x-axis, the throughput as y-axis, the element_size as hue (using the custom color palette) and the byte_size and arch-flags as facet
    g = sns.catplot(x="SIMD-elementCount", y="throughput (GiB/s)", hue="element_size", col="byte_size", palette=custom_palette, data=arch_df, kind="bar", height=4, aspect=1)
    
    g.set_axis_labels("Elements in tight loop", "Throughput (GiB/s)")
    # Set the grid to be displayed
    g.despine(left=True)
    # Remove space between the facets
    plt.subplots_adjust(wspace=0.1)  

    # Change the legend title
    # g._legend.set_title("Processed Data types")


    # Set the titles for each facet using beautify_data_size(col_name)
    for ax in g.axes.flat:
      title = ax.get_title()
      # Remove the "byte_size=" part of the title
      title = int(float(title.replace("byte_size = ", "")))
      # Get the maximum throughput from max_throuhgput_df for title = byte_size, for every element_size
      current_df = arch_df.loc[arch_df["byte_size"] == title]
      # As there are multiple entries, get the maximum and the minimum throughput for every element_size
      max_throughput = current_df.groupby("element_size")["throughput (GiB/s)"].max()
      min_throughput = current_df.groupby("element_size")["throughput (GiB/s)"].min()  

      if title not in arch_dict:
        arch_dict[title] = dict()
      if arch_flag not in arch_dict[title]:
        arch_dict[title][arch_flag] = 0
      arch_dict[title][arch_flag] = max(arch_dict[title][arch_flag],max_throughput.max())

      for element_size, throughput in max_throughput.items():
        # For every throughput value, draw a horizontal line in the color of the element_size (using the custom color palette)
        ax.axhline(throughput, color=color_dict[element_size], linestyle='--', linewidth=1)
      
      # Write every throughput value one below the other starting from the maximum throughput at the top left corner of the facet. The text should have a white background with no text border, the text should be evenly spaced
      for i, (element_size, throughput) in enumerate(max_throughput.items()):
        # get the corresponding value for the minimum throughput for the given element_size
        min_throughput_value = min_throughput[element_size]
        ax.text(0.05, 0.95 - i*0.05, f"{datatype_dict[element_size]}: [{min_throughput_value:.2f}, {throughput:.2f}] GiB/s", transform=ax.transAxes, color=color_dict[element_size], fontsize=10, bbox=dict(facecolor='white', edgecolor='none', pad=0.5))
        
      ax.set_title(beautify_data_size(int(float(ax.get_title().split("=")[1]))))
      ax.grid(True, which='major', linestyle='--')
      ax.grid(True, which='minor', linestyle=':')
      ax.set_axisbelow(True)
    
    # Change the legend labels
    for t, l in zip(g._legend.texts, new_labels): t.set_text(l)

    # Change the legend from vertical to horizontal
    """ Doesn't work in Py 3.8 ¯\_(ツ)_/¯ """
    # handles, labels = g._legend.legend_handles, new_labels
    handles, labels = g.axes.flat[0].get_legend_handles_labels()
    labels = new_labels
    g._legend.remove()
    g.fig.legend(title= "Processed Data Types", handles=handles, labels=labels, ncol=4, loc='lower center', bbox_to_anchor=(0.5, -0.15))
    g.fig.suptitle(arch_labels[arch_flag], fontsize=16, y=1.05, ha='center', va='top', bbox=dict(facecolor='white', edgecolor='none', pad=5.0))
    plt.show()
    plt.close()

  plot_idx = 0
  fig, axs = plt.subplots(1, len(arch_dict), sharey=True, figsize=(14,4))
  fig.suptitle("Highest throughput by architecture flag")
  for element_size in arch_dict:
    ax = axs[plot_idx]
    ax.grid(linestyle='--',color="lightgrey")
    ax.set_title( beautify_data_size(element_size) )
    if plot_idx == 0:
      ax.set_ylabel("Throughput (GiB/s)")
    lists = sorted(arch_dict[element_size].items())
    x, y = zip(*lists)
    ax.bar(x, y, zorder=3)
    plot_idx += 1
  plt.close()


def bars_for_variant( df, variant, element_sizes, data_size):
  bar_data = []
  if "Autovec" in variant:
    for es in element_sizes:
      bar_data.append( df[ (df["variant"].str.contains("autovec")) & (df["element_size"] == es) & (df["byte_size"] == data_size) ][ "throughput (GiB/s)" ].max() )
  else:
    for es in element_sizes:
      bar_data.append( df[(df["variant"] == variant) & (df["element_size"] == es) & (df["byte_size"] == data_size) ][ "throughput (GiB/s)" ].max() )
     
  for i in range(0,len(bar_data)):
    if math.isnan(bar_data[i]):
      bar_data[i] = 0
  return bar_data

def plot_large_combined_grid(df):
  fig = plt.figure(constrained_layout=True, figsize=(10,12))
  # fig.suptitle('Figure title')

  sizes = df["byte_size"].unique()
  element_sizes = df["element_size"].unique()
  variants = df["variant"].unique()
  scalar_idx = np.argwhere(variants=="scalar")
  variants = np.delete(variants, scalar_idx)
  auto_idxs = [x for x,y in enumerate(variants) if "autovec" in y]
  auto_idxs.sort(reverse=True)
  for aidx in auto_idxs:
      variants = np.delete(variants,aidx)
  variants = np.append(variants,"Autovec*")
  variants.sort()

  width = get_width(len(variants))

  # create Mx1 row layout
  subfigs = fig.subfigures(nrows=len(new_labels), ncols=1)
  for row, subfig in enumerate(subfigs):
      subfig.suptitle(f'Base Type: {new_labels[row]}')

      X = np.arange(len(element_sizes))
      x_offsets = get_offsets(len(variants))

      # create 1xN subplots per subfig
      axs = subfig.subplots(nrows=1, ncols=len(sizes), sharey=True)
      for col, ax in enumerate(axs):
          if col == 0:
            ax.set_ylabel("Throughput (GiB/s)")
          for variant_idx in range(0,len(variants)):
            variant_data = bars_for_variant(df, variants[variant_idx], element_sizes, sizes[col])
            ax.bar(X + x_offsets[variant_idx], variant_data, width=width, edgecolor='black', zorder=3, label=variants[variant_idx])
            ax.legend(loc='upper center', bbox_to_anchor=(0.5, -0.25), fancybox=True, shadow=True, ncol=3, fontsize=6)
            # ax.legend(loc='upper center', bbox_to_anchor=(0.5, 1.05), ncol=3, fancybox=True, shadow=True, fontsize=5)
            ax.set_xticks(X, [f"{int(e)*8} Byte" for e in element_sizes])
            ax.set_xlabel("Data Element Size")
          ax.set_title(f'{beautify_data_size(sizes[col])}')
  plt.show()
  plt.close()