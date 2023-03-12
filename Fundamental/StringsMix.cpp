/*
Given two strings s1 and s2, we want to visualize how different the two strings are. We will only take into account the lowercase letters (a to z). First let us count the frequency of each lowercase letters in s1 and s2.

s1 = "A aaaa bb c"

s2 = "& aaa bbb c d"

s1 has 4 'a', 2 'b', 1 'c'

s2 has 3 'a', 3 'b', 1 'c', 1 'd'

So the maximum for 'a' in s1 and s2 is 4 from s1; the maximum for 'b' is 3 from s2. In the following we will not consider letters when the maximum of their occurrences is less than or equal to 1.

We can resume the differences between s1 and s2 in the following string: "1:aaaa/2:bbb" where 1 in 1:aaaa stands for string s1 and aaaa because the maximum for a is 4. In the same manner 2:bbb stands for string s2 and bbb because the maximum for b is 3.

The task is to produce a string in which each lowercase letters of s1 or s2 appears as many times as its maximum if this maximum is strictly greater than 1; these letters will be prefixed by the number of the string where they appear with their maximum value and :. If the maximum is in s1 as well as in s2 the prefix is =:.

In the result, substrings (a substring is for example 2:nnnnn or 1:hhh; it contains the prefix) will be in decreasing order of their length and when they have the same length sorted in ascending lexicographic order (letters and digits - more precisely sorted by codepoint); the different groups will be separated by '/'. See examples and "Example Tests".

Hopefully other examples can make this clearer.

s1 = "my&friend&Paul has heavy hats! &"
s2 = "my friend John has many many friends &"
mix(s1, s2) --> "2:nnnnn/1:aaaa/1:hhh/2:mmm/2:yyy/2:dd/2:ff/2:ii/2:rr/=:ee/=:ss"

s1 = "mmmmm m nnnnn y&friend&Paul has heavy hats! &"
s2 = "my frie n d Joh n has ma n y ma n y frie n ds n&"
mix(s1, s2) --> "1:mmmmmm/=:nnnnnn/1:aaaa/1:hhh/2:yyy/2:dd/2:ff/2:ii/2:rr/=:ee/=:ss"

s1="Are the kids at home? aaaaa fffff"
s2="Yes they are here! aaaaa fffff"
mix(s1, s2) --> "=:aaaaaa/2:eeeee/=:fffff/1:tt/2:rr/=:hh"
Note for Swift, R, PowerShell
        The prefix =: is replaced by E:

s1 = "mmmmm m nnnnn y&friend&Paul has heavy hats! &"
s2 = "my frie n d Joh n has ma n y ma n y frie n ds n&"
mix(s1, s2) --> "1:mmmmmm/E:nnnnnn/1:aaaa/1:hhh/2:yyy/2:dd/2:ff/2:ii/2:rr/E:ee/E:ss"

*/

#include <gtest/gtest.h>
#include <map>
#include <algorithm>
#include <vector>

class Mix {
public:
    static std::string mix(const std::string &s1, const std::string &s2);
};

std::map<char, int> countLowercaseGreaterThanOne(const std::string &s) {
    std::map<char, int> res;
    for (auto &c: s) {
        if (islower(c) && res.count(c) == 0) {
            auto cnt = std::count(s.begin(), s.end(), c);
            if (cnt > 1) {
                res[c] = cnt;
            }
        }
    }
    return res;
}

std::vector<std::pair<std::string, int> > Merge2Map(std::map < char, int > &m1, std::map < char, int > &m2) {
    std::vector<std::pair<std::string, int> > res;
    for (char c = 'a'; c <= 'z'; c++) {
        if (m1.count(c) > 0 && m2.count(c) == 0) {
            res.emplace_back(std::string(m1[c], c), 1);
        } else if (m1.count(c) == 0 && m2.count(c) > 0) {
            res.emplace_back(std::string(m2[c], c), 2);
        } else if (m1.count(c) > 0 && m2.count(c) > 0) {
            if (m1[c] > m2[c]) {
                res.emplace_back(std::string(m1[c], c), 1);
            } else if (m1[c] < m2[c]) {
                res.emplace_back(std::string(m2[c], c), 2);
            } else {
                res.emplace_back(std::string(m2[c], c), 3);
            }
        }
    }
    std::sort(res.begin(), res.end(), [](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) {
        return a.first.length() > b.first.length() || (a.first.length() == b.first.length() && a.second < b.second)
               || (a.first.length() == b.first.length() && a.second == b.second && a.first[0] < b.first[0]);
    });
    return res;
}

std::string Mix::mix(const std::string &s1, const std::string &s2) {
    std::map<char, int> m1, m2;
    m1 = countLowercaseGreaterThanOne(s1);
    m2 = countLowercaseGreaterThanOne(s2);
    std::vector<std::pair<std::string, int> > resArr;
    resArr = Merge2Map(m1, m2);
    std::string res;
    for (auto &i: resArr) {
        if (i.second == 3) {
            res += "=:" + i.first + "/";
        } else {
            res += std::to_string(i.second) + ":" + i.first + "/";
        }
    }
    return res.substr(0, res.length() - 1);
}

/*#include <vector>

using namespace std;

class Mix {
public:
    static std::string mix(const std::string &s1, const std::string &s2) {
        string rv;
        int aFreq[26] = {0}, bFreq[26] = {0};
        vector<pair<string, string>> table;
        for (auto c: s1) if (islower(c)) aFreq[c - 'a']++;
        for (auto c: s2) if (islower(c)) bFreq[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            int frequency = max(aFreq[i], bFreq[i]);
            if (frequency <= 1) continue;
            string stringLoc = "=";
            if (aFreq[i] != bFreq[i]) stringLoc = ((aFreq[i] > bFreq[i]) ? "1" : "2");
            table.push_back(make_pair(string(frequency, ((char) ('a' + i))), stringLoc));
        }
        sort(table.begin(), table.end(), [](pair<string, string> a, pair<string, string> b) {
            if (a.first.length() != b.first.length()) return (a.first.length() > b.first.length());
            return (a.second + ":" + a.first < b.second + ":" + b.first);
        });
        for (auto x: table)
            rv += x.second + ":" + x.first + "/";
        return rv.substr(0, rv.length() - 1);
    }
};*/

TEST(TEST, MyTEST) {
    Mix mix;
    std::string s1("my&friend&Paul has heavy hats! &");
    std::string s2("my friend John has many many friends &");
    std::string ans = mix.mix(s1, s2);
    std::string sol = "2:nnnnn/1:aaaa/1:hhh/2:mmm/2:yyy/2:dd/2:ff/2:ii/2:rr/=:ee/=:ss";
    ASSERT_EQ(ans, sol);
    sol = "1:ooo/1:uuu/2:sss/=:nnn/1:ii/2:aa/2:dd/2:ee/=:gg";
    ans = mix.mix("looping is fun but dangerous", "less dangerous than coding");
    ASSERT_EQ(ans, sol);
}


int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}