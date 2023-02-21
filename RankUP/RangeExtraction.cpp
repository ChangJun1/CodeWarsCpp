/*
A format for expressing an ordered list of integers is to use a comma separated list of either

individual integers
or a range of integers denoted by the starting integer separated from the end integer in the range by a dash, '-'.
The range includes all integers in the interval including both endpoints. It is not considered a range unless it spans at least 3 numbers.
For example "12,13,15-17"

Complete the solution so that it takes a list of integers in increasing order and returns a correctly formatted string in the range format.

Example:

range_extraction({-10, -9, -8, -6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20});
// returns "-10--8,-6,-3-1,3-5,7-11,14,15,17-20"
*/


#include <gtest/gtest.h>
#include <string>
#include <vector>

std::string range_extraction(std::vector<int> args) {
    if (args.empty()) {
        return "";
    }
    std::string res;
    for (int i = 0; i < args.size();) {
        int j = i;
        while (args[j] + 1 == args[j + 1] && j < args.size() - 1) {
            j++;
        }
        if (j - i >= 2) {
            res += std::to_string(args[i]) + "-" + std::to_string(args[j]) + ",";
        } else {
            for (int k = i; k <= j; k++) {
                res += std::to_string(args[k]) + ",";
            }
        }
        i = j + 1;
    }
    return res.substr(0, res.length() - 1);
}

//most popular
//std::string range_extraction(std::vector<int> args)
//{
//    using Range = std::pair<int, int>;
//    std::vector<Range> ranges;
//    for(auto &i : args)
//        if(ranges.empty() || ranges.back().second + 1 != i)
//            ranges.push_back({i, i});
//        else
//            ++ranges.back().second;
//
//    std::string result;
//    for(auto &r : ranges)
//        if(r.first == r.second)
//            result.append(std::to_string(r.first) + ",");
//        else
//            result.append(std::to_string(r.first) +
//                          ((r.first + 1 == r.second) ? ',' : '-') +
//                          std::to_string(r.second) +
//                          ",");
//    result.pop_back();
//    return result;
//}

TEST(TEST, MyTEST) {
    ASSERT_EQ(range_extraction({-6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20}),
              "-6,-3-1,3-5,7-11,14,15,17-20");
    ASSERT_EQ(range_extraction({-3, -2, -1, 2, 10, 15, 16, 18, 19, 20}), "-3--1,2,10,15,16,18-20");
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
