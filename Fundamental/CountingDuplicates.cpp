/*
Count the number of Duplicates
Write a function that will return the count of distinct case-insensitive alphabetic characters and numeric digits
that occur more than once in the input string.

The input string can be assumed to contain only alphabets (both uppercase and lowercase) and numeric digits.

Example
"abcde" -> 0 # no characters repeats more than once
"aabbcde" -> 2 # 'a' and 'b'
"aabBcde" -> 2 # 'a' occurs twice and 'b' twice (`b` and `B`)
"indivisibility" -> 1 # 'i' occurs six times
"Indivisibilities" -> 2 # 'i' occurs seven times and 's' occurs twice
"aA11" -> 2 # 'a' and '1'
"ABBA" -> 2 # 'A' and 'B' each occur twice
*/

#include <gtest/gtest.h>
#include <unordered_map>

size_t duplicateCount(const std::string &in); // helper for tests

size_t duplicateCount(const char *in) {
    if (!in) {
        return 0;
    }
    std::unordered_map<char, int> m;
    const char *p = in;
    for (; *p != '\0'; p++) {
        m[std::tolower(*p)]++;
    }
    size_t res = 0;
    for (auto v: m) {
        if (v.second > 1) {
            res++;
        }
    }
    return res;
}
/* // most popular
std::size_t duplicateCount(const char* in) {
    std::unordered_map<char, unsigned> counts;
    for (const char* c = in; *c != '\0'; ++c) {
        ++counts[tolower(*c)];
    }
    return std::count_if(cbegin(counts), cend(counts), [](const auto& count) {
        return count.second > 1;
    });
}*/

TEST(TEST, MyTEST) {
    ASSERT_EQ(duplicateCount(" "), 0);
    ASSERT_EQ(duplicateCount(""), 0);
    ASSERT_EQ(duplicateCount("aabbcde"), 2);
    ASSERT_EQ(duplicateCount("aabBcde"), 2);
    ASSERT_EQ(duplicateCount("Indivisibility"), 1);
    ASSERT_EQ(duplicateCount("Indivisibilities"), 2);
    ASSERT_EQ(duplicateCount("ABBA"), 2);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
