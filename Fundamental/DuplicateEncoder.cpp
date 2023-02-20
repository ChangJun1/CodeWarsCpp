/*The goal of this exercise is to convert a string to a new string where each character in the new string is
 * "(" if that character appears only once in the original string,
 * or ")" if that character appears more than once in the original string.
 * Ignore capitalization when determining if a character is a duplicate.

Examples
"din"      =>  "((("
"recede"   =>  "()()()"
"Success"  =>  ")())())"
"(( @"     =>  "))(("
*/
#include <gtest/gtest.h>
#include <string>
#include <unordered_map>

std::string duplicate_encoder(const std::string &word) {
    if (word.empty()) {
        return "";
    }
    std::unordered_map<char, int> m;
    std::string res;
    for (int i = 0; i < word.size(); i++) {
        m[word[i]]++;
    }
    for (int i = 0; i < word.size(); i++) {
        if (m[word[i]] > 1) {
            res += ")";
        } else if ('a' <= word[i] && word[i] <= 'z' && m[word[i] - ('a' - 'A')] > 0) {
            res += ")";
        } else if ('A' <= word[i] && word[i] <= 'Z' && m[word[i] + ('a' - 'A')] > 0) {
            res += ")";
        } else {
            res += "(";
        }
    }
    return res;
}

//most popular
//#include <string>
//#include <cctype>
//
//std::string duplicate_encoder(const std::string& word){
//
//    std::map<char, int> table;
//    for(auto x : word) table[std::tolower(x)]++;
//
//    std::string result;
//    for(auto x: word) result += (table[std::tolower(x)]==1)? "(":")";
//
//    return result;
//}

TEST(TEST, MyTEST) {
    ASSERT_EQ(duplicate_encoder("din"), "(((");
    ASSERT_EQ(duplicate_encoder("recede"), "()()()");
    ASSERT_EQ(duplicate_encoder("Success"), ")())())");
    ASSERT_EQ(duplicate_encoder("CodeWarrior"), "()(((())())");
    ASSERT_EQ(duplicate_encoder("Supralapsarian"), ")()))()))))()(");
    ASSERT_EQ(duplicate_encoder("(( @"), "))((");
    ASSERT_EQ(duplicate_encoder(" ( ( )"), ")))))(");
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
