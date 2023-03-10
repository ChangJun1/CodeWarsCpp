/*
Description
Given an array X of positive integers, its elements are to be transformed by running the following operation on them as many times as required:

if X[i] > X[j] then X[i] = X[i] - X[j]

When no more transformations are possible, return its sum ("smallest possible sum").

For instance, the successive transformation of the elements of input X = [6, 9, 21] is detailed below:

X_1 = [6, 9, 12] # -> X_1[2] = X[2] - X[1] = 21 - 9
X_2 = [6, 9, 6]  # -> X_2[2] = X_1[2] - X_1[0] = 12 - 6
X_3 = [6, 3, 6]  # -> X_3[1] = X_2[1] - X_2[0] = 9 - 6
X_4 = [6, 3, 3]  # -> X_4[2] = X_3[2] - X_3[1] = 6 - 3
X_5 = [3, 3, 3]  # -> X_5[1] = X_4[0] - X_4[1] = 6 - 3
The returning output is the sum of the final transformation (here 9).

Example
solution([6, 9, 21]) #-> 9
Solution steps:
[6, 9, 12] #-> X[2] = 21 - 9
[6, 9, 6] #-> X[2] = 12 - 6
[6, 3, 6] #-> X[1] = 9 - 6
[6, 3, 3] #-> X[2] = 6 - 3
[3, 3, 3] #-> X[1] = 6 - 3
*/

#include <gtest/gtest.h>
#include <vector>
#include <numeric>
#include <algorithm>

unsigned long long solution(const std::vector<unsigned long long> &arr) {
    std::vector<unsigned long long> v(arr);
    std::sort(v.begin(), v.end());
    unsigned long long maxDivisor = v.back();
    for (int i = 0; i < v.size(); i++) {
        maxDivisor = std::gcd(v[i], maxDivisor);
    }
    return maxDivisor * v.size();
}

// most popular
/*unsigned long long solution(const std::vector<unsigned long long> &arr) {
    unsigned long long cur_gcd = arr.front();

    for (auto num: arr) {
        cur_gcd = std::__gcd(num, cur_gcd);

    }
    return cur_gcd * arr.size();
}*/

TEST(TEST, MyTEST) {
    ASSERT_EQ(solution({1, 21, 55}), 3);
    ASSERT_EQ(solution({3, 13, 23, 7, 83}), 5);
    ASSERT_EQ(solution({4, 16, 24}), 12);
    ASSERT_EQ(solution({30, 12}), 12);
    ASSERT_EQ(solution({60, 12, 96, 48, 60, 24, 72, 36, 72, 72, 48}), 132);
    ASSERT_EQ(solution({71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71}), 923);
    ASSERT_EQ(solution({11, 22}), 22);
    ASSERT_EQ(solution({9}), 9);
    ASSERT_EQ(solution({1}), 1);
    ASSERT_EQ(solution({9, 9}), 18);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
