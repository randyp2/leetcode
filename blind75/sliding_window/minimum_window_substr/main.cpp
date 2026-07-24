#include <climits>
#include <iostream>
#include <unordered_map>

class Solution {

  public:
    std::string minWindow(std::string s, std::string t) {
        if (t.empty())
            return "";

        const std::size_t N = s.length();

        std::unordered_map<char, int> have_map;
        std::unordered_map<char, int> need_map;

        for (char c : t)
            need_map[c]++;

        int have = 0, need = need_map.size();
        int l = 0, r = 0;

        int shortest_substr_length = INT_MAX;
        int shortest_substr_first_idx = 0;

        while (r < s.size()) {
            // Loop through trying to find smallest substr

            if (need_map.contains(s[r])) {
                have_map[s[r]]++;

                // Check if we collected all characters needed for t[r]
                if (have_map[s[r]] == need_map[s[r]])
                    ++have;
            }

            // Found all characters of t in current substr
            while (need == have) {
                // New shortest substr found
                if (shortest_substr_length > r - l + 1) {
                    shortest_substr_length = r - l + 1;
                    shortest_substr_first_idx = l;
                }

                // Increment the left ptr until current substr is invalid
                if (need_map.contains(s[l])) {
                    --have_map[s[l]];

                    if (have_map[s[l]] < need_map[s[l]])
                        --have;
                }
                ++l;
            }
            ++r;
        }

        if (shortest_substr_length == INT_MAX)
            return "";
        return s.substr(shortest_substr_first_idx, shortest_substr_length);
    }
};

int main() {
    std::cout << "--- MINIMUM WINDOW ---\n";
    return 0;
};
