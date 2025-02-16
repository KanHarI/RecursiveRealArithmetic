#include "RecursiveRealArithmetic.h"
#include "gtest/gtest.h"

// Test to verify that compute returns twice the input
TEST(RecursiveRealArithmeticTest, ComputesDouble) {
    double input = 5.0;
    double expected = 10.0;
    double result = RecursiveRealArithmetic::compute(input);
    EXPECT_DOUBLE_EQ(expected, result);
}

// New simple unit test to check zero input
TEST(RecursiveRealArithmeticTest, ComputesZero) {
    double input = 0.0;
    double expected = 0.0;
    double result = RecursiveRealArithmetic::compute(input);
    EXPECT_DOUBLE_EQ(expected, result);
}

// main() function is usually provided by GTest's gtest_main, but if needed uncomment the following:
/*
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/