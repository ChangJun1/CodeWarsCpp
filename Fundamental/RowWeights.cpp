#include <gtest/gtest.h>
#include <utility>
#include <vector>

using namespace std;

pair<int, int> rowWeights(const vector<int> &weights) {
    if (weights.empty()) {
        return make_pair(0, 0);
    }

    pair<int, int> res{0, 0};
    int i = 0, j = 1;
    for (; i < weights.size() && j < weights.size(); i += 2, j += 2) {
        res.first += weights[i];
        res.second += weights[j];
    }
    for (; i < weights.size(); i += 2) {
        res.first += weights[i];
    }
    for (; j < weights.size(); j += 2) {
        res.second += weights[j];
    }
    return res;
}

// most popular
/*pair<int, int> rowWeights(const vector<int> &weights) {
    int sum1{}, sum2{};

    for (int i = 0; i < weights.size(); i++)
        i % 2 ? sum2 += weights[i] : sum1 += weights[i];

    std::pair<int, int> pr{sum1, sum2};

    return pr;

}*/

TEST(TEST, MyTEST) {
    using namespace std;

    using vec = vector<int>;
    using p = pair<int, int>;

    auto e = p{80, 0};
    ASSERT_EQ(rowWeights(vec{80}), e);

    e = p{100, 50};
    ASSERT_EQ(rowWeights(vec{100, 50}), e);

    e = p{120, 140};
    ASSERT_EQ(rowWeights(vec{50, 60, 70, 80}), e);

    e = p{62, 27};
    ASSERT_EQ(rowWeights(vec{13, 27, 49}), e);

    e = p{236, 92};
    ASSERT_EQ(rowWeights(vec{70, 58, 75, 34, 91}), e);

    e = p{211, 164};
    ASSERT_EQ(rowWeights(vec{29, 83, 67, 53, 19, 28, 96}), e);

    e = p{100, 50};
    ASSERT_EQ(rowWeights(vec{100, 50}), e);

    e = p{150, 151};
    ASSERT_EQ(rowWeights(vec{100, 51, 50, 100}), e);

    e = p{207, 235};
    ASSERT_EQ(rowWeights(vec{39, 84, 74, 18, 59, 72, 35, 61}), e);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}