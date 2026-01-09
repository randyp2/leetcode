#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    /**
<<<<<<< HEAD
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
=======
     * Time complexity: O(n * mlogm) -> m is longest string length
     * Space complexity: O(n)
>>>>>>> 73c321f (1/9/26: Completed group anagrams)
     */
    std::vector<std::vector<std::string>>
    groupAnagrams(std::vector<std::string> &strs) {

<<<<<<< HEAD
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
=======
        if (strs.size() == 1)
            return {{strs[0]}};
        if (strs[0] == "")
            return {{""}};

        // Two words are an anagram if theyre sorted versions are equivalent
        // Maps: sorted-string -> {<equal-strings>}
        std::unordered_map<std::string, std::vector<std::string>> res;

        // const auto& -> dont copy and dont mutate : cost efficient for each
        // iter
        for (const auto &str : strs) { // O(n)

            std::string sortedStr = str;
            std::sort(sortedStr.begin(),
                      sortedStr.end()); // O(m log m) given that m is length  of
                                        // longest string

            res[sortedStr].push_back(str);
        }

        // Loop over hashmap and return ans
        std::vector<std::vector<std::string>> ans;

        // O(n)
        for (const auto &pair : res) {
            ans.push_back(pair.second);
>>>>>>> 73c321f (1/9/26: Completed group anagrams)
        }

        return ans;
    }
<<<<<<< HEAD
};

int main() { std::cout << " ------- Group Anagram ------- " << std::endl; }
=======

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
>>>>>>> 73c321f (1/9/26: Completed group anagrams)
