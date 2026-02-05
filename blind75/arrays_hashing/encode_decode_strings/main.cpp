#include <cctype>
#include <iostream>
#include <stdexcept>
#include <vector>

class Solution {
  public:
    int to_number(std::string str) {
        int ans = 0;

        for (char c : str) {
            ans = ans * 10 + (c - '0');
        }

        return ans;
    }
    std::string encode(std::vector<std::string> &strs) {

        /**
         * Metadata that is unique to every string - length
         * Store length before the content of the string [length][string]
         * However what if string contains digits then -> 5232123 = ambiguous
         *
         * Add a delimiter -> [length][delimiter][string]
         */

        std::string encoded = "";

        // Runtime: O(N)
        for (const auto &str : strs) {
            encoded += std::to_string(str.length()) + ";" + str;
        }

        return encoded;
    }

    std::vector<std::string> decode(std::string s) {

        std::vector<std::string> decoded;

        std::string token = "";
        for (int i = 0; i < s.length(); ++i) {

            // Find index of delimiter
            int j = i;
            while (s[j] != ';')
                ++j;

            // Get length Metadata
            int length = to_number(s.substr(i, j - i));

            // Get string
            decoded.push_back(s.substr(j + 1, length));
            i = j + length;
        }

        return decoded;
    }
};

int main() {
    std::cout << "Encode and decode strings: " << std::endl;

    Solution sol;

    return 0;
}
