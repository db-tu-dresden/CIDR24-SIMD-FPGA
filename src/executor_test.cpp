
#include <CL/sycl.hpp>
#include <sycl/ext/intel/fpga_extensions.hpp>
#include <iostream>
#include <tuple>
#include <utility>
#include <type_traits>


template<typename T>
auto test_kernel(T* out, T const * in, std::size_t element_count) {
  out[0] = in[3];
  return element_count;
}

class host_executor {
  public:
    decltype(auto) operator()(auto&& fun, auto&&... args) {
      return fun(std::forward<decltype(args)>(args)...);
    }
};

class one_api_executor {    
  protected:
    static void exception_handler(sycl::exception_list exceptions) {
        for (std::exception_ptr const& e : exceptions) {
            try {
                std::rethrow_exception(e);
            } catch (sycl::exception const& e) {
                std::cout << "Caught asynchronous SYCL exception:\n"
                          << e.what() << std::endl;
            }
        }
    }
};

template<typename T>
struct oneApiPtrWrapper {
  using type = 
    std::conditional_t<
      std::is_pointer_v<std::remove_reference_t<T>>,
      sycl::ext::intel::host_ptr<std::remove_pointer_t<std::remove_reference_t<T>>>,
      std::remove_reference_t<T>
    >;
  type const value;
  explicit oneApiPtrWrapper(T _value) : value(_value) {}
  auto get() const { 
    if constexpr (std::is_same_v<type, sycl::ext::intel::host_ptr<std::remove_pointer_t<std::remove_reference_t<T>>>>) {
        return value.get();
    } else {
        return value; 
    }
  }
};

template<class Fun, class Tuple, std::size_t... I>
static inline __attribute__((always_inline)) auto call_get_and_apply_lambda_impl(Fun fun, Tuple&& tuple, std::index_sequence<I...>) {
  return fun(std::get<I>(std::forward<Tuple>(tuple)).get()...);
}
template<class Fun, class Tuple, std::size_t... I>
static inline __attribute__((always_inline)) auto call_get_and_apply_lambda_impl(Fun* fun, Tuple&& tuple, std::index_sequence<I...>) {
  return (*fun)(std::get<I>(std::forward<Tuple>(tuple)).get()...);
}

template<typename Selector>
class one_api_device_coprocess_executor: public one_api_executor {
  private:
    Selector selector = Selector{};
    sycl::queue q;
  public:
    one_api_device_coprocess_executor(
      auto&& one_api_queue_properties
    ): q{selector, one_api_executor::exception_handler, one_api_queue_properties} {
      // make sure the device supports USM device allocations
      sycl::device d = q.get_device();
      if (!d.get_info<sycl::info::device::usm_device_allocations>()) {
          std::cerr << "ERROR: The selected device does not support USM device"
                    << " allocations" << std::endl;
          std::terminate();
      }
      if (!d.get_info<sycl::info::device::usm_host_allocations>()) {
          std::cerr << "ERROR: The selected device does not support USM host"
                    << " allocations" << std::endl;
          std::terminate();
      }
    }
  public:
    template<typename Fun, typename... Args>
    decltype(auto) operator()(Fun fun, Args... args) {
      q.submit(
        [&](sycl::handler& h) {
          h.single_task<Fun>([&]() [[intel::kernel_args_restrict]] {
            // []<typename LambdaFun, typename Tuple, size_t... I>(LambdaFun&& _fun, Tuple _args, std::index_sequence<I...>) mutable {
            //   _fun(std::get<I>(_args).get()...);
            // }(std::forward<Fun>(fun), std::forward_as_tuple(oneApiPtrWrapper<Args>(args)...), std::make_index_sequence<sizeof...(Args)>{});
            auto oneApiPtrWrappers = std::make_tuple(oneApiPtrWrapper<Args>(args)...);
            [fun, oneApiPtrWrappers]<size_t... I>(std::index_sequence<I...>) mutable {
              (*fun)(std::get<I>(oneApiPtrWrappers).get()...);
            }(std::make_index_sequence<sizeof...(Args)>{});
            // if constexpr (std::is_pointer_v<std::decay_t<Fun>>) {
            //   return call_get_and_apply_lambda_impl(fun, std::forward_as_tuple(oneApiPtrWrapper<Args>(args)...), std::make_index_sequence<sizeof...(Args)>{});
            // } else {
            //   return call_get_and_apply_lambda_impl(&fun, std::forward_as_tuple(oneApiPtrWrapper<Args>(args)...), std::make_index_sequence<sizeof...(Args)>{});
            // }
            // fun(oneApiPtrWrapper<Args>(args).get()...);
            // return std::apply(std::forward<Fun>(fun), std::forward_as_tuple(oneApiPtrWrapper<Args>(args).get()...));
            // return one_api_functor<Fun>::apply(std::forward<Fun>(fun), args...);
          });
        }
      ).wait();
    }
};



int main() {
  auto a = reinterpret_cast<int *>(malloc(100*sizeof(int)));
  auto b = reinterpret_cast<int *>(malloc(100*sizeof(int)));
  a[0] = 1337;
  b[0] = 42;
  //auto props = ;

  one_api_device_coprocess_executor<sycl::ext::intel::fpga_emulator_selector>
    executor{sycl::property_list{sycl::property::queue::enable_profiling()}};

  executor(test_kernel<int>, a, b, 100);

  return 0;
}