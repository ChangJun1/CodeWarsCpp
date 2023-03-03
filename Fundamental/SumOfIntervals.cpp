#include <gtest/gtest.h>
#include <unordered_set>

// 超时
int sum_intervals(std::vector<std::pair<int, int>> intervals) {
    if (intervals.empty()) {
        return 0;
    }
    if (intervals.size() == 1) {
        return intervals.back().second - intervals.back().first;
    }
    std::unordered_set<int> s;
    for (auto i: intervals) {
        for (int j = i.first; j < i.second; j++) {
            s.insert(j);
        }
    }
    return s.size();
}

// most popular
/*int sum_intervals(vector <pair<int, int>> v) {
    sort(v.begin(), v.end(),
         [](auto x, auto y) { return x.first != y.first ? x.first < y.first : x.second < y.second; });
    int r = 0, last = v[0].first;
    for (auto p: v) {
        int x = p.first, y = p.second;
        if (y <= last) continue;
        r += y - max(x, last);
        last = y;
    }
    return r;
}*/

TEST(TEST, MyTEST) {
    std::vector<std::pair<int, int>> intervals = {{1, 5}};
    ASSERT_EQ(sum_intervals(intervals), 4);

    intervals = {{1, 5},
                 {6, 10}};
    ASSERT_EQ(sum_intervals(intervals), 8);

    intervals = {{1, 4},
                 {7, 10},
                 {3, 5}};
    ASSERT_EQ(sum_intervals(intervals), 7);
}


int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
