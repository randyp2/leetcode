#include <iostream>
#include <stdexcept>
#include <vector>

class Solution {

  public:
    int maxSubArray(std::vector<int> &nums) {

        const int N = nums.size();

        int max_sum = 0;
        for (int num : nums) {
            max_sum += num;
        }

        int l = 0;
        int r = N - 1;

        int curr_sum = max_sum;
        while (l < r) {

            if (l < r) {
                curr_sum -= l;
            } else {
                curr_sum -= r;
            }

            max_sum = std::max(curr_sum, max_sum);
        }

        return max_sum;
    }
};

int main() {
    std::cout << "--- MAX SUBARRAY ---\n";
    return 0;
}
