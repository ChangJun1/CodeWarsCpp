/*
The main idea is to count all the occurring characters in a string. If you have a string like aba, then the result should be {'a': 2, 'b': 1}.

What if the string is empty? Then the result should be empty object literal, {}.
 */

#include <gtest/gtest.h>
#include <map>
#include <string>

std::map<char, unsigned> count(const std::string &string) {
    std::map<char, unsigned> m;
    for (auto &s: string) {
        m[s]++;
    }
    return m;
}

TEST(TEST, MyTEST) {
    std::map<char, unsigned> m = {
            {'a', 2},
            {'b', 1}
    };
    std::map<char, unsigned> m1 = {};
    std::map<char, unsigned> m2 = {
            {'a',1},
            {'b',2},
            {'c',3}
    };

    ASSERT_EQ(count("aba"), m);
    ASSERT_EQ(count(""), m1);
    ASSERT_EQ(count("abbccc"), m2);

}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}