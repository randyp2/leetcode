#include <iostream>
#include <stdexcept>

class Solution {
  public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
        const int N = nums.size();

        std::vector<std::vector<int>> res;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < N; ++i) {

            // Skippping over duplicates
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            int new_target = 0 - nums[i];

            // Initiate two pointer approach
            int l = i + 1;
            int r = N - 1;

            while (l < r) {
                int sum = nums[l] + nums[r];

                // If sum = new_target -> record answer
                if (sum == new_target) {
                    res.push_back({nums[i], nums[l], nums[r]});

                    while (l < r && nums[l] == nums[l + 1])
                        ++l;
                    while (l < r && nums[r] == nums[r - 1])
                        --r;

                    ++l;
                    --r;
                } else if (sum < new_target) {
                    ++l;
                } else {
                    --r;
                }
            }
        }

        return res;
        throw std::runtime_error("Function not implemented yet...");
    };
};

int main() {
    std::cout << "--- THREE SUM ---\n";
    return 0;
}
