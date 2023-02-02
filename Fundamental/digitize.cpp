#include <gtest/gtest.h>

/*
Convert number to reversed array of digits
Given a random non-negative number, you have to return the digits of this number within an array in reverse order.

Example(Input => Output):
35231 => [1,3,2,5,3]
0 => [0]
*/

using namespace std;

std::vector<int> digitize(unsigned long n) {
    if (n == 0) {
        return vector<int>({0});
    }
    vector<int> res;
    while (n > 0) {
        res.push_back(n % 10);
        n /= 10;
    }
    return res;
}

TEST(Test, digitize) {
    EXPECT_EQ(digitize(348597), vector<int>({7, 9, 5, 8, 4, 3}));
    EXPECT_EQ(digitize(35231), vector<int>({1, 3, 2, 5, 3}));
    EXPECT_EQ(digitize(0), vector<int>({0}));
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}