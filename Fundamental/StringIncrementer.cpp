/*
Your job is to write a function which increments a string, to create a new string.

If the string already ends with a number, the number should be incremented by 1.
If the string does not end with a number. the number 1 should be appended to the new string.
Examples:

foo -> foo1

foobar23 -> foobar24

foo0042 -> foo0043

foo9 -> foo10

foo099 -> foo100

Attention: If the number has leading zeros the amount of digits should be considered.
*/

#include <gtest/gtest.h>
#include <string>

std::string incrementString(const std::string &str) {
    if (str.empty()) {
        return "1";
    }
    int n = str.length();
    int i = n - 1;
    // 末尾不是数字
    if (!std::isdigit(str[i])) {
        return str + "1";
    }
    //末尾是数字，提取出来
    while (std::isdigit(str[i]) && i >= 0) {
        i--;
    }
    int x = std::stoi(str.substr(i + 1, n - i - 1)) + 1;
    int j = 0, tmp = x;
    while (tmp > 0) {
        j++;
        tmp /= 10;
    }
    // 位数不够补"0"
    if (j < n - i - 1) {
        return str.substr(0, i + 1) + std::string(n - i - j - 1, '0') + std::to_string(x);
    }
    return str.substr(0, i + 1) + std::to_string(x);
}

// most popular
/*string incrementString(const string &str) {

    string s = str;

    if (s.empty() || !isdigit(s.back()))
        return s + "1";

    for (int i = s.size() - 1; i >= 0; i--) {
        char &c = s[i];
        if (isdigit(c)) {
            if (c < '9') {
                c++;
                return s;
            } else {
                c = '0';
                continue;
            }
        } else {
            s.insert(i + 1, "1");
            return s;
        }
    }

    return s;
}*/

void do_test(const std::string &str, const std::string expected) {
    ASSERT_EQ(incrementString(str), expected);
}

TEST(TEST, MyTEST) {
    do_test("foobar000", "foobar001");
    do_test("foo", "foo1");
    do_test("foobar001", "foobar002");
    do_test("foobar99", "foobar100");
    do_test("foobar099", "foobar100");
    do_test("", "1");
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
