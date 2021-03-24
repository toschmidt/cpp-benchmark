#pragma once

#include <cmath>
#include <functional>
#include <numeric>

namespace benchmark {

   using AggregateFunction = std::function<double(const std::vector<double>&)>;

   static const AggregateFunction Sum = [](const std::vector<double>& values) -> double {
      return std::accumulate(values.begin(), values.end(), 0.0);
   };

   static const AggregateFunction ArithmeticMean = [](const std::vector<double>& values) -> double {
      if (values.empty()) {
         return std::nan("");
      }

      return Sum(values) / values.size();
   };

   static const AggregateFunction GeometricMean = [](const std::vector<double>& values) -> double {
      if (values.empty()) {
         return std::nan("");
      }

      double mul = std::accumulate(values.begin(), values.end(), 1.0,
                                   [](const double& value1, const double& value2) { return value1 * value2; });

      return std::pow(mul, 1.0 / values.size());
   };

   static const AggregateFunction Median = [](const std::vector<double>& vs) -> double {
      std::vector<double> values = vs;
      size_t n = values.size() / 2 + (values.size() % 2 == 0);
      nth_element(values.begin(), values.begin() + n, values.end());

      if (values.size() % 2 == 0) {
         return (values[n - 1] + values[n]) / 2;
      } else {
         return values[n];
      }
   };

   static const AggregateFunction GeothmeticMeandian = [](const std::vector<double>& vs) -> double {
      // see https://xkcd.com/2435/
      std::vector<double> values = vs;
      for (size_t i = 0; i < 42; i++) {
         values = {ArithmeticMean(values), GeometricMean(values), Median(values)};
      }

      return Median(values);
   };
} // namespace benchmark
