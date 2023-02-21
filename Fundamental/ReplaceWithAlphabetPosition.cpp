/*
In this kata you are required to, given a string, replace every letter with its position in the alphabet.
If anything in the text isn't a letter, ignore it and don't return it.

"a" = 1, "b" = 2, etc.

Example

alphabet_position("The sunset sets at twelve o' clock.")
Should return "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11" ( as a string )
*/


#include <gtest/gtest.h>
#include <string>
#include <algorithm>

std::string alphabet_position(const std::string &text) {
    if (text.empty()) {
        return "";
    }

    std::string res;
    for (auto c: text) {
        if (isalpha(c)) {
            int tmp = 0;
            if (c >= 'a' && c <= 'z') {
                tmp += int(c) - int('a') + 1;
            } else {
                tmp += int(c) - int('A') + 1;
            }
            res += std::to_string(tmp) + " ";
        }
    }
    return res.substr(0, res.length() - 1);
}

// most popular
// ‘A'为65，'a'为97，
// 二进制来看，小写和大写的区别就在第五位
// 所有的小写的第五位（从0开始）是1，所有的大写字母的第五位都是0
//std::string alphabet_position(const std::string &s) {
//    std::stringstream ss;
//    for (auto &x : s) if (std::isalpha(x)) ss << (x | 32) - 96 << ' ';
//    std::string r = ss.str();
//    if (r.size()) r.pop_back();
//    return r;
//}

TEST(TEST, MyTEST) {
    ASSERT_EQ(alphabet_position("The sunset sets at twelve o' clock."),
              "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11");
    ASSERT_EQ(alphabet_position("The narwhal bacons at midnight."),
              "20 8 5 14 1 18 23 8 1 12 2 1 3 15 14 19 1 20 13 9 4 14 9 7 8 20");
    ASSERT_EQ(alphabet_position("0123456789"), "");
    ASSERT_EQ(alphabet_position(",./<>?-_=+ "), "");
    ASSERT_EQ(alphabet_position(""), "");

}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
