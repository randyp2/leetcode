#include <algorithm>
#include <array>
#include <iostream>
#include <stdexcept>

class Solution {
  public:
    int characterReplacement(std::string s, int k) {

        const int N = s.length();

        int l = 0;
        int r = 0;

        std::array<int, 26> freq_array{0};
        int max_substr = 0;
        int max_freq = 0;

        // Store initial frequency
        while (r < N) {
            ++(freq_array[s[r] - 'A']);

            // Compute the frequency
            int window_length = r - l + 1;
            max_freq = std::max(max_freq, freq_array[s[r] - 'A']);
            int replac_need = window_length - max_freq;

            if (replac_need > k) {

                // Shrink window until valid
                while (l < r && replac_need > k) {
                    // Remove freq
                    --(freq_array[s[l] - 'A']);
                    ++l;

                    window_length = r - l + 1;
                    replac_need = window_length - max_freq;
                }
            }

            max_substr = std::max(max_substr, window_length);
            ++r;
        }

        return max_substr;
    }
};

int main() {
    std::cout << "--- LONGEST REPEATING...---\n";
    return 0;
}
