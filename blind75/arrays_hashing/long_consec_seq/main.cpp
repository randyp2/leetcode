#include <climits>
#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {

  public:
    int longestConsecutive(std::vector<int> &nums) {
        const size_t N = nums.size();

        if (N == 0)
            return 0;

        // Create our unorderset of numbers
        std::unordered_set<int> s;
        for (int num : nums)
            s.insert(num);

        // Find the longest interval
        int ans = INT_MIN;
        for (int num : nums) {
            int count = 1;

            // find the start number
            // continue if not start of the interval
            if (s.find(num - 1) != s.end())
                continue;

            // Count the sequence
            while (s.find(num + 1) != s.end()) {
                ++count;
                ++num;
            }

            ans = std::max(ans, count);
        }

        return ans;
    }
};

int main() {
    std::cout << "--- LONGEST CONSECUTIVE SEQUENCE ---\n";
    return 0;
};
