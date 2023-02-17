/*
Task
In this simple Kata your task is to create a function that turns a string into a Mexican Wave.
You will be passed a string and you must return that string in an array where an uppercase letter is a person standing up.

Rules
1.  The input string will always be lower case but maybe empty.

2.  If the character in the string is whitespace then pass over it as if it was an empty seat

Example
wave("hello") => {"Hello", "hEllo", "heLlo", "helLo", "hellO"}
*/

#include <gtest/gtest.h>
#include <vector>

std::vector<std::string> wave(std::string y) {
    int n = y.size();
    std::vector<std::string> res;
    for (int i = 0; i < n; ++i) {
        if (y[i] >= 'a' && y[i] <= 'z') {
            std::string tmp = y;
            tmp[i] = toupper(y[i]);
            res.push_back(tmp);
        }
    }
    return res;
}
// Most popular
//std::vector<std::string> wave(std::string x){
//    vector <string> op;
//    string temp=x;
//    for(int i=0;i<x.length();i++)
//    {
//        if(x[i]==' ')continue;
//        temp[i] = toupper(temp[i]);
//        op.push_back(temp);
//        temp=x;
//    }
//    return op;
//
//}

TEST(TEST, MyTEST) {

    using v = std::vector<std::string>;
    v s0{};
    v s1{"Hello", "hEllo", "heLlo", "helLo", "hellO"};
    v s2{"Codewars", "cOdewars", "coDewars", "codEwars", "codeWars", "codewArs", "codewaRs", "codewarS"};
    v s3{"Two words", "tWo words", "twO words", "two Words", "two wOrds", "two woRds", "two worDs", "two wordS"};
    v s4{" Gap ", " gAp ", " gaP "};
    ASSERT_EQ(wave(""), s0);
    ASSERT_EQ(wave("hello"), s1);
    ASSERT_EQ(wave("codewars"), s2);
    ASSERT_EQ(wave("two words"), s3);
    ASSERT_EQ(wave(" gap "), s4);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
