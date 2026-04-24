#include <array>
#include <iostream>
#include <unordered_map>

class Solution {
  public:
    /**
     * Create ferquency arrays and incr and decr based on s and t characters
     * More memory efficient.
     * Uses spatial locality more than unorderd_map
     */
    bool isAnagram(std::string s, std::string t) {

        if (s.size() != t.size())
            return false;

        std::array<int, 26> freq;

        const int N = s.size();

        for (int i = 0; i < N; ++i) {
            const char s_char = s[i];
            const char t_char = t[i];

            // If anagrams these should cancel it out
            freq[s_char - 'a']++;
            freq[t_char - 'a']--;
        }

        // Freq array shuld be all 0's if true anagrams
        for (int num : freq) {
            if (num != 0)
                return false;
        }

        return true;
    }

    bool isAnagram2(std::string s, std::string t) {

        // Sort both strings
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        return s == t;
    }
};

int main() {
    std::cout << "--- VALID ANAGRAM ---\n";
    return 0;
}
