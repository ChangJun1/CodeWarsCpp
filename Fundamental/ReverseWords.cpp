/*
Complete the function that accepts a string parameter,
and reverses each word in the string. All spaces in the string should be retained.

Examples
"This is an example!" ==> "sihT si na !elpmaxe"
"double  spaces"      ==> "elbuod  secaps"
*/

#include <gtest/gtest.h>
#include <algorithm>

std::string reverse_words(std::string str) {
    if (str.empty() || str.size() == 1) {
        return str;
    }
    for (int i = 0; i < str.size(); i++) {
        int j = i;
        while (str[j] != ' ' && j < str.size()) {
            j++;
        }
        if (j == str.size()) {
            std::reverse(str.begin() + i, str.begin() + j);
            return str;
        }
        if (i != j) {
            std::reverse(str.begin() + i, str.begin() + j);
            i = j;
        }
    }
    return str;
}

//most popular
/*std::string reverse_words(std::string str) {
    std::string out;
    std::string cword;
    for (char c: str) {
        if (c == ' ') {
            out += cword;
            out += c;
            cword = "";
            continue;
        }
        cword = c + cword;
    }
    out += cword;
    return out;
}*/

TEST(TEST, MyTEST) {
    ASSERT_EQ(reverse_words("The quick brown fox jumps over the lazy dog."),
              "ehT kciuq nworb xof spmuj revo eht yzal .god");
    ASSERT_EQ(reverse_words("apple"), "elppa");
    ASSERT_EQ(reverse_words("a b c d"), "a b c d");
    ASSERT_EQ(reverse_words("double  spaced  words"), "elbuod  decaps  sdrow");
    ASSERT_EQ(reverse_words(" Test with a leading space"), " tseT htiw a gnidael ecaps");
    ASSERT_EQ(reverse_words("Test with a trailing space "), "tseT htiw a gniliart ecaps ");
    ASSERT_EQ(reverse_words(""), "");
    ASSERT_EQ(reverse_words("ab   ba   cd"), "ba   ab   dc");
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
