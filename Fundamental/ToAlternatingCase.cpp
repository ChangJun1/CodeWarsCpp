/*altERnaTIng cAsE <=> ALTerNAtiNG CaSe
Define String.prototype.toAlternatingCase (or a similar function/method such as to_alternating_case/toAlternatingCase/ToAlternatingCase in your selected language; see the initial solution for details) such that each lowercase letter becomes uppercase and each uppercase letter becomes lowercase. For example:

"hello world".toAlternatingCase() === "HELLO WORLD"
"HELLO WORLD".toAlternatingCase() === "hello world"
"hello WORLD".toAlternatingCase() === "HELLO world"
"HeLLo WoRLD".toAlternatingCase() === "hEllO wOrld"
"12345".toAlternatingCase()       === "12345"                   // Non-alphabetical characters are unaffected
"1a2b3c4d5e".toAlternatingCase()  === "1A2B3C4D5E"
"String.prototype.toAlternatingCase".toAlternatingCase() === "sTRING.PROTOTYPE.TOaLTERNATINGcASE"*/

#include <gtest/gtest.h>

std::string to_alternating_case(const std::string &str) {
    std::string res(str.size(), ' ');
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            res[i] = str[i] - ('a' - 'A');
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            res[i] = str[i] + ('a' - 'A');
        } else {
            res[i] = str[i];
        }
    }
    return res;
}
// best solution

#include <iostream>
/*

std::string to_alternating_case(std::string str)
{
    for(auto& ch : str)
    {
        ch = std::islower(ch) ? std::toupper(ch) : std::tolower(ch);
    }
    return str;
}
*/


TEST(TEST, MyTEST) {
    ASSERT_EQ(to_alternating_case("hello world"), "HELLO WORLD");
    ASSERT_EQ(to_alternating_case("HELLO WORLD"), "hello world");
    ASSERT_EQ(to_alternating_case("hello WORLD"), "HELLO world");
    ASSERT_EQ(to_alternating_case("HeLLo WoRLD"), "hEllO wOrld");
    ASSERT_EQ(to_alternating_case("12345"), "12345");
    ASSERT_EQ(to_alternating_case("1a2b3c4d5e"), "1A2B3C4D5E");
    ASSERT_EQ(to_alternating_case("String.prototype.toAlternatingCase"), "sTRING.PROTOTYPE.TOaLTERNATINGcASE");
    ASSERT_EQ(to_alternating_case(to_alternating_case("Hello World")), "Hello World");
    ASSERT_EQ(to_alternating_case("altERnaTIng cAsE"), "ALTerNAtiNG CaSe");
    ASSERT_EQ(to_alternating_case("ALTerNAtiNG CaSe"), "altERnaTIng cAsE");
    ASSERT_EQ(to_alternating_case("altERnaTIng cAsE <=> ALTerNAtiNG CaSe"), "ALTerNAtiNG CaSe <=> altERnaTIng cAsE");
    ASSERT_EQ(to_alternating_case("ALTerNAtiNG CaSe <=> altERnaTIng cAsE"), "altERnaTIng cAsE <=> ALTerNAtiNG CaSe");
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
