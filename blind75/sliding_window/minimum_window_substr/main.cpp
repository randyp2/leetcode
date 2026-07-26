#include <climits>
#include <iostream>
#include <unordered_map>

class Solution {

  public:
    std::string minWindow(std::string s, std::string t) {
        if (t.empty())
            return "";

        std::unordered_map<char, int> need_map, have_map;
        for (char c : t)
            ++need_map[c];

        int shortest_substr_length = INT_MAX;
        int shortest_substr_idx = 0;

        int need = need_map.size();
        int have = 0;

        int l = 0;
        for (int r = 0; r < s.length(); ++r) {

            if (need_map.contains(s[r])) {
                have_map[s[r]]++;

                if (have_map[s[r]] == need_map[s[r]])
                    ++have;
            }

            while (need == have) {
                if (shortest_substr_length > r - l + 1) {
                    shortest_substr_length = r - l + 1;
                    shortest_substr_idx = l;
                }

                if (have_map.contains(s[l])) {
                    have_map[s[l]]--;

                    if (have_map[s[l]] < need_map[s[l]])
                        --have;
                }

                ++l;
            }
        }

        if (shortest_substr_length == INT_MAX)
            return "";
        return s.substr(shortest_substr_idx, shortest_substr_length);
    }
};

int main() {
    std::cout << "--- MINIMUM WINDOW ---\n";
    return 0;
};
