#pragma once

#include <string>
#include <vector>

namespace benchmark {

   enum Format
   {
      JSON,
      CSV,
      CONSOLE
   };

   class BenchmarkArguments : public std::vector<std::string> {
     public:
      BenchmarkArguments* listTests(bool value = false);
      BenchmarkArguments* minTime(size_t minTime);
      BenchmarkArguments* repetitions(size_t repetitions = 1);
      BenchmarkArguments* reportAggregatesOnly(bool value = false);
      BenchmarkArguments* displayAggregatesOnly(bool value = false);
      BenchmarkArguments* format(Format format = CONSOLE);
      BenchmarkArguments* out(const std::string& filename);
      BenchmarkArguments* outFormat(Format outFormat = CONSOLE);
      BenchmarkArguments* color(bool value = true);
      BenchmarkArguments* countersTabular(bool value = true);
      BenchmarkArguments* verbosity(const std::string& value);
      BenchmarkArguments* filter(const std::string& regex);
   };

} // namespace benchmark
