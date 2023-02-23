/*
Implement a function that adds two numbers together and returns their sum in binary. The conversion can be done before, or after the addition.

The binary number returned should be a string.

Examples:(Input1, Input2 --> Output (explanation)))

1, 1 --> "10" (1 + 1 = 2 in decimal or 10 in binary)
5, 9 --> "1110" (5 + 9 = 14 in decimal or 1110 in binary)
*/

#include <gtest/gtest.h>
#include <cstdint>
#include <string>
#include <algorithm>

std::string convert2Binary(uint64_t a) {
    std::string res;
    while (a > 0) {
        auto tmp = std::to_string(a % 2);
        res += tmp;
        a /= 2;
    }
    std::reverse(res.begin(), res.end());
    if (res.empty()) {
        res = "0";
    }
    return res;
}

std::string add_binary(uint64_t a, uint64_t b) {
    auto sum = a + b;
    return convert2Binary(sum);
}

//most popular
//#include <fmt/core.h>
//std::string add_binary(std::uint64_t a, std::uint64_t b) {
//    return fmt::format("{:b}", a + b);
//}

TEST(TEST, MyTEST) {
    ASSERT_EQ(add_binary(1, 1), "10");
    ASSERT_EQ(add_binary(0, 1), "1");
    ASSERT_EQ(add_binary(1, 0), "1");
    ASSERT_EQ(add_binary(2, 2), "100");
    ASSERT_EQ(add_binary(51, 12), "111111");
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
