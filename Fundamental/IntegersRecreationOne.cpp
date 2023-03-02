/*
1, 246, 2, 123, 3, 82, 6, 41 are the divisors of number 246. Squaring these divisors we get: 1, 60516, 4, 15129, 9, 6724, 36, 1681.
The sum of these squares is 84100 which is 290 * 290.

Task
Find all integers between m and n (m and n integers with 1 <= m <= n) such that the sum of their squared divisors is itself a square.

We will return an array of subarrays or of tuples (in C an array of Pair) or a string.
The subarrays (or tuples or Pairs) will have two elements: first the number the squared divisors of which is a square and then the sum of the squared divisors.

Example:
list_squared(1, 250) --> [[1, 1], [42, 2500], [246, 84100]]
list_squared(42, 250) --> [[42, 2500], [246, 84100]]
The form of the examples may change according to the language, see "Sample Tests".

Note
In Fortran - as in any other language - the returned string is not permitted to contain any redundant trailing whitespace: you can use dynamically allocated character strings.
*/


#include <gtest/gtest.h>
#include <utility>
#include <vector>
#include <cmath>
#include <numeric>

std::vector<long long> divisors(long long n) {
    std::vector<long long> res;
    for (long long i = 1; i <= (long long) sqrt(n); i++) {
        if (n % i == 0) {
            res.push_back(i);
            long long tmp = n / i;
            if (tmp > i) {
                res.push_back(tmp);
            }
        }
    }
    return res;
}

long long sumOfDivisorsSquare(const std::vector<long long> &array) {
    return std::accumulate(array.begin(), array.end(), 0, [](long long a, long long val) {
        return a + val * val;
    });
}

bool isSquare(const long long sum) {
    auto x = sqrt(sum);
    if (x == floor(x)) {
        return true;
    }
    return false;
}

class SumSquaredDivisors {
public:
    static std::vector<std::pair<long long, long long>> listSquared(long long m, long long n) {
        std::vector<std::pair<long long, long long >> res;
        if (m > n) {
            return res;
        }
        for (long long i = m; i <= n; ++i) {
            auto div = divisors(i);
            auto sum = sumOfDivisorsSquare(div);
            if (isSquare(sum)) {
                res.push_back(std::make_pair(i, sum));
            }
        }
        return res;
    }
};

// most popular
/*string SumSquaredDivisors::listSquared(long long m, long long n) {
    string ret;
    for (int i = m; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= i; j++)
            if (i % j == 0) sum += j * j;
        double sqrt_sum = sqrt(sum);
        if (floor(sqrt_sum) == sqrt_sum)
            ret += "{" + to_string(i) + ", " + to_string(sum) + "}, ";
    };
    return "{" + ret.substr(0, ret.size() - 2) + "}";
}*/

using Result = std::vector<std::pair<long long, long long>>;

void dotest(long long m, long long n, const Result &expected) {
    ASSERT_EQ(SumSquaredDivisors::listSquared(m, n), expected);
}

TEST(TEST, MyTEST) {
    dotest(1, 250, {{1,   1},
                    {42,  2500},
                    {246, 84100}});
    dotest(42, 250, {{42,  2500},
                     {246, 84100}});
    dotest(250, 500, {{287, 84100}});
    dotest(300, 600, {});
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
