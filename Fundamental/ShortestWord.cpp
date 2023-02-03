/*Simple, given a string of words, return the length of the shortest word(s).

String will never be empty and you do not need to account for different data types.*/

#include <gtest/gtest.h>
#include <string>

using namespace std;

/*int find_short(std::string str) {
    int res = 0;
    int n = str.size();
    int i = 0;
    while (i < n) {
        int tmp = 0;
        while (str[i] != ' ' && i < n) {
            tmp++;
            i++;
        }
        if (tmp < res || res == 0) {
            res = tmp;
        }
        i++;
    }
    return res;
}*/


// best solution

int find_short(const std::string &str) {
    std::istringstream inp(str);
    std::string s;
    int len = -1;
    while (std::getline(inp, s, ' ')) {
        // s.length()的类型为std::string::size_type，即unsigned int，当unsigned int与int进行比较时，统一转换成unsigned int，因此-1是最大的值
        if (s.length() < len) {
            len = s.length();
        }
    }
    return len;
}

TEST(TEST, find_short) {
    ASSERT_EQ(find_short("bitcoin take over the world maybe who knows perhaps"), 3);
    ASSERT_EQ(find_short("turns out random test cases are easier than writing out basic ones"), 3);
    ASSERT_EQ(find_short("lets talk about javascript the best language"), 3);
    ASSERT_EQ(find_short("i want to travel the world writing code one day"), 1);
    ASSERT_EQ(find_short("Let's travel abroad shall we"), 2);
    ASSERT_EQ(find_short("Lets all go on holiday somewhere very cold"), 2);
    ASSERT_EQ(find_short("Let's travel abroad shall we"), 2);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}