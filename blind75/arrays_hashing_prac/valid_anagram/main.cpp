#include <iostream>
#include <stdexcept>
#include <unordered_map>

class Solution {
  public:
    bool isAnagram(std::string s, std::string t) {

        if (s.length() != t.length())
            return false;

        std::unordered_map<int, int> s_map;
        std::unordered_map<int, int> t_map;

        for (char c : s)
            s_map[c]++;

        for (char c : t)
            t_map[c]++;

        return s_map == t_map;

        throw std::runtime_error("Function not implemented yet...");
    }
};

int main() {
    std::cout << "--- VALID ANAGRAM ---\n";
    return 0;
}
