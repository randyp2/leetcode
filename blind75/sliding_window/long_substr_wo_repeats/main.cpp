#include <iostream>
#include <unordered_set>

class Solution {

  public:
    int lengthOfLongestSubstring(std::string s) {
        const std::size_t N = s.length();
        if (N <= 1)
            return s.length();

        std::unordered_set<char> s_set;

        int l = 0;
        int r = 1;

        // init set with curr pointers
        s_set.insert(s[l]);

        int max_len = 0;
        while (r < N) {
            auto [it, inserted] = s_set.insert(s[r]);
            bool repeat = !inserted;

            while (repeat) {
                s_set.erase(s[l]);
                ++l;

                const auto [it2, inserted2] = s_set.insert(s[r]);
                if (inserted2)
                    repeat = false;
            }

            max_len = std::max(max_len, r - l);
            ++r;
        }

        return max_len + 1;
    }
};

int main() {
    std::cout << "--- LENGHT OF LONGEST SUBSTRING WIHTOUT REPEATS ---\n";
    return 0;
};
