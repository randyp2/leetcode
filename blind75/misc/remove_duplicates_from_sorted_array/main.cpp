#include <iostream>
#include <vector>

class Solution {
  public:
    /**
     * Input: nums = [0,0,1,1,1,2,2,3,3,4]
     *
     * left_ptr = 0
     * right_ptr = 1
     *
     *
     * Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
     */

    int removeDuplicates(std::vector<int> &nums) {

        int left_ptr = 0;
        int right_ptr = 1;

        while (right_ptr < nums.size()) {
            if (nums[right_ptr] != nums[left_ptr]) {
                nums[++left_ptr] = nums[right_ptr];
            }

            ++right_ptr;
        }
        return left_ptr + 1;
    }
};

int main() {
    std::cout << "--- REMOVE DUPLICATES FROM SROTED ARRAY ---\n";
    return 0;
}
