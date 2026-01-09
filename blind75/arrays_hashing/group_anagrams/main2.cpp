#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<std::string>>
    groupAnagrams(std::vector<std::string> &strs) {

        if (strs.size() == 1)
            return {{strs[0]}};

        // Maps: freq_array -> {<strings_of_same_freq_array>}
        //      - vectors and arrays are not hashable
        //      - must create a new key for the freq_array
        std::unordered_map<std::string, std::vector<std::string>> result;

        // O(n)
        for (const auto &str : strs) {
            std::vector<int> freq(26, 0); // a->z : 0->25

            // Count the character frequencies in each str
            // O(m) -> average length of a string
            for (const auto &character : str) {
                freq[character - 'a']++;
            }

            // Create hashable key for frequency
            std::string key = "";
            for (int num : freq) {
                key += std::to_string(num) + ", ";
            }

            // Insert into hashtable
            result[key].push_back(str);
        }

        std::vector<std::vector<std::string>> answer;
        // Use structured binding -> c++17
        // cant be const auto & since move constructors cant bind const
        for (auto &[_, val] : result) {
            answer.emplace_back(std::move(val));
            // ***** USE MOVE TO REDUCE COPY OVERHEAD ******
            // Transfers ownership
        }

        return answer;
    }

    void printAns(std::vector<std::vector<std::string>> ans) {

        for (const auto &vec : ans) {
            std::cout << "[";

            for (const auto &str : vec) {
                std::cout << str << ", ";
            }
            std::cout << "]" << std::endl;
        }
    }
};

int main() {

    std::cout << " ----------- Group Anagrams (Sorting solution) ----------- "
              << std::endl;
    Solution sol;

    std::vector<std::string> input1 = {"eat", "tea", "tan",
                                       "ate", "nat", "bat"};

    std::vector<std::vector<std::string>> output1 = sol.groupAnagrams(input1);
    std::cout << "Output 1: " << std::endl;
    sol.printAns(output1);
    std::cout << std::endl;

    return 0;
}
