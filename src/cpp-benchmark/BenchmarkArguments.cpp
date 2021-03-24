#include "cpp-benchmark/BenchmarkArguments.hpp"

namespace benchmark {

   BenchmarkArguments* BenchmarkArguments::listTests(bool value) {
      push_back(std::string{"--benchmark_list_tests="} + ((value) ? "true" : "false"));
      return this;
   }

   BenchmarkArguments* BenchmarkArguments::minTime(size_t minTime) {
      push_back(std::string{"--benchmark_min_time="} + std::to_string(minTime));
      return this;
   }

   BenchmarkArguments* BenchmarkArguments::repetitions(size_t repetitions) {
      push_back(std::string{"--benchmark_repetitions="} + std::to_string(repetitions));
      return this;
   }

   BenchmarkArguments* BenchmarkArguments::reportAggregatesOnly(bool value) {
      push_back(std::string{"--benchmark_report_aggregates_only="} + ((value) ? "true" : "false"));
      return this;
   }

   BenchmarkArguments* BenchmarkArguments::displayAggregatesOnly(bool value) {
      push_back(std::string{"--benchmark_display_aggregates_only="} + ((value) ? "true" : "false"));
      return this;
   }

   BenchmarkArguments* BenchmarkArguments::format(Format format) {
      push_back(std::string{"--benchmark_format="} +
                ((format == CONSOLE) ? "console" : ((format == JSON) ? "json" : "csv")));
      return this;
   }

   BenchmarkArguments* BenchmarkArguments::out(const std::string& filename) {
      push_back(std::string{"--benchmark_out="} + filename);
      return this;
   }

   BenchmarkArguments* BenchmarkArguments::outFormat(Format outFormat) {
      push_back(std::string{"--benchmark_out_format="} +
                ((outFormat == CONSOLE) ? "console" : ((outFormat == JSON) ? "json" : "csv")));
      return this;
   }

   BenchmarkArguments* BenchmarkArguments::color(bool value) {
      push_back(std::string{"--benchmark_color="} + ((value) ? "true" : "false"));
      return this;
   }

   BenchmarkArguments* BenchmarkArguments::countersTabular(bool value) {
      push_back(std::string{"--benchmark_counters_tabular="} + ((value) ? "true" : "false"));
      return this;
   }

   BenchmarkArguments* BenchmarkArguments::verbosity(const std::string& value) {
      push_back(std::string{"--v="} + value);
      return this;
   }

   BenchmarkArguments* BenchmarkArguments::filter(const std::string& regex) {
      push_back(std::string{"--benchmark_filter="} + regex);
      return this;
   }
}
