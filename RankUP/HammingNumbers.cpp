/*
A Hamming number is a positive integer of the form 2i3j5k, for some non-negative integers i, j, and k.

Write a function that computes the nth smallest Hamming number.

Specifically:

The first smallest Hamming number is 1 = 203050
The second smallest Hamming number is 2 = 213050
The third smallest Hamming number is 3 = 203150
The fourth smallest Hamming number is 4 = 223050
The fifth smallest Hamming number is 5 = 203051
The 20 smallest Hamming numbers are given in the Example test fixture.

Your code should be able to compute the first 5 000 ( LC: 400, Clojure: 2 000, Haskell: 12 691, NASM, C, D, C++, Go and Rust: 13 282 ) Hamming numbers without timing out.
*/

#include <gtest/gtest.h>
#include <cstdint>
#include <vector>

uint64_t hamber(int n) {
    std::vector<uint64_t> tempArr(n);
    tempArr[0] = 1;
    long a = 2, b = 3, c = 5;
    int aIdx = 0, bIdx = 0, cIdx = 0;
    for (int i = 1; i < n; i++) {
        tempArr[i] = std::min(std::min(a, b), c);
        if (tempArr[i] == a) {
            a = tempArr[++aIdx] * 2;
        }
        if (tempArr[i] == b) {
            b = tempArr[++bIdx] * 3;
        }
        if (tempArr[i] == c) {
            c = tempArr[++cIdx] * 5;
        }
    }
    return tempArr[n - 1];
}

// most popular
/*uint64_t hamber(int n) {
    std::vector<uint64_t> h = {1};
    uint64_t x2 = 2, x3 = 3, x5 = 5;
    size_t i = 0, j = 0, k = 0;

    while (h.size() < n) {
        h.push_back(std::min({x2, x3, x5}));

        if (x2 == h.back())
            x2 = 2 * h[++i];
        if (x3 == h.back())
            x3 = 3 * h[++j];
        if (x5 == h.back())
            x5 = 5 * h[++k];
    }

    return h[n - 1];
}*/

TEST(TEST, MyTEST) {
    ASSERT_EQ(hamber(5), 5);
    ASSERT_EQ(hamber(8), 9);
    ASSERT_EQ(hamber(11), 15);
    ASSERT_EQ(hamber(14), 20);
    ASSERT_EQ(hamber(17), 27);
    ASSERT_EQ(hamber(20), 36);
    ASSERT_EQ(hamber(23), 48);
    ASSERT_EQ(hamber(26), 60);
    ASSERT_EQ(hamber(29), 75);
    ASSERT_EQ(hamber(32), 90);
    ASSERT_EQ(hamber(35), 108);
    ASSERT_EQ(hamber(38), 128);
    ASSERT_EQ(hamber(41), 150);
    ASSERT_EQ(hamber(44), 180);
    ASSERT_EQ(hamber(47), 216);
    ASSERT_EQ(hamber(50), 243);
    ASSERT_EQ(hamber(53), 270);
    ASSERT_EQ(hamber(56), 320);
    ASSERT_EQ(hamber(59), 375);
    ASSERT_EQ(hamber(62), 405);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
