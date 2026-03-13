#include <ios>
#include <iostream>
#include <stdexcept>
#include <vector>

class Solution {

  public:
    std::vector<int> productExceptSelf(std::vector<int> &nums) {

        const int N = nums.size();
        std::vector<int> res(N);

        // Do prefix
        res[0] = 1;
        for (int i = 1; i < N; ++i)
            res[i] = res[i - 1] * nums[i - 1];

        // Suffix in the same resulting array
        int right_product = 1;
        for (int i = N - 1; i >= 0; --i) {
            res[i] *= right_product;
            right_product *= nums[i];
        }

        return res;
    }
};

int main() {
    std::cout << "--- PRODUCT OF ARRAY EXCEPT SELF ---\n";
    return 0;
}
