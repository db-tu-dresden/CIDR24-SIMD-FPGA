import jinja2

datatypes = {
    "smallint": ["-DUI8", "-DUI16"],
    "bigint": ["-DUI32", "-DUI64"],
    "ui8" : ["-DUI8"],
    "ui16": ["-DUI16"],
    "ui32": ["-DUI32"],
    "ui64": ["-DUI64"]    
}
vector_lenghts = {
    "128_to_512": ["-DVL128", "-DVL256", "-DVL512"],
    "1K_to_4K": ["-DVL1024", "-DVL2048", "-DVL4096"],
    "128": ["-DVL128"],
    "256": ["-DVL256"], 
    "512": ["-DVL512"],
    "1k" : ["-DVL1024"],
    "2k" : ["-DVL2048"],
    "4k" : ["-DVL4096"]    
}
operators = {
    "aggregate_autovec" : "src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp",
    "lzc_unrolled_and_aggregate_outDevice" : "src/lzc_unrolled_and_aggregate_test.cpp",
    "modulo_and_aggregate_outDevice" : "src/modulo_test_and_aggregate.cpp",
    "hadd" : "src/hadd_test.cpp"
}
templateLoader = jinja2.FileSystemLoader(searchpath="./")
templateEnv = jinja2.Environment(loader=templateLoader)
template = templateEnv.get_template("makefile.j2")

with open("Makefile_generated", "w") as f:
  for op in operators:
      for dt in datatypes:
          for vl in vector_lenghts:
              f.write(
                template.render({
                  "operator": op,
                  "source": operators[op],
                  "datatype": dt,
                  "dtypeDef": " ".join(datatypes[dt]),
                  "vector_length": vl,
                  "vlDef": " ".join(vector_lenghts[vl])
                })
              )
              f.write("\n")

print("#Execute make for combined targets")
for op in operators:
    for dt in datatypes:
        if len(datatypes[dt]) > 1:
            for vl in vector_lenghts:
                if len(vector_lenghts[vl]) > 1:
                    print(f"make bench_{op}_{dt}_VL{vl} >> build_{op}_{dt}_VL{vl}.log 2>&1")

print("#Execute make for special targets (use them if design is to big to fit)")
for op in operators:
    for dt in datatypes:
        if len(datatypes[dt]) == 1:
            for vl in vector_lenghts:
                print(f"#make bench_{op}_{dt}_VL{vl} >> build_{op}_{dt}_VL{vl}.log 2>&1")
        else:
            for vl in vector_lenghts:
              if len(vector_lenghts[vl]) == 1:
                print(f"#make bench_{op}_{dt}_VL{vl} >> build_{op}_{dt}_VL{vl}.log 2>&1")

print("----------------------------")
with open("run_all.sh", "w") as f:
    f.write("#!/bin/bash\n")
    f.write("CWD=$(pwd)\n")
    f.write("cd ${CWD}/build\n")
    
    executables = [
        "bench_conflict_detection_unrolled_and_aggregate_ui64_VL512.fpga",
        "bench_conflict_detection_unrolled_and_aggregate_ui64_VL1K.fpga",
        "bench_conflict_detection_unrolled_and_aggregate_ui32_VL512.fpga"
        ]
    for op in operators:
        for dt in datatypes:
            if len(datatypes[dt]) > 1:
                for vl in vector_lenghts:
                    if len(vector_lenghts[vl]) > 1:
                        executables.append(f"bench_{op}_{dt}_VL{vl}.fpga")
    for exec in executables:
        for s in ["1MiB", "2MiB", "4MiB", "8MiB", "16MiB", "32MiB", "64MiB", "128MiB", "256MiB", "512MiB", "1GiB"]:
            f.write(f"./{exec} --size {s}\n")