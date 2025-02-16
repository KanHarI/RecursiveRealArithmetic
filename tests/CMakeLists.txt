enable_testing()

# Add test executable
add_executable(RecursiveRealArithmeticTests test_RecursiveRealArithmetic.cpp)

# Link the RecursiveRealArithmetic library and GoogleTest libraries
target_link_libraries(RecursiveRealArithmeticTests PRIVATE ${PROJECT_NAME} GTest::gtest GTest::gtest_main)

# Register the test with ctest
add_test(NAME RecursiveRealArithmeticTests COMMAND $<TARGET_FILE:RecursiveRealArithmeticTests>) 