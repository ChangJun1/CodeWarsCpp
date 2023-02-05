/*
7kyu  Testing 1-2-3

Your team is writing a fancy new text editor and you've been tasked with implementing the line numbering.

Write a function which takes a list of strings and returns each line prepended by the correct number.

The numbering starts at 1. The format is n: string. Notice the colon and space in between.

Examples: (Input --> Output)

[] --> []
["a", "b", "c"] --> ["1: a", "2: b", "3: c"]
*/

#include <gtest/gtest.h>
#include <string>
#include <vector>

std::vector<std::string> number(const std::vector<std::string> &lines) {
    if (lines.empty()) {
        return {};
    }
    std::vector<std::string> res(lines.size());
    for (int i = 0; i < lines.size(); i++) {
        res[i] = std::to_string(i + 1) + ": " + lines[i];
    }
    return res;
}

TEST(TEST, MyTEST) {
    std::vector<std::string> lines1 = {};
    std::vector<std::string> expected1 = {};
    std::vector<std::string> lines2 = {"a", "b", "c"};;
    std::vector<std::string> expected2 = {"1: a", "2: b", "3: c"};
    ASSERT_EQ(number(lines1), expected1);
    ASSERT_EQ(number(lines2), expected2);
}

int main(int argc, char *argv[]) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
