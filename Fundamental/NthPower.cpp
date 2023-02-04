#include <gtest/gtest.h>
#include <vector>
#include <cmath>

int index(const std::vector<int> &vector, int n) {
    //your code here
    if (n >= vector.size()) {
        return -1;
    }
    return int(pow(vector[n], n));
}

TEST(TEST, MyTEST) {
    ASSERT_EQ(index({1, 2, 3, 4}, 2), 9);
    ASSERT_EQ(index({5, 1, 3, 3}, 3), 27);
    ASSERT_EQ(index({1, 2}, 3), -1);
    ASSERT_EQ(index({1}, 0), 1);
    ASSERT_EQ(index({1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 9), 1);
    ASSERT_EQ(index({1, 1, 1, 1, 1, 1, 1, 1, 1, 2}, 9), 512);
    ASSERT_EQ(index({29, 82, 45, 10}, 3), 1000);
    ASSERT_EQ(index({6, 31}, 3), -1);
    ASSERT_EQ(index({75, 68, 35, 61, 9, 36, 89, 11, 30}, 10), -1);
}

int main(int argc, char *arg[]) {
    ::testing::InitGoogleTest(&argc, arg);
    return RUN_ALL_TESTS();
}
