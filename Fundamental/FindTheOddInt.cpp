/*
Given an array of integers, find the one that appears an odd number of times.

There will always be only one integer that appears an odd number of times.

Examples
[7] should return 7, because it occurs 1 time (which is odd).
[0] should return 0, because it occurs 1 time (which is odd).
[1,1,2] should return 2, because it occurs 1 time (which is odd).
[0,1,0,1,0] should return 0, because it occurs 3 times (which is odd).
[1,2,2,3,3,3,4,3,3,3,2,2,1] should return 4, because it appears 1 time (which is odd).
*/

#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>

int findOdd(const std::vector<int> &numbers) {
    std::unordered_map<int, int> m;
    for (auto i: numbers) {
        m[i]++;
    }
    for (auto i: numbers) {
        if (m[i] % 2 == 1) {
            return i;
        }
    }
    return -1;
}

// most popular
// use count() algorithm
//int findOdd(const std::vector<int> &numbers) {
//    for (auto elem: numbers) {
//        if (std::count(numbers.begin(), numbers.end(), elem) % 2 != 0) {
//            return elem;
//        }
//    }
//    return 0;
//}

TEST(TEST, MyTEST) {
    using V = std::vector<int>;
    ASSERT_EQ(findOdd(V{20, 1, -1, 2, -2, 3, 3, 5, 5, 1, 2, 4, 20, 4, -1, -2, 5}), 5);
    ASSERT_EQ(findOdd(V{1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5}), -1);
    ASSERT_EQ(findOdd(V{20, 1, 1, 2, 2, 3, 3, 5, 5, 4, 20, 4, 5}), 5);
    ASSERT_EQ(findOdd(V{10}), 10);
    ASSERT_EQ(findOdd(V{1, 1, 1, 1, 1, 1, 10, 1, 1, 1, 1}), 10);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


