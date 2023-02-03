/*You might know some pretty large perfect squares. But what about the NEXT one?

Complete the findNextSquare method that finds the next integral perfect square after the one passed as a parameter. Recall that an integral perfect square is an integer n such that sqrt(n) is also an integer.

If the parameter is itself not a perfect square then -1 should be returned. You may assume the parameter is non-negative.

Examples:(Input --> Output)

121 --> 144
625 --> 676
114 --> -1 since 114 is not a perfect square*/

#include <gtest/gtest.h>
#include <cmath>

long int findNextSquare(long int sq) {
    // Return the next square if sq if a perfect square, -1 otherwise
    double x = sqrt(sq);
    if (x - floor(x) > 1e-5) {
        return -1;
    }
    return (long int) pow(x + 1, 2);
}


TEST(TEST, findNextSquare) {
    ASSERT_EQ(findNextSquare(121), 144);
    ASSERT_EQ(findNextSquare(625), 676);
    ASSERT_EQ(findNextSquare(319225), 320356);
    ASSERT_EQ(findNextSquare(15241383936), 15241630849);
    ASSERT_EQ(findNextSquare(155), -1);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
