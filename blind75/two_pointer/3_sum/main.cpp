#include <algorithm>
#include <iostream>
#include <vector>

class Solution {

  public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
        const int N = nums.size();
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ans;

        for (int i = 0; i < N; ++i) {

            // Skip any duplicates
            if (i != 0) {
                if (nums[i - 1] == nums[i])
                    continue;
            }

            int l = i + 1;
            int r = N - 1;
            const int new_target = 0 - nums[i];
            while (l < r) {
                int sum = nums[l] + nums[r];

                if (sum == new_target) {
                    ans.push_back({nums[l], nums[r], nums[i]});

                    while (l < r && nums[l + 1] == nums[l])
                        ++l;
                    while (l < r && nums[r - 1] == nums[r])
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

        return ans;
    }
};

int main() {
    std::cout << "--- 3 SUM ---\n";
    return 0;
};
