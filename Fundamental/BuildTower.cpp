/*
Build Tower
Build a pyramid-shaped tower, as an array/list of strings, given a positive integer number of floors. A tower block is represented with "*" character.

For example, a tower with 3 floors looks like this:

[
"  *  ",
" *** ",
"*****"
]
And a tower with 6 floors looks like this:

[
"     *     ",
"    ***    ",
"   *****   ",
"  *******  ",
" ********* ",
"***********"
]
*/

#include <gtest/gtest.h>
#include <string>
#include <vector>

std::vector<std::string> towerBuilder(unsigned nFloors) {
    std::vector<std::string> res;
    if (nFloors == 0) {
        return res;
    }
    res.resize(nFloors);
    for (int i = nFloors - 1; i >= 0; i--) {
        res[i] = std::string((nFloors - 1 - i), ' ') + std::string((2 * i + 1), '*') +
                 std::string((nFloors - 1 - i), ' ');
    }
    return res;
}

// most popular
/*using namespace std;

vector<string> towerBuilder(unsigned nFloors) {
    vector<string> vect;
    for (unsigned i = 0, k = 1; i < nFloors; i++, k += 2)
        vect.push_back(string(nFloors - i - 1, ' ') + string(k, '*') + string(nFloors - i - 1, ' '));
    return {vect};
}*/

TEST(TEST, MyTEST) {
    {
        std::vector<std::string> expected = {"*"};

        std::vector<std::string> actual = towerBuilder(1);

        ASSERT_EQ(actual, expected);
    }

    {
        std::vector<std::string> expected = {" * ", "***"};

        std::vector<std::string> actual = towerBuilder(2);

        ASSERT_EQ(actual, expected);
    }

    {
        std::vector<std::string> expected = {"  *  ", " *** ", "*****"};

        std::vector<std::string> actual = towerBuilder(3);

        ASSERT_EQ(actual, expected);
    }
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
