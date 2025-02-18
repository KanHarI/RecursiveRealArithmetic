#ifndef RECURSIVE_REAL_ARITHMETIC_H
#define RECURSIVE_REAL_ARITHMETIC_H

#include <functional>
#include <tuple>
#include <vector>

namespace RecursiveRealArithmetic {

// A computable real is a function that receives target accuracy
// (real is between VAL - 2^(-accuracy) and VAL + 2^(-accuracy))
// and returns a tuple with:
// - sign
// - exponent
// - mantissa
// This is NOT a standard floating point representation, it represents the real number:
// (-1)^sign * 2^exponent * <mantissa>
// Where the 0th bit of mantissa is the 1/2 place, the 1st bit is the 1/4 place, etc.
typedef std::function<std::tuple<bool, int, std::vector<bool>>(int)> t_callback;

class ComputableReal {
   private:
    t_callback callback;

   public:
    // Fixed constructor and added compute declaration
    ComputableReal(t_callback callback);

    // Evaluates the computable real at the given accuracy
    std::tuple<bool, int, std::vector<bool>> compute(int accuracy) const;
};

class Integer : public ComputableReal {
   public:
    Integer(int value);
};

class Zero : public ComputableReal {
   public:
    Zero();
};

class Sum : public ComputableReal {
   public:
    Sum(ComputableReal a, ComputableReal b);
};

}  // namespace RecursiveRealArithmetic

#endif  // RECURSIVE_REAL_ARITHMETIC_H