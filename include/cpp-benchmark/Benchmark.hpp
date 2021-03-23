#pragma once

#include "BenchmarkArguments.hpp"
#include <benchmark/benchmark.h>

namespace benchmark {

   class Benchmark : public ::benchmark::Fixture {};

} // namespace benchmark

#define MAIN()                                                  \
   extern benchmark::BenchmarkArguments* arguments;             \
   int main(int argc, char** argv) {                            \
      char** new_argv = new char*[argc + arguments->size()];    \
      for (int i = 0; i < argc; i++)                            \
         new_argv[i] = argv[i];                                 \
      for (size_t i = 0; i < arguments->size(); i++)            \
         new_argv[i + argc] = (*arguments)[i].data();           \
      argc += arguments->size();                                \
      ::benchmark::Initialize(&argc, new_argv);                 \
      if (::benchmark::ReportUnrecognizedArguments(argc, argv)) \
         return 1;                                              \
      ::benchmark::RunSpecifiedBenchmarks();                    \
      delete[](new_argv);                                       \
   }                                                            \
   benchmark::BenchmarkArguments* arguments = (new benchmark::BenchmarkArguments())
