/*
There was a test in your class and you passed it. Congratulations!
But you're an ambitious person. You want to know if you're better than the average student in your class.

You receive an array with your peers' test scores. Now calculate the average and compare your score!

Return True if you're better, else False!

Note: Your points are not included in the array of your class's points. For calculating the average point you may add your point to the given array!
*/

#include <gtest/gtest.h>
#include <vector>
#include <numeric>

bool betterThanAverage(std::vector<int> classPoints, int yourPoints) {
    auto sum = std::accumulate(classPoints.begin(), classPoints.end(), 0);
    sum += yourPoints;
    auto average = sum * 1.0 / (classPoints.size() + 1);
    if (yourPoints > average) {
        return true;
    }
    return false;
}

// most popular (Note?)
//bool betterThanAverage(const std::vector<int> &classPoints, const int yourPoints) {
//    return std::accumulate(classPoints.cbegin(), classPoints.cend(), 0) < classPoints.size() * yourPoints;
//}

TEST(TEST, MyTEST) {
    using vec = std::vector<int>;
    ASSERT_EQ(betterThanAverage(vec{2, 3}, 5), true);
    ASSERT_EQ(betterThanAverage(vec{100, 40, 34, 57, 29, 72, 57, 88}, 75), true);
    ASSERT_EQ(betterThanAverage(vec{12, 23, 34, 45, 56, 67, 78, 89, 90}, 69), true);
    ASSERT_EQ(betterThanAverage(vec{41, 75, 72, 56, 80, 82, 81, 33}, 50), false);
    ASSERT_EQ(betterThanAverage(vec{29, 55, 74, 60, 11, 90, 67, 28}, 21), false);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
