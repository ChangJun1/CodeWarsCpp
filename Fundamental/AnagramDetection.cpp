/*
An anagram is the result of rearranging the letters of a word to produce a new word (see wikipedia).

Note: anagrams are case insensitive

Complete the function to return true if the two arguments given are anagrams of each other; return false otherwise.

Examples
"foefet" is an anagram of "toffee"

"Buckethead" is an anagram of "DeathCubeK"

*/


#include <gtest/gtest.h>
#include <string>
#include <unordered_map>
#include <algorithm>

bool isAnagram(std::string test, std::string original) {
    if (test.length() != original.length()) {
        return false;
    }
    std::transform(test.begin(), test.end(), test.begin(), ::tolower);
    std::transform(original.begin(), original.end(), original.begin(), ::tolower);
    std::unordered_map<char, int> m;
    for (int i = 0; i < original.length(); i++) {
        m[test[i]]++;
        m[original[i]]--;
    }
    for (auto v: m) {
        if (v.second != 0) {
            return false;
        }
    }
    return true;
}

// most popular
// sort directly
//bool isAnagram(std::string t, std::string o){
//
//    if(t.size() != o.size())
//        return false;
//
//    std::transform(t.begin(),t.end(),t.begin(),::tolower);
//    std::transform(o.begin(),o.end(),o.begin(),::tolower);
//    std::sort(t.begin(),t.end());
//    std::sort(o.begin(),o.end());
//
//    return t==o;
//
//}

TEST(TEST, MyTEST) {
//    ASSERT_EQ(isAnagram("foefet", "toffee"), true);
    ASSERT_EQ(isAnagram("Buckethead", "DeathCubeK"), true);
    ASSERT_EQ(isAnagram("Twoo", "WooT"), true);
    ASSERT_EQ(isAnagram("dumble", "bumble"), false);
    ASSERT_EQ(isAnagram("around", "round"), false);
    ASSERT_EQ(isAnagram("ound", "round"), false);
    ASSERT_EQ(isAnagram("apple", "pale"), false);
    ASSERT_EQ(isAnagram("apple", "appeal"), false);
    ASSERT_EQ(isAnagram("apple", "appeal"), false);
    ASSERT_EQ(isAnagram("", ""), true);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
