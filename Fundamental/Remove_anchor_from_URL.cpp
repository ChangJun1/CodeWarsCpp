/*
Complete the function/method so that it returns the url with anything after the anchor (#) removed.

Examples
"www.codewars.com#about" --> "www.codewars.com"
"www.codewars.com?page=1" -->"www.codewars.com?page=1"
 */

#include <gtest/gtest.h>
#include <algorithm>

std::string replaceAll(std::string str) {
    std::string::iterator pos = std::find(str.begin(), str.end(), '#');

    if (pos != str.end()) {
        str.erase(pos, str.end());
    }

    return str;
}

/* // best solution
std::string replaceAll(std::string str) {
    return str.substr(0, str.find('#'));
}*/

TEST(TEST, MyTEST) {
    ASSERT_EQ(replaceAll("www.codewars.com#about"), "www.codewars.com");
    ASSERT_EQ(replaceAll("www.codewar#s.c#om#about"), "www.codewar");
    ASSERT_EQ(replaceAll("www.codewars.com?page=1"), "www.codewars.com?page=1");
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
