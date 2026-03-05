#include <iostream>
#include <stdexcept>
#include <unordered_map>

class Solution {
  public:
    /**
     * @brief Determine if two strings are anagram
     * Two strings are valid anagrams <=> they have same amount of chars
     *
     * @param first string
     * @param second string to compare
     *
     * @return bool -> valid anagarm
     */
    bool validAnagram(std::string t, std::string s) {
        if (t.length() != s.length())
            return false;

        std::unordered_map<char, int> t_map;
        std::unordered_map<char, int> s_map;

        for (char c : t)
            t_map[c]++;

        for (char c : t)
            t_map[c]++;

        return t_map == s_map;

        throw std::runtime_error("Function not implemented yet");
    }
};

int main() {
    std::cout << "--- GROUP ANAGRAMS ---\n";
    return 0;
}
