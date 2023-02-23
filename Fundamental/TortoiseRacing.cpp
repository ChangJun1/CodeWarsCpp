/*
Two tortoises named A and B must run a race. A starts with an average speed of 720 feet per hour. Young B knows she runs faster than A, and furthermore has not finished her cabbage.

When she starts, at last, she can see that A has a 70 feet lead but B's speed is 850 feet per hour. How long will it take B to catch A?

More generally: given two speeds v1 (A's speed, integer > 0) and v2 (B's speed, integer > 0) and a lead g (integer > 0) how long will it take B to catch A?

The result will be an array [hour, min, sec] which is the time needed in hours, minutes and seconds (round down to the nearest second) or a string in some languages.

If v1 >= v2 then return nil, nothing, null, None or {-1, -1, -1} for C++, C, Go, Nim, Pascal, COBOL, Erlang, [-1, -1, -1] for Perl,[] for Kotlin or "-1 -1 -1".

Examples:
(form of the result depends on the language)

race(720, 850, 70) => [0, 32, 18] or "0 32 18"
race(80, 91, 37)   => [3, 21, 49] or "3 21 49"
Note:
See other examples in "Your test cases".

In Fortran - as in any other language - the returned string is not permitted to contain any redundant trailing whitespace: you can use dynamically allocated character strings.

** Hints for people who don't know how to convert to hours, minutes, seconds:

Tortoises don't care about fractions of seconds
Think of calculation by hand using only integers (in your code use or simulate integer division)
or Google: "convert decimal time to hours minutes seconds"
*/


#include <gtest/gtest.h>

class Tortoise {
public:
    static std::vector<int> race(int v1, int v2, int g);
};

std::vector<int> Tortoise::race(int v1, int v2, int g) {
    if (v1 <= 0 || v2 <= 0 || g <= 0) {
        return {-1, -1, -1};
    }
    if (v2 <= v1) {
        return {-1, -1, -1};
    }
    std::vector<int> res;
    int speed = v2 - v1;
    int tmp = g;
    for (int i = 0; i < 3; i++) {
        res.push_back(tmp / speed);
        tmp = (tmp % speed) * 60;
    }
    return res;
}

//most popular
/*class Tortoise {
public:
    static std::vector<int> race(int v1, int v2, int g) {
        if (v1 >= v2) return {-1, -1, -1};
        int t = g * 3600 / (v2 - v1);
        return {t / 3600, t / 60 % 60, t % 60};
    }
};*/


void dotest(int v1, int v2, int g, std::vector<int> expected) {
    ASSERT_EQ(Tortoise::race(v1, v2, g), expected);
}

TEST(TEST, MyTEST) {
    dotest(720, 850, 70, {0, 32, 18});
    dotest(820, 81, 550, {-1, -1, -1});
    dotest(80, 91, 37, {3, 21, 49});
}


int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
