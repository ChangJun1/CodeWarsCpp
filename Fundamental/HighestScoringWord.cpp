/*
Given a string of words, you need to find the highest scoring word.

Each letter of a word scores points according to its position in the alphabet: a = 1, b = 2, c = 3 etc.

For example, the score of abad is 8 (1 + 2 + 1 + 4).

You need to return the highest scoring word as a string.

If two words score the same, return the word that appears earliest in the original string.

All letters will be lowercase and all inputs will be valid.
*/

#include <gtest/gtest.h>
#include <string>

std::string highestScoringWord(const std::string &str) {
    int score = 0;
    std::string res;
    for (int i = 0; i < str.length(); i++) {
        int tmp = 0;
        int j = i;
        while (str[i] != ' ') {
            tmp += str[i] - 'a' + 1;
            i++;
            if (i == str.length()) {
                break;
            }
        }
        if (tmp > score) {
            score = tmp;
            res = str.substr(j, i - j);
        }
    }
    return res;
}

// most popular
//std::string highestScoringWord(const std::string &str)
//{
//    std::cout << str << std::endl;
//
//    std::istringstream stm(str);
//    std::string token, maxString;
//    long maxValue = 0;
//
//    auto GetValue = [](const std::string& s)
//    {
//        long r = 0;
//        for (auto c : s)
//            r += int(c) - int('a') + 1;
//
//        return r;
//    };
//
//    while (std::getline(stm, token, ' '))
//    {
//        long actValue = GetValue(token);
//        if (actValue > maxValue)
//        {
//            maxValue = actValue;
//            maxString = token;
//        }
//    }
//
//    return maxString;
//}


TEST(TEST, MyTEST) {
    ASSERT_EQ(highestScoringWord("man i need a taxi up to ubud"), "taxi");
    ASSERT_EQ(highestScoringWord("what time are we climbing up the volcano"), "volcano");
    ASSERT_EQ(highestScoringWord("take me to semynak"), "semynak");
    ASSERT_EQ(highestScoringWord("massage yes massage yes massage"), "massage");
    ASSERT_EQ(highestScoringWord("take two bintang and a dance please"), "bintang");
    ASSERT_EQ(highestScoringWord("aa b"), "aa");
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
