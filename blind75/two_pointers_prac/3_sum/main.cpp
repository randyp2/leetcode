#include <iostream>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {

        std::sort(nums.begin(), nums.end());
        const int N = nums.size();
        std::vector<std::vector<int>> res;

        for (int i = 0; i < N; ++i) {

            int curr_num = nums[i];
            int target = 0 - curr_num;

            if (i != 0 && nums[i - 1] == nums[i])
                continue;

            int l = i + 1;
            int r = N - 1;
            while (l < r) {

                int left_num = nums[l];
                int right_num = nums[r];
                int sum = left_num + right_num;

                if (sum == target) {

                    res.push_back({curr_num, left_num, right_num});

                    int next_left = nums[l + 1];
                    int next_right = nums[r - 1];
                    while (l < r && left_num == next_left)
                        left_num = nums[++l];
                    while (l < r && right_num == next_right)
                        right_num = nums[--r];

                    ++l;
                    --r;
                } else if (sum < target) {
                    ++l;
                } else {
                    --r;
                }
            }
        }

        return res;
    }
};

int main() {
    std::cout << "--- 3Sum ---\n";
    return 0;
}
