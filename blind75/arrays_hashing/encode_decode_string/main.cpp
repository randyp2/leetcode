#include <cctype>
#include <iostream>
#include <string>
#include <vector>

class Solution {

  public:
    std::string encode(std::vector<std::string> &strs) {

        const size_t N = strs.size();

        std::string encoded_string = "";
        for (const auto &str : strs) {
            const int length = str.length();

            // Encode w/ delimiter = # + length + #
            encoded_string += ("#" + std::to_string(length) + "#" + str);
        }

        return encoded_string;
    }

    std::vector<std::string> decode(std::string s) {
        const size_t N = s.length();

        std::vector<std::string> ans;

        for (size_t i = 0; i < N; ++i) {

            // Get length of string to parse
            int length_ = 0;
            int idx_to_parse = -1;
            if (i != N - 1 && s[i] == '#') {
                if (std::isdigit(s[i + 1])) {
                    // Loop until you get the actual digit
                    // #10#

                    std::string length = "";
                    int idx = i;
                    while (s[idx] != '#' && idx < N) {
                        length += s[idx++];
                    }
                    idx_to_parse = idx + 1;

                    length_ = std::stoi(length);
                }
            }

            std::string parsed_str = "";
            while (idx_to_parse < length_) {
                parsed_str += s[idx_to_parse++];
            }

            ans.push_back(parsed_str);
            i += length_;
        }

        return ans;
    }
};

int main() {
    std::cout << "--- ENCODDE DECODE A STRING ---\n";
    return 0;
};
