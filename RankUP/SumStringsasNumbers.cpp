#include <gtest/gtest.h>
#include <string>

std::string sum_strings(const std::string &a, const std::string &b) {
    if (a.empty() || b.empty()) {
        return a.empty() ? b : a;
    }
    std::string add1 = std::string(a.rbegin(), a.rend());
    std::string add2 = std::string(b.rbegin(), b.rend());
    int flag = 0;
    std::string res;
    for (int i = 0; i < add1.length() || i < add2.length(); i++) {
        int tmp = i >= add1.length() ? (add2[i] - '0') + flag : i >= add2.length() ? (add1[i] - '0') + flag :
                                                                (add1[i] - '0') + (add2[i] - '0') + flag;
        if (tmp >= 10) {
            tmp -= 10;
            flag = 1;
        } else {
            flag = 0;
        }
        res += std::to_string(tmp);
    }

    if (flag == 1) {
        res += "1";
    }

    return std::string(res.rbegin(), res.rend());

}

// most popular
/*string sum_strings(const string &a, const string &b) {
    string result;
    int carry = 0, n = max(a.size(), b.size());
    for (int i = 0; i < n; i++) {
        if (i < a.size()) carry += a[a.size() - 1 - i] - '0';
        if (i < b.size()) carry += b[b.size() - 1 - i] - '0';
        result.push_back('0' + carry % 10);
        carry /= 10;
    }
    result.push_back(carry + '0');
    while (result.size() > 1 && result.back() == '0')
        result.pop_back();
    reverse(result.begin(), result.end());
    return result;
}*/


TEST(TEST, MyTEST) {
    ASSERT_EQ(sum_strings("623", "457"), "1080");
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
