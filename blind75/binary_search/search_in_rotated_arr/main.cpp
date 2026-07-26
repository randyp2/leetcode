#include <iostream>
#include <vector>

class Solution {

  public:
    int search(std::vector<int> &nums, int target) {

        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (nums[m] == target)
                return m;

            // If left half is sorted
            if (nums[l] <= nums[m]) {
                if (target >= nums[l] && target <= nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            } else {
                if (target >= nums[m] && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }

        return -1;
    }
};

int main() {
    std::cout << "--- SEARCH IN A ROTATED ARRAY ---\n";
    return 0;
};
