#include <tuple>
#include <vector>

#include "RecursiveRealArithmetic.h"
#include "gtest/gtest.h"

using namespace RecursiveRealArithmetic;
using std::tuple;
using std::vector;

// main() function is usually provided by GTest's gtest_main, but if needed uncomment the following:
/*
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/

// Test for custom ComputableReal using lambda
TEST(ComputableRealTest, CustomLambda) {
    ComputableReal cr([](int accuracy) -> tuple<bool, int, vector<bool>> {
        vector<bool> vec(accuracy, true);
        return std::make_tuple(false, accuracy, vec);
    });
    int acc = 5;
    auto result = cr.compute(acc);
    bool sign;
    int exponent;
    vector<bool> mantissa;
    std::tie(sign, exponent, mantissa) = result;
    EXPECT_FALSE(sign);
    EXPECT_EQ(exponent, acc);
    EXPECT_EQ(mantissa.size(), static_cast<size_t>(acc));
    for (bool b : mantissa) {
        EXPECT_TRUE(b);
    }
}

// Test for Integer with positive value
TEST(IntegerTest, Positive) {
    Integer intVal(5);
    int acc = 10;
    auto result = intVal.compute(acc);
    bool sign;
    int exponent;
    vector<bool> mantissa;
    std::tie(sign, exponent, mantissa) = result;

    EXPECT_FALSE(sign);
    // 8 < 5 < 4 => 2^3 < 5 < 2^2 => exponent = 3
    EXPECT_EQ(exponent, 3);
    // mantissa size should be acc + exponent = 10 + 3 = 13
    EXPECT_EQ(mantissa.size(), static_cast<size_t>(13));
    // Check the binary representation of 5: 5 in binary = 101 (little endian: bit0=1, bit1=0,
    // bit2=1)
    EXPECT_TRUE(mantissa[0]);  // LSB
    EXPECT_FALSE(mantissa[1]);
    EXPECT_TRUE(mantissa[2]);
    for (size_t i = 3; i < mantissa.size(); i++) {
        EXPECT_FALSE(mantissa[i]);
    }
}

// Test for Integer with negative value
TEST(IntegerTest, Negative) {
    Integer intVal(-6);
    int acc = 8;
    auto result = intVal.compute(acc);
    bool sign;
    int exponent;
    vector<bool> mantissa;
    std::tie(sign, exponent, mantissa) = result;

    EXPECT_TRUE(sign);
    EXPECT_EQ(exponent, 3);
    // mantissa size should be acc + exponent = 8 + 2 = 10
    EXPECT_EQ(mantissa.size(), static_cast<size_t>(11));
    // Check the binary representation of 6: 6 in binary = 110
    EXPECT_TRUE(mantissa[0]);
    EXPECT_TRUE(mantissa[1]);
    EXPECT_FALSE(mantissa[2]);
    for (size_t i = 3; i < mantissa.size(); i++) {
        EXPECT_FALSE(mantissa[i]);
    }
}

// Test for Zero
TEST(ZeroTest, Zero) {
    Zero zero;
    int acc = 10;
}
