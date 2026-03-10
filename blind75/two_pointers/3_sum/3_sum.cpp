#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

class Solution {

  public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {

        // Sort the list -> ascending order
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> result;

        const int N = nums.size();
        for (int i = 0; i < N; ++i) {
            int curr_num = nums[i];
            int target = 0 - curr_num;

            // Skip over duplicates
            if (i != 0)
                if (nums[i - 1] == curr_num)
                    continue;

            int l = i + 1;
            int r = N - 1;

            /**
             * Since the list is sorted
             * if nums[left_pointer] + nums[right_pointer] < target;
             *  -> then --right_pointer;
             *  -> else ++left_pointer;
             */
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum == target) {
                    result.push_back({curr_num, nums[l], nums[r]});

                    // Consider [-1, 0, 0, 1, 1]
                    // We must skip the duplicates
                    while (l < r && nums[l] == nums[l + 1])
                        ++l;
                    while (l < r && nums[r] == nums[r - 1])
                        --r;
                    ++l;
                    --r;
                } else if (sum < target) {
                    ++l;
                } else {
                    --r;
                }
            }
        }

        return result;
        throw std::runtime_error("Function not implemented yet...");
    }
};

int main() {
    std::cout << "--- 3 SUM --- \n";
    return 0;
}
