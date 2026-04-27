#include <array>
#include <iostream>
#include <unordered_map>

class Solution {

  public:
    bool isAnagram2(std::string s, std::string t) {

        if (s.length() != t.length())
            return false;

        const size_t N = s.length();

        std::array<int, 26> freq_arr{};

        // Increment the character for s
        // Decrement the character for t
        for (size_t i = 0; i < N; ++i) {
            freq_arr[s[i] - 'a']++;
            freq_arr[t[i] - 'a']--;
        }

        // Anagram if the array is all 0's
        // all_of -> C++11: Accepts a lambda to execute per each element
        return std::all_of(freq_arr.begin(), freq_arr.end(),
                           [](int x) { return x == 0; });
    }

    bool isAnagram(std::string s, std::string t) {

        if (s.length() != t.length())
            return false;

        std::unordered_map<char, int> s_map;
        std::unordered_map<char, int> t_map;

        // Build the unorderd map
        for (char c : s)
            ++s_map[c];

        for (char c : t)
            ++t_map[c];

        // Valid anagram if maps are identical
        return s_map == t_map;
    }
};

int main() {
    std::cout << "--- VALID ANAGRAM ---\n";
    return 0;
};
