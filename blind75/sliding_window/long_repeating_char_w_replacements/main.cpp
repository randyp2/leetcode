#include <algorithm>
#include <array>
#include <climits>
#include <iostream>
#include <sys/types.h>

class Solution {

  public:
    int characterReplacement(std::string s, int k) {

        std::array<int, 26> freq{};

        int l = 0;
        int r = 0;

        int max_freq = 0;
        int ans = INT_MIN;

        while (r < s.length()) {
            freq[s[r] - 'A']++;
            max_freq = std::max(max_freq, freq[s[r] - 'A']);

            while ((r - l + 1) - max_freq > k) { // While invalid
                freq[s[l] - 'A']--;
                ++l;
            }

            ans = std::max(ans, r - l + 1);
            ++r;
        }

        return ans;
    }
};

int main() {
    std::cout << "--- LONGEST REEPATING CHARACTER REPLACEMENT ---\n";
    return 0;
};
