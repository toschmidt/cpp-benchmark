#pragma once

#include "AggregateFunction.hpp"
#include "BenchmarkArguments.hpp"
#include <cpp-utility/perf/Counter.hpp>
#include <unordered_set>
#include <utility>
#include <benchmark/benchmark.h>

namespace benchmark {

   class PerfBenchmark : public internal::Benchmark {
     private:
      std::vector<utility::perf::Counter> counters;
      utility::perf::PerfEvent event;
      AggregateFunction aggregate{ArithmeticMean};

     public:
      explicit PerfBenchmark(const std::vector<utility::perf::Counter>& counters)
         : internal::Benchmark(""), counters(counters), event(counters) {}

      PerfBenchmark()
         : PerfBenchmark({utility::perf::INSTRUCTIONS, utility::perf::CYCLES, utility::perf::DURATION_MS,
                          utility::perf::BRANCH_MISSES, utility::perf::L1D_MISSES, utility::perf::L1I_MISSES,
                          utility::perf::LLC_MISSES, utility::perf::DTLB_MISSES, utility::perf::IPC}) {}

      PerfBenchmark* Name(const char* name) {
         SetName(name);
         return this;
      }

      forceinline void Run(State& st) final {
         std::unordered_map<utility::perf::Counter, std::vector<double>> counterValues;
         for (const auto& counter : counters) {
            counterValues.try_emplace(counter, std::vector<double>{});
         }

         this->SetUp(st);

         for (auto _ : st) {
            this->Prepare(st);

            event.start();
            this->Measure(st);
            event.stop();

            this->PostProcess(st);

            st.SetIterationTime(event.get(utility::perf::DURATION_S));
            for (auto& counterValue : counterValues) {
               counterValue.second.push_back(event.get(counterValue.first));
            }
         }

         this->TearDown(st);

         for (const auto& counterValue : counterValues) {
            st.counters[counterValue.first->getName()] = aggregate(counterValue.second);
         }
      }

      forceinline virtual void SetUp(State&) {}
      forceinline virtual void TearDown(State&) {}

      forceinline virtual void Prepare(State&) {}
      forceinline virtual void PostProcess(State&) {}

      forceinline virtual void Measure(State&) {}
   };

} // namespace benchmark
