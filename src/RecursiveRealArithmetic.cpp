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

// Sum::Sum(ComputableReal a, ComputableReal b)
//     : ComputableReal([a, b](int accuracy) -> std::tuple<bool, int, std::vector<bool>> {
//           // TODO: Implement this
//           auto n1 = a.compute(accuracy + 1);
//           auto n2 = b.compute(accuracy + 1);
//           auto exp1 = std::get<1>(n1);
//           auto exp2 = std::get<1>(n2);
//           auto sign1 = std::get<0>(n1);
//           auto sign2 = std::get<0>(n2);
//           auto mantissa1 = std::get<2>(n1);
//           auto mantissa2 = std::get<2>(n2);
//           if (mantissa1.size() < mantissa2.size()) {
//               mantissa1.resize(mantissa2.size(), false);
//           } else if (mantissa2.size() < mantissa1.size()) {
//               mantissa2.resize(mantissa1.size(), false);
//           }
//           // Add a "false" to the front of the mantissa (space for the carry)
//           mantissa1.insert(mantissa1.begin(), false);
//           mantissa2.insert(mantissa2.begin(), false);
//           if (exp1 == exp2) {
//               if (sign1 == sign2) {
//                   while (
//                       std::any_of(mantissa1.begin(), mantissa1.end(), [](bool b) { return b; }))
//                       { std::vector<bool> and_mantissas(mantissa1.size()); std::vector<bool>
//                       xor_mantissas(mantissa1.size()); std::transform(mantissa1.begin(),
//                       mantissa1.end(), mantissa2.begin(),
//                                      and_mantissas.begin(), std::bit_and<bool>());
//                       std::transform(mantissa1.begin(), mantissa1.end(), mantissa2.begin(),
//                                      xor_mantissas.begin(), std::bit_xor<bool>());
//                       mantissa1 = xor_mantissas;
//                       mantissa2 = and_mantissas;
//                       // Roll mantissa2 right by 1
//                       mantissa2.push_back(false);
//                       mantissa2.erase(mantissa2.begin());
//                   }
//               } else {
//                   // Subtraction
//               }
//           }
//       }) {}

}  // namespace RecursiveRealArithmetic