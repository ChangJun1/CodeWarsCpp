/*

An isogram is a word that has no repeating letters, consecutive or non-consecutive. Implement a function that determines whether a string that contains only letters is an isogram. Assume the empty string is an isogram. Ignore letter case.

Example: (Input --> Output)

"Dermatoglyphics" --> true "aba" --> false "moOse" --> false (ignore letter case)

isIsogram "Dermatoglyphics" = true
isIsogram "moose" = false
isIsogram "aba" = false

*/

#include <gtest/gtest.h>
#include <unordered_map>

bool is_isogram(std::string str) {
    std::unordered_map<char, int> m;
    for (auto c: str) {
        if (m[c] > 0) {
            return false;
        }
        m[c]++;
        if (c >= 'a' && c <= 'z') {
            m[c - ('a' - 'A')]++;
        } else if (c >= 'A' && c <= 'A') {
            m[c + ('a' - 'A')]++;
        }
    }
    return true;
}

TEST(TEST, MyTEST) {
    ASSERT_EQ(is_isogram("Dermatoglyphics"), true);
    ASSERT_EQ(is_isogram("moose"), false);
    ASSERT_EQ(is_isogram("isIsogram"), false);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
