#include <array>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<std::string>>
    groupAnagrams(std::vector<std::string> &strs) {

        const int N = strs.size();

        if (strs.size() == 1)
            return {{strs[0]}};

        std::unordered_map<std::string, std::vector<std::string>> m;

        for (const auto &str : strs) {
            std::array<int, 26> freq_array{};

            const int STR_LENGTH = str.length();
            for (int i = 0; i < STR_LENGTH; ++i)
                freq_array[str[i] - 'a']++;

            std::string key = "";
            for (int i = 0; i < 26; ++i)
                key += std::to_string(freq_array[i]);
        }

        throw std::runtime_error("Function not implemented yet");
    }
};

int main() {
    std::cout << "--- GROUP ANAGRAMS ---\n";
    return 0;
}
