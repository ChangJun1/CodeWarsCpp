#include <gtest/gtest.h>
#include <string>
#include <vector>

std::vector<std::string> get_pins_by_char(char c) {
    switch (c) {
        case '0':
            return {"0", "8"};
        case '1':
            return {"1", "2", "4"};
        case '2':
            return {"1", "2", "3", "5"};
        case '3':
            return {"2", "3", "6"};
        case '4':
            return {"1", "4", "5", "7"};
        case '5':
            return {"2", "4", "5", "6", "8"};
        case '6':
            return {"3", "5", "6", "9"};
        case '7':
            return {"4", "7", "8"};
        case '8':
            return {"0", "5", "7", "8", "9"};
        case '9':
            return {"6", "8", "9"};
        default:
            return {};
    }
}

std::vector<std::string> get_pins(std::string observed) {
    if (observed.empty()) {
        return {};
    }
    std::vector<std::string> first = get_pins_by_char(observed[0]);
    if (observed.length() == 1) {
        return first;
    }
    std::vector<std::string> res;
    std::vector<std::string> last = get_pins(observed.substr(1, observed.length() - 1));
    for (int i = 0; i < first.size(); ++i) {
        for (int j = 0; j < last.size(); ++j) {
            std::string tmp = first[i] + last[j];
            res.push_back(tmp);
        }
    }
    return res;
}

// most popular
/*using namespace std;

vector<string> get_pins(const string &observed, const string &prefix = "") {
    static const map<char, string> neighbors =
            {
                    {'1', "124"},
                    {'2', "1235"},
                    {'3', "236"},
                    {'4', "1457"},
                    {'5', "24568"},
                    {'6', "3569"},
                    {'7', "478"},
                    {'8', "05789"},
                    {'9', "689"},
                    {'0', "08"}
            };
    if (!observed.size()) return {prefix};
    vector<string> pins;
    for (auto c: neighbors.at(observed[0]))
        for (auto pin: get_pins(observed.substr(1), prefix + c))
            pins.push_back(pin);
    return pins;
}*/

TEST(TEST, MyTEST) {
    std::vector<std::string> output = get_pins("8");
    std::sort(output.begin(), output.end());
    std::vector<std::string> result = {"0", "5", "7", "8", "9"};
    ASSERT_EQ(output, result);

    output = get_pins("11");
    std::sort(output.begin(), output.end());
    result = {"11", "12", "14", "21", "22", "24", "41", "42", "44"};
    ASSERT_EQ(output, result);

    output = get_pins("369");
    std::sort(output.begin(), output.end());
    result = {"236", "238", "239", "256", "258", "259", "266", "268", "269", "296", "298", "299", "336", "338", "339",
              "356", "358", "359", "366", "368", "369", "396", "398", "399", "636", "638", "639", "656", "658", "659",
              "666", "668", "669", "696", "698", "699"};
    ASSERT_EQ(output, result);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
