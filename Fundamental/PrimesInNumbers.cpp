/*
Given a positive number n > 1 find the prime factor decomposition of n. The result will be a string with the following form :

"(p1**n1)(p2**n2)...(pk**nk)"
with the p(i) in increasing order and n(i) empty if n(i) is 1.

Example: n = 86240 should return "(2**5)(5)(7**2)(11)"
*/
#include <gtest/gtest.h>
#include <map>

class PrimeDecomp {
public:
    static std::string factors(int lst);
};

std::string PrimeDecomp::factors(int lst) {
    if (lst <= 1) {
        return "invalid lst argument";
    }
    std::map<int, int> m;
    for (int i = 2; i <= lst; i++) {
        if (lst % i == 0) {
            m[i]++;
            lst /= i;
            i = 1;
            continue;
        }
    }
    if (m.empty()) {
        return std::to_string(lst);
    }
    std::string res;
    for (auto &val: m) {
        if (val.second > 1) {
            res = res + "(" + std::to_string(val.first) + "**" + std::to_string(val.second) + ")";
        } else {
            res = res + "(" + std::to_string(val.first) + ")";
        }
    }
    return res;
}

// most popular
/*
#include <sstream>
std::string PrimeDecomp::factors(int n) {
    std::ostringstream res;
    for (int i = 2; n > 1; i++) {
        int k = 0;
        while (n % i == 0) {
            n /= i;
            k++;
        }
        if (k == 1)
            res << '(' << i << ')';
        else if (k > 1)
            res << '(' << i << "**" << k << ')';
    }
    return res.str();
}
*/

TEST(TEST, MyTEST) {
    ASSERT_EQ(PrimeDecomp::factors(7775460), "(2**2)(3**3)(5)(7)(11**2)(17)");
    ASSERT_EQ(PrimeDecomp::factors(7919), "(7919)");
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
