#include <gtest/gtest.h>

std::string bmi(double w, double h) {

    //TODO: Implement this function
    if (w < 0 || h <= 0) {
        throw std::logic_error("Method or operation is not implemented");
    }
    double bmi = w / h / h;
    if (bmi <= 18.5) {
        return "Underweight";
    } else if (bmi <= 25.0) {
        return "Normal";
    } else if (bmi <= 30.0) {
        return "Overweight";
    } else {
        return "Obese";
    }
}

TEST(TEST, MyTEST) {
    ASSERT_EQ(bmi(81.585, 2.1), "Underweight");
    ASSERT_EQ(bmi(90.25, 1.9), "Normal");
    ASSERT_EQ(bmi(86.7, 1.7), "Overweight");
    ASSERT_EQ(bmi(200, 1.6), "Obese");
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}