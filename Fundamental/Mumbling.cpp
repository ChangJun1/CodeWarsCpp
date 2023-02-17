/*
The examples below show you how to write function accum:

Examples:
accum("abcd") -> "A-Bb-Ccc-Dddd"
accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
accum("cwAt") -> "C-Ww-Aaa-Tttt"
The parameter of accum is a string which includes only letters from a..z and A..Z.
*/

#include <gtest/gtest.h>

class Accumul {
public:
    static std::string accum(const std::string &s);
};

std::string Accumul::accum(const std::string &s) {
    std::string res;
    for (int i = 0; i < s.length(); i++) {
        std::string tmp = std::string(i + 1, tolower(s[i]));
        tmp[0] = toupper(tmp[0]);
        res += tmp + "-";
    }
    return res.substr(0, res.length() - 1);
}

// Most popular
//class Accumul
//{
//public:
//    static std::string accum(const std::string &s) {
//        stringstream result;
//        for (int i = 0; i < s.length(); i++)
//            result << "-" << string(1, toupper(s[i])) << string(i, tolower(s[i]));
//        return result.str().substr(1);
//    }
//};

TEST(TEST, MyTEST) {
    EXPECT_EQ(Accumul::accum("ZpglnRxqenU"),
              "Z-Pp-Ggg-Llll-Nnnnn-Rrrrrr-Xxxxxxx-Qqqqqqqq-Eeeeeeeee-Nnnnnnnnnn-Uuuuuuuuuuu");
    EXPECT_EQ(Accumul::accum("NyffsGeyylB"),
              "N-Yy-Fff-Ffff-Sssss-Gggggg-Eeeeeee-Yyyyyyyy-Yyyyyyyyy-Llllllllll-Bbbbbbbbbbb");
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
