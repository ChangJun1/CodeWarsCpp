/*
Given a string, capitalize the letters that occupy even indexes and odd indexes separately, and return as shown below. Index 0 will be considered even.

For example, capitalize("abcdef") = ['AbCdEf', 'aBcDeF']. See test cases for more examples.

The input will be a lowercase string with no spaces.

Good luck!

If you like this Kata, please try:

Indexed capitalization

Even-odd disparity
*/

#include <gtest/gtest.h>
#include <string>
#include <utility>

using namespace std;

std::pair<std::string, std::string> capitalize(const std::string &s) {
    string evenStr(s), oddStr(s);
    for (int i = 0; i < s.size(); i += 2) {
        evenStr[i] = std::toupper(evenStr[i]);
    }
    for (int i = 1; i < s.size(); i += 2) {
        oddStr[i] = std::toupper(oddStr[i]);
    }
    return {evenStr, oddStr};
}

// most popular
/*std::pair<std::string, std::string> capitalize(const std::string &s) {
    string str1, str2;
    for (int i = 0; i < s.length(); i++) {
        if (i % 2 == 0) {
            str1 += toupper(s[i]);
            str2 += s[i];
        } else {
            str1 += s[i];
            str2 += toupper(s[i]);
        }
    }
    return {str1, str2};
}*/


void doTest(const string &s, const pair<string, string> &expected) {
    pair<string, string> actual = capitalize(s);
    ASSERT_EQ(actual, expected);
}

TEST(TEST, MyTEST) {
    doTest("abcdef", {"AbCdEf", "aBcDeF"});
    doTest("codewars", {"CoDeWaRs", "cOdEwArS"});
    doTest("abracadabra", {"AbRaCaDaBrA", "aBrAcAdAbRa"});
    doTest("codewarriors", {"CoDeWaRrIoRs", "cOdEwArRiOrS"});
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
