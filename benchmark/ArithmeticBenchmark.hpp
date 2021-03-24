#pragma once

#include <cpp-benchmark/PerfBenchmark.hpp>

template<typename T>
struct add {
   forceinline T operator()(const T& v1, const T& v2) {
      return v1 + v2;
   }
};

template<typename T>
struct subtract {
   forceinline T operator()(const T& v1, const T& v2) {
      return v1 - v2;
   }
};

template<typename T>
struct mul {
   forceinline T operator()(const T& v1, const T& v2) {
      return v1 * v2;
   }
};

template<typename T>
struct division {
   T operator()(const T& v1, const T& v2) {
      return v1 / v2;
   }
};

template<typename T>
struct mod {
   __attribute__((optimize("no-tree-vectorize"))) forceinline T operator()(const T& v1, const T& v2) {
      return v1 % v2;
   }
};

template<typename T>
struct shift {
   forceinline T operator()(const T& v1, const T& v2) {
      return v2 << v1;
   }
};

template<typename T, template<typename> typename Operation = add>
class ArithmeticBenchmark : public benchmark::PerfBenchmark {
  private:
   size_t iterations = 0;

  public:
   void SetUp(benchmark::State& st) override {
      iterations = st.range(0);
   }

   __attribute__((optimize("no-tree-vectorize"))) forceinline void Measure(benchmark::State&) final {
      Operation<T> operation{};
      T value = 1;
      for (size_t i = 1; i <= iterations; i++) {
         value = operation(value, i);
      }
      benchmark::DoNotOptimize(value);
   }
};
