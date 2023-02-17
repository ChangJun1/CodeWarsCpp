/*
Task:
Your task is to write a function which returns the sum of following series upto nth term(parameter).

Series: 1 + 1/4 + 1/7 + 1/10 + 1/13 + 1/16 +...
Rules:
You need to round the answer to 2 decimal places and return it as String.

If the given value is 0 then it should return 0.00

You will only be given Natural Numbers as arguments.

Examples:(Input --> Output)
1 --> 1 --> "1.00"
2 --> 1 + 1/4 --> "1.25"
5 --> 1 + 1/4 + 1/7 + 1/10 + 1/13 --> "1.57"
*/

#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>

std::string seriesSum(int n) {
    double res = 0.0;
    for (int i = 0; i < n; i++) {
        res += 1.0 / (3 * i + 1);
    }
    std::stringstream ss;
    ss << std::setiosflags(std::ios::fixed) << std::setprecision(2) << res;
    return ss.str();
}

//most popular
//string seriesSum(int n)
//{
//    double ret = 0.0;
//    double base = 1.0;
//    while (n--) {
//        ret += 1 / base;
//        base += 3;
//    }
//    stringstream retss;
//    retss << setprecision(2) << fixed << ret;
//    return retss.str();
//}

TEST(TEST, MyTEST) {
    std::string expected = "0.00";
    std::string actual = seriesSum(0);
    ASSERT_EQ(actual, expected);

    expected = "1.25";
    actual = seriesSum(2);
    ASSERT_EQ(actual, expected);

    expected = "1.57";
    actual = seriesSum(5);
    ASSERT_EQ(actual, expected);

    expected = "1.77";
    actual = seriesSum(9);
    ASSERT_EQ(actual, expected);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
