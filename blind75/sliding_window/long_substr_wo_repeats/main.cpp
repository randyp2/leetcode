#include <iostream>
#include <unordered_set>

class Solution {

  public:
    int lengthOfLongestSubstring(std::string s) {
        const std::size_t N = s.length();
        if (N <= 1)
            return N;

        std::unordered_set<int> set;

        int l = 0;
        int ans = 0;
        for (int r = 0; r < N; ++r) {

            while (set.contains(s[r])) {
                set.erase(s[l]);
                ++l;
            }

            set.insert(s[r]);
            ans = std::max(ans, r - l + 1);
        }

        return ans;
    }
};

int main() {
    std::cout << "--- LENGHT OF LONGEST SUBSTRING WIHTOUT REPEATS ---\n";
    return 0;
};
