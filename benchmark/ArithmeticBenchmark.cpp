#include "ArithmeticBenchmark.hpp"
#include <cpp-benchmark/Benchmark.hpp>

using AddIntBenchmark = ArithmeticBenchmark<int, add>;
REGISTER_BENCHMARK(AddIntBenchmark)->ArgsProduct({{1000000000ull}})->Iterations(5);

using SubtractIntBenchmark = ArithmeticBenchmark<int, subtract>;
REGISTER_BENCHMARK(SubtractIntBenchmark)->ArgsProduct({{1000000000ull}})->Iterations(5);

using MulIntBenchmark = ArithmeticBenchmark<int, mul>;
REGISTER_BENCHMARK(MulIntBenchmark)->ArgsProduct({{1000000000ull}})->Iterations(5);

using DivisionIntBenchmark = ArithmeticBenchmark<int, division>;
REGISTER_BENCHMARK(DivisionIntBenchmark)->ArgsProduct({{1000000000ull}})->Iterations(5);

using ModIntBenchmark = ArithmeticBenchmark<int, mod>;
REGISTER_BENCHMARK(ModIntBenchmark)->ArgsProduct({{1000000000ull}})->Iterations(5);

using ShiftIntBenchmark = ArithmeticBenchmark<int, add>;
REGISTER_BENCHMARK(ShiftIntBenchmark)->ArgsProduct({{1000000000ull}})->Iterations(5);

using AddDoubleBenchmark = ArithmeticBenchmark<double, add>;
REGISTER_BENCHMARK(AddDoubleBenchmark)->ArgsProduct({{1000000000ull}})->Iterations(5);

using SubtractDoubleBenchmark = ArithmeticBenchmark<double, subtract>;
REGISTER_BENCHMARK(SubtractDoubleBenchmark)->ArgsProduct({{1000000000ull}})->Iterations(5);

using MulDoubleBenchmark = ArithmeticBenchmark<double, mul>;
REGISTER_BENCHMARK(MulDoubleBenchmark)->ArgsProduct({{1000000000ull}})->Iterations(5);

using DivisionDoubleBenchmark = ArithmeticBenchmark<double, division>;
REGISTER_BENCHMARK(DivisionDoubleBenchmark)->ArgsProduct({{1000000000ull}})->Iterations(5);

MAIN()->countersTabular()->format(benchmark::CONSOLE);
