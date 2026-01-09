#include <iostream>
#include <unordered_map>

class Solution {
  public:
    // Space complexity O(1): At most can be 26 characters so space is not
    // dynamic
    bool isAnagram(std::string s, std::string t) {

        if (s.length() != t.length())
            return false;

        // Construct frequency hashmaps for each string
        std::unordered_map<char, int> s_map;
        std::unordered_map<char, int> t_map;

        // Init hashmaps
        // Time complexity O(n)
        for (char c : s)
            s_map[c]++;

        // Time complexity O(n)
        for (char c : t)
            t_map[c]++;

        return s_map == t_map;
    }
};

int main() {

    std::cout << "Hello world" << std::endl;
    Solution sol;

    std::cout << "Test 1: " << sol.isAnagram("anagram", "nagaram") << std::endl;
    std::cout << "Test 2: " << sol.isAnagram("rat", "car") << std::endl;
    std::cout << "Test 3: " << sol.isAnagram("racecar", "carrace") << std::endl;
    std::cout << "Test 4: " << sol.isAnagram("jar", "jam") << std::endl;
    return 0;
}
