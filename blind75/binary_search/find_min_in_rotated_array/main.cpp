#include <iostream>
#include <vector>

class Solution {

  public:
    int findMin(std::vector<int> &nums) {
        if (nums.size() == 1)
            return nums[0];

        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;

            // Array is rotated search answer is in the right half
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return nums[l];
    }
};

int main() {
    std::cout << "--- FIND MINIMUM IN ROTATED ARRAY ---\n";
    return 0;
};
