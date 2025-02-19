#include "RecursiveRealArithmetic.h"

#include <functional>
#include <tuple>
#include <vector>

#include "utils.h"

namespace RecursiveRealArithmetic {

ComputableReal::ComputableReal(t_callback callback) : callback(callback) {}

std::tuple<bool, int, std::vector<bool>> ComputableReal::compute(int accuracy) const {
    return callback(accuracy);
}

Zero::Zero()
    : ComputableReal([](int accuracy) -> std::tuple<bool, int, std::vector<bool>> {
          return std::make_tuple(false, 0, std::vector<bool>(0));
      }) {}

Integer::Integer(int value)
    : ComputableReal([value](int accuracy) -> std::tuple<bool, int, std::vector<bool>> {
          unsigned absValue = std::abs(value);
          if (absValue == 0) {
              const Zero zero;
              return zero.compute(accuracy);
          }
          int exponent = ceil_log2(absValue);
          unsigned mantissa_bits = std::max(1, accuracy + exponent);
          std::vector<bool> mantissa(mantissa_bits, false);
          for (int i = 0; i < std::min(exponent, static_cast<int>(mantissa_bits)); i++) {
              mantissa[i] = absValue & (1 << (exponent - i - 1));
          }
          return std::make_tuple(value < 0, exponent, mantissa);
      }) {}
}  // namespace RecursiveRealArithmetic