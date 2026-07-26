#include <array>
#include <iostream>
#include <sys/types.h>

class Solution {

  public:
    int characterReplacement(std::string s, int k) {

        std::array<int, 26> freq{};

        int l = 0;
        int ans = 0;
        int max_freq = 0;
        for (int r = 0; r < s.length(); ++r) {
            const int idx = s[r] - 'A';
            freq[idx]++;
            max_freq = std::max(max_freq, freq[idx]);

            // Invalid substring
            while ((r - l + 1) - max_freq > k) {
                freq[s[l] - 'A']--;
                ++l;
            }

            ans = std::max(ans, r - l + 1);
        }

        return ans;
    }
};

int main() {
    std::cout << "--- LONGEST REEPATING CHARACTER REPLACEMENT ---\n";
    return 0;
};
