/*
A bookseller has lots of books classified in 26 categories labeled A, B, ... Z. Each book has a code c of 3, 4, 5 or more characters. The 1st character of a code is a capital letter which defines the book category.

In the bookseller's stocklist each code c is followed by a space and by a positive integer n (int n >= 0) which indicates the quantity of books of this code in stock.

For example an extract of a stocklist could be:

L = {"ABART 20", "CDXEF 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60"}.
or
L = ["ABART 20", "CDXEF 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60"] or ....
You will be given a stocklist (e.g. : L) and a list of categories in capital letters e.g :

M = {"A", "B", "C", "W"}
or
M = ["A", "B", "C", "W"] or ...
and your task is to find all the books of L with codes belonging to each category of M and to sum their quantity according to each category.

For the lists L and M of example you have to return the string (in Haskell/Clojure/Racket/Prolog a list of pairs):

(A : 20) - (B : 114) - (C : 50) - (W : 0)
where A, B, C, W are the categories, 20 is the sum of the unique book of category A, 114 the sum corresponding to "BKWRK" and "BTSQZ", 50 corresponding to "CDXEF" and 0 to category 'W' since there are no code beginning with W.

If L or M are empty return string is "" (Clojure/Racket/Prolog should return an empty array/list instead).
*/

#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<std::pair<std::string, std::string> > splitArt(std::vector<std::string> &Vstr) {
    std::vector<std::pair<std::string, std::string> > res;
    for (auto v: Vstr) {
        int i = 0;
        while (i < v.size() && v[i] != ' ') {
            i++;
        }
        if (i == v.size()) {
            return res;
        }
        res.push_back({v.substr(0, 1), v.substr(i + 1, v.size() - i - 1)});
    }
    return res;
}

std::unordered_map<std::string, int> count(std::vector<std::pair<std::string, std::string> > &p) {
    std::unordered_map<std::string, int> m;
    for (auto v: p) {
        if (m[v.first] > 0) {
            m[v.first] += std::stoi(v.second);
        } else {
            m[v.first] = std::stoi(v.second);
        }
    }
    return m;
}


class StockList {
public:
    static std::string stockSummary(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories) {
        std::string res;
        if (lstOfArt.empty() || categories.empty()) {
            return res;
        }
        auto pairArt = splitArt(lstOfArt);
        auto m = count(pairArt);
        for (auto s: categories) {
            if (m[s] > 0) {
                res += "(" + s + " : " + std::to_string(m[s]) + ")" + " - ";
            } else {
                res += "(" + s + " : 0) - ";
            }
        }
        return res.substr(0, res.size() - 3);
    }
};

//most popular
/*class StockList {
public:
    static std::string stockSummary(std::vector<std::string> &books, std::vector<std::string> &categories) {
        if (books.empty() || categories.empty())
            return "";

        int stocks['Z' + 1] = {0};
        for (const std::string &book: books) {
            std::size_t position = book.find_first_of(" ", 2, 1);//从下标为2开始查找，每次参与匹配的字符长度为1
            stocks[book[0]] += std::atoi(book.data() + position);
        }

        std::string result = "";
        for (const std::string &category: categories) {
            result = result
                     + (result.empty() ? "" : " - ")
                     + "(" + category[0] + " : " + std::to_string(stocks[category[0]]) + ")";
        }

        return result;
    }
};*/

TEST(TEST, MyTEST) {
    std::vector<std::string> art = {"ABAR 200", "CDXE 500", "BKWR 250", "BTSQ 890", "DRTY 600"};
    std::vector<std::string> cd = {"A", "B"};
    ASSERT_EQ(StockList::stockSummary(art, cd), "(A : 200) - (B : 1140)");
    art = {"BBAR 150", "CDXE 515", "BKWR 250", "BTSQ 890", "DRTY 600"};
    cd = {"A", "B", "C", "D"};
    ASSERT_EQ(StockList::stockSummary(art, cd), "(A : 0) - (B : 1290) - (C : 515) - (D : 600)");
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
