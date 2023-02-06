#include <gtest/gtest.h>


bool isPalindrom(const std::string &str) {
    int n = str.size();
    for (int i = 0; i < n / 2; i++) {
        if (tolower(str[i]) != tolower(str[n - 1 - i])) {
            return false;
        }
    }
    return true;
}

TEST(TEST, MyTEST) {
    ASSERT_EQ(isPalindrom("a"), true);
    ASSERT_EQ(isPalindrom("aba"), true);
    ASSERT_EQ(isPalindrom("Abba"), true);
    ASSERT_EQ(isPalindrom("hello"), false);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
