#include <iostream>
#include <unordered_map>

class Solution {
  public:
    bool isAnagram(std::string s, std::string t) {

        if (s.length() != t.length())
            return false;

        // Create frequency maps for the characters of each string
        std::unordered_map<char, int> s_map;
        std::unordered_map<char, int> t_map;

        for (char c : s)
            s_map[c]++;

        for (char c : t)
            t_map[c]++;

        return s_map == t_map;
    }
};

int main() {
    std::cout << "=== Valid Anagram ===\n";
    return 0;
}
