/*
You will be given an array of numbers. You have to sort the odd numbers in ascending order while leaving the even numbers at their original positions.

Examples
[7, 1]  =>  [1, 7]
[5, 8, 6, 3, 4]  =>  [3, 8, 6, 5, 4]
[9, 8, 7, 6, 5, 4, 3, 2, 1, 0]  =>  [1, 8, 3, 6, 5, 4, 7, 2, 9, 0]
*/

#include <gtest/gtest.h>
#include <algorithm>

class Kata {
public:
    std::vector<int> sortArray(std::vector<int> array) {
        if (array.empty()) {
            return {};
        }
        std::vector<int> v;
        for (int i = 0; i < array.size(); ++i) {
            if (array[i] & 1) {
                v.push_back(array[i]);
            }
        }
        std::sort(v.begin(), v.end());

        for (int i = 0, j = 0; i < array.size() && j < v.size(); ++i) {
            if (array[i] & 1) {
                if (array[i] != v[j]) {
                    array[i] = v[j];
                }
                j++;
            }
        }
        return array;
    }
};


/*class Kata {
public:
    std::vector<int> sortArray(std::vector<int> array) {
        std::vector<int> odds;
        std::copy_if(array.begin(), array.end(), std::back_inserter(odds), [](int x) { return x % 2; });
        std::sort(odds.begin(), odds.end());
        for (int i = 0, j = 0; i < array.size(); i++) if (array[i] % 2) array[i] = odds[j++];
        return array;
    }
};*/

TEST(TEST, MyTEST) {
    {
        std::vector<int> expected = {1, 3, 2, 8, 5, 4};

        Kata kata;
        std::vector<int> actual = kata.sortArray({5, 3, 2, 8, 1, 4});

        ASSERT_EQ(actual, expected);
    }

    {
        std::vector<int> expected = {1, 3, 5, 8, 0};

        Kata kata;
        std::vector<int> actual = kata.sortArray({5, 3, 1, 8, 0});

        ASSERT_EQ(actual, expected);
    }

    {
        std::vector<int> expected = {};

        Kata kata;
        std::vector<int> actual = kata.sortArray({});

        ASSERT_EQ(actual, expected);
    }

}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
