#include <array>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    /**
     * General notes:
     *
     * What makes an anagram? => Two strigs that contain the same frequency of
     * letters
     *
     * First idea (brute force):
     *    - Keep track of the frequency via a map of first string in vector
     *    - Compare to every other string
     *    - Group strings up
     *
     *    Result: O(n^2)
     *
     * Second idea (optimal or suboptimal?):
     *    - Create a map s.t.:
     *        key = vector representing frequencies of each character
     *        value = string associated to that frequncy
     *
     *    Result: O(n)
     */
    std::vector<std::vector<std::string>>
    groupAnagrams(std::vector<std::string> &strs) {

        std::unordered_map<std::string, std::vector<std::string>> m;
        for (auto &str : strs) {
            // Cool c++ fact
            // std::array has same memory has a normal array
            // it keeps track of size since 26 is part of its type
            std::array<int, 26> freq{}; // Create a std array with fixed size of
                                        // 26 - Default initialize

            // Count the frequeny of the string
            for (char ch : str) {
                freq[ch - 'a']++;
            }

            // Construct key: O(26)
            std::string key = "";
            for (int num : freq) {
                key += std::to_string(num) + "#";
            }

            m[key].push_back(str);
        }

        // Return result in expected output format
        std::vector<std::vector<std::string>> ans;
        // Use structured binding
        for (auto &[_, val] : m) {
            // use move constructor instead of copy constructor
            ans.push_back(std::move(val));
        }

        return ans;
    }
};

int main() { std::cout << " ------- Group Anagram ------- " << std::endl; }
