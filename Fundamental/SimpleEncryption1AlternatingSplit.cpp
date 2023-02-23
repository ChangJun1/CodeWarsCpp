/*
Implement a pseudo-encryption algorithm
which given a string S and an integer N concatenates all the odd-indexed characters of S with all the even-indexed characters of S,
this process should be repeated N times.

Examples:

encrypt("012345", 1)  =>  "135024"
encrypt("012345", 2)  =>  "135024"  ->  "304152"
encrypt("012345", 3)  =>  "135024"  ->  "304152"  ->  "012345"

encrypt("01234", 1)  =>  "13024"
encrypt("01234", 2)  =>  "13024"  ->  "32104"
encrypt("01234", 3)  =>  "13024"  ->  "32104"  ->  "20314"
Together with the encryption function, you should also implement a decryption function which reverses the process.

If the string S is an empty value or the integer N is not positive, return the first argument without changes.

This kata is part of the Simple Encryption Series:

Simple Encryption #1 - Alternating Split
Simple Encryption #2 - Index-Difference
Simple Encryption #3 - Turn The Bits Around
Simple Encryption #4 - Qwerty
Have fun coding it and please don't forget to vote and rank this kata! :-)
*/

#include <gtest/gtest.h>

std::string encrypt(std::string text, int n) {
    if (text.empty()) {
        return "";
    }
    std::string oddString, evenString;
    std::string res(text);

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < res.size(); i++) {
            if (i % 2 == 0) {
                evenString.push_back(res[i]);
            } else {
                oddString.push_back(res[i]);
            }
        }
        res = oddString + evenString;
        evenString.clear();
        oddString.clear();
    }
    return res;
}

std::string decrypt(std::string encryptedText, int n) {
    if (encryptedText.empty()) {
        return "";
    }
    std::string res(encryptedText);
    std::string tmp(res);
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < tmp.size() / 2; i++) {
            res[2 * i + 1] = tmp[i];
        }
        for (int i = tmp.size() / 2; i < tmp.size(); i++) {
            res[2 * (i - tmp.size() / 2)] = tmp[i];
        }
        tmp = res;
    }
    return res;
}

// most popular
/*std::string encrypt(std::string text, int n) {
    if (n <= 0) return text;

    const unsigned stringSize = text.size();

    for (unsigned i = 0; i < n; i++) {
        std::string eText;

        for (unsigned j = 1; j < stringSize; j += 2)
            eText.push_back(text[j]);
        for (unsigned j = 0; j < stringSize; j += 2)
            eText.push_back(text[j]);

        text = eText;
    }

    return text;
}

std::string decrypt(std::string text, int n) {
    if (n <= 0) return text;

    const unsigned stringSize = text.size();
    const unsigned stringSizeHalf = stringSize / 2;

    for (unsigned i = 0; i < n; i++) {
        std::string dText;

        for (unsigned j = 0; j < stringSizeHalf; j++) {
            dText.push_back(text[j + stringSizeHalf]);
            dText.push_back(text[j]);
        }

        if (stringSize & 1)
            dText.push_back(text[stringSize - 1]);

        text = dText;
    }

    return text;
}*/

TEST(TEST, MyTEST) {
    ASSERT_EQ(encrypt("This is a test!", 0), "This is a test!");
    ASSERT_EQ(encrypt("This is a test!", 1), "hsi  etTi sats!");
    ASSERT_EQ(encrypt("This is a test!", 2), "s eT ashi tist!");
    ASSERT_EQ(encrypt("This is a test!", 3), " Tah itse sits!");
    ASSERT_EQ(encrypt("This is a test!", 4), "This is a test!");
    ASSERT_EQ(encrypt("This is a test!", -1), "This is a test!");
    ASSERT_EQ(encrypt("This kata is very interesting!", 1), "hskt svr neetn!Ti aai eyitrsig");

    ASSERT_EQ(decrypt("This is a test!", 0), "This is a test!");
    ASSERT_EQ(decrypt("hsi  etTi sats!", 1), "This is a test!");
    ASSERT_EQ(decrypt("s eT ashi tist!", 2), "This is a test!");
    ASSERT_EQ(decrypt(" Tah itse sits!", 3), "This is a test!");
    ASSERT_EQ(decrypt("This is a test!", 4), "This is a test!");
    ASSERT_EQ(decrypt("This is a test!", -1), "This is a test!");
    ASSERT_EQ(decrypt("hskt svr neetn!Ti aai eyitrsig", 1), "This kata is very interesting!");

    ASSERT_EQ(encrypt("", 0), "");
    ASSERT_EQ(encrypt("", 3), "");
    ASSERT_EQ(decrypt("", 0), "");
    ASSERT_EQ(decrypt("", 3), "");
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
