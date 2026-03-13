#include <iostream>
#include <unordered_set>

class Solution {

  public:
    int lengthOfLongestSubstring(std::string s) {

        const size_t N = s.length();
        if (N == 0)
            return 0;

        std::unordered_set<char> s_set;
        int max = 1;

        size_t l = 0;
        size_t r = 0;
        while (r < N) {

            // Discard duplicates
            while (s_set.find(s[r]) != s_set.end()) {
                // Remove l and shrink the window
                s_set.erase(s[l]);
                l++;
            }

            // Find current max
            int curr_length = r - l + 1;
            max = std::max(max, curr_length);

            s_set.insert(s[r]);
            ++r;
        }

        return max;
    }
};

int main() {
    std::cout << "--- LENGTH OF LONGEST SUBSTRING ---\n";

    Solution sol;

    // set = {a, b, c}
    std::string input1 = "abcabcbb";
    std::string input2 = "pwwkew";
    std::string input3 = "bbb";

    int output1 = sol.lengthOfLongestSubstring(input1);
    int output2 = sol.lengthOfLongestSubstring(input2);
    int output3 = sol.lengthOfLongestSubstring(input3);

    std::cout << "Output1: " << output1 << std::endl;
    std::cout << "Output2: " << output2 << std::endl;
    std::cout << "Output3: " << output3 << std::endl;

    return 0;
}
