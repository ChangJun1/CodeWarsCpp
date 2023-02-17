/*
You are going to be given an array of integers. Your job is to take that array and find an index N where the sum of the integers to the left of N is equal to the sum of the integers to the right of N. If there is no index that would make this happen, return -1.

For example:

Let's say you are given the array {1,2,3,4,3,2,1}:
Your function will return the index 3, because at the 3rd position of the array, the sum of left side of the index ({1,2,3}) and the sum of the right side of the index ({3,2,1}) both equal 6.

Let's look at another one.
You are given the array {1,100,50,-51,1,1}:
Your function will return the index 1, because at the 1st position of the array, the sum of left side of the index ({1}) and the sum of the right side of the index ({50,-51,1,1}) both equal 1.

Last one:
You are given the array {20,10,-80,10,10,15,35}
At index 0 the left side is {}
The right side is {10,-80,10,10,15,35}
They both are equal to 0 when added. (Empty arrays are equal to 0 in this problem)
Index 0 is the place where the left side and right side are equal.

Note: Please remember that in most programming/scripting languages the index of an array starts at 0.

Input:
An integer array of length 0 < arr < 1000. The numbers in the array can be any integer positive or negative.

Output:
The lowest index N where the side to the left of N is equal to the side to the right of N. If you do not find an index that fits these rules, then you will return -1.

Note:
If you are given an array with multiple answers, return the lowest correct index.
*/

#include <gtest/gtest.h>
#include <vector>

using namespace std;

int find_even_index(const vector<int> numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        int lsum = 0;
        for (int j = 0; j < i; j++) {
            lsum += numbers[j];
        }
        int rsum = 0;
        for (int j = i + 1; j < numbers.size(); j++) {
            rsum += numbers[j];
        }
        if (lsum == rsum) {
            return i;
        }
    }
    return -1;
}
// most popular
//int find_even_index (const vector <int> numbers) {
//    for (int index = 0; index < numbers.size(); index++)
//    {
//        int left_sum = std::accumulate(numbers.begin(), numbers.begin() + index, 0);
//        int right_sum = std::accumulate(numbers.begin() + index + 1, numbers.end(), 0);
//        if (left_sum == right_sum)
//            return index;
//    }
//    return -1;
//}

TEST(TEST, MyTEST) {
    {
        vector<int> numbers{1, 2, 3, 4, 3, 2, 1};
        int expected = 3;
        ASSERT_EQ(find_even_index(numbers), expected);
    }

    {
        vector<int> numbers{1, 100, 50, -51, 1, 1};
        int expected = 1;
        ASSERT_EQ(find_even_index(numbers), expected);
    }

    {
        vector<int> numbers{1, 2, 3, 4, 5, 6};
        int expected = -1;
        ASSERT_EQ(find_even_index(numbers), expected);
    }

    {
        vector<int> numbers{20, 10, 30, 10, 10, 15, 35};
        int expected = 3;
        ASSERT_EQ(find_even_index(numbers), expected);
    }

    {
        vector<int> numbers{20, 10, -80, 10, 10, 15, 35};
        int expected = 0;
        ASSERT_EQ(find_even_index(numbers), expected);
    }

    {
        vector<int> numbers{10, -80, 10, 10, 15, 35, 20};
        int expected = 6;
        ASSERT_EQ(find_even_index(numbers), expected);
    }

    {
        vector<int> numbers{0, 0, 0, 0, 0};
        int expected = 0;
        ASSERT_EQ(find_even_index(numbers), expected);
    }

    {
        vector<int> numbers{-1, -2, -3, -4, -3, -2, -1};
        int expected = 3;
        ASSERT_EQ(find_even_index(numbers), expected);
    }
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
