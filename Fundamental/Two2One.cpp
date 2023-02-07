/*
Two to One
Take 2 strings s1 and s2 including only letters from a to z. Return a new sorted string, the longest possible, containing distinct letters - each taken only once - coming from s1 or s2.

Examples:
a = "xyaabbbccccdefww"
b = "xxxxyyyyabklmopq"
longest(a, b) -> "abcdefklmopqwxy"

a = "abcdefghijklmnopqrstuvwxyz"
longest(a, a) -> "abcdefghijklmnopqrstuvwxyz"
*/

#include <gtest/gtest.h>
#include <set>

class TwoToOne {
public:
    static std::string longest(const std::string &s1, const std::string &s2);
};

std::string TwoToOne::longest(const std::string &s1, const std::string &s2) {
    std::set<char> s;
    for (auto it = s1.begin(); it != s1.end(); it++) {
        s.insert(*it);
    }
    for (auto it = s2.begin(); it != s2.end(); it++) {
        s.insert(*it);
    }
    std::string res;
    for (auto it = s.begin(); it != s.end(); it++) {
        res += *it;
    }
    return res;
}

//std::string longest(const std::string& s1, const std::string& s2) {
//    std::set<char> chars(s1.begin(), s1.end());
//    for (char c : s2)
//        chars.insert(c);
//    return std::string(chars.begin(), chars.end());
//}

TEST(TEST, MyTEST) {
    EXPECT_EQ(TwoToOne::longest("aretheyhere", "yestheyarehere"), "aehrsty");
    EXPECT_EQ(TwoToOne::longest("loopingisfunbutdangerous", "lessdangerousthancoding"), "abcdefghilnoprstu");
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
