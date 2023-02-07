/*
Create a function that takes 2 integers in form of a string as an input, and outputs the sum (also as a string):

Example: (Input1, Input2 -->Output)

"4",  "5" --> "9"
"34", "5" --> "39"
"", "" --> "0"
"2", "" --> "2"
"-5", "3" --> "-2"
*/

#include <gtest/gtest.h>
#include <string>

std::string sum_str(const std::string &a, const std::string &b) {
    if (a == "" && b == "") {
        return "0";
    }
    if (a == "") {
        return b;
    }
    if (b == "") {
        return a;
    }
    const char *a1 = a.c_str();
    const char *b1 = b.c_str();
    int res = atoi(a1) + atoi(b1);
    return std::to_string(res);
}

/*
std::string sum_str(const std::string& a, const std::string& b) {
    return std::to_string(std::stoi(a == "" ? "0" : a) + std::stoi(b == "" ? "0" : b));
}

#include <string>
#include <sstream>

using namespace std;

string sum_str(const string& a, const string& b) {
    stringstream sa(a), sb(b);
    int num_a = 0, num_b = 0;
    sa >> num_a;
    sb >> num_b;
    int sum = num_a + num_b;

    return to_string(sum);
}
*/


TEST(TEST, MyTEST) {
    ASSERT_EQ(sum_str("-5", "3"), "-2");
    ASSERT_EQ(sum_str("4", "5"), "9");
    ASSERT_EQ(sum_str("34", "5"), "39");
    ASSERT_EQ(sum_str("", ""), "0");
    ASSERT_EQ(sum_str("42", ""), "42");
    ASSERT_EQ(sum_str("", "42"), "42");
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
