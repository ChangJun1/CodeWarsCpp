/*
Your task is to make function, which returns the sum of a sequence of integers.

The sequence is defined by 3 non-negative values: begin, end, step (inclusive).

If begin value is greater than the end, function should returns 0

Examples

2,2,2 --> 2
2,6,2 --> 12 (2 + 4 + 6)
1,5,1 --> 15 (1 + 2 + 3 + 4 + 5)
1,5,3  --> 5 (1 + 4)
*/

#include <gtest/gtest.h>

int sequenceSum(int start, int end, int step) {
    if (start > end) {
        return 0;
    }
    int res = 0;
    while (start <= end) {
        res += start;
        start += step;
    }
    return res;
}

TEST(TEST, MyTEST) {
    ASSERT_EQ(sequenceSum(2, 6, 2), 12);
    ASSERT_EQ(sequenceSum(1, 5, 1), 15);
    ASSERT_EQ(sequenceSum(1, 5, 3), 5);
    ASSERT_EQ(sequenceSum(0, 15, 3), 45);
    ASSERT_EQ(sequenceSum(16, 15, 3), 0);
    ASSERT_EQ(sequenceSum(2, 24, 22), 26);
    ASSERT_EQ(sequenceSum(2, 2, 2), 2);
    ASSERT_EQ(sequenceSum(2, 2, 1), 2);
    ASSERT_EQ(sequenceSum(1, 15, 3), 35);
    ASSERT_EQ(sequenceSum(15, 1, 3), 0);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
