#include <cassert>
#include <iostream>
#include <vector>

class Solution {

  public:
    std::vector<int> productExceptSelf2(std::vector<int> &nums) {
        const size_t N = nums.size();

        // Build the left_product within the answer array
        std::vector<int> ans(N);
        ans[0] = 1;
        for (size_t i = 1; i < N; ++i)
            ans[i] = ans[i - 1] * nums[i - 1];

        // Build the right_product in place of the answer array
        int rhs_product = nums[N - 1];
        for (int i = N - 2; i >= 0; --i) {
            ans[i] *= rhs_product;
            rhs_product *= nums[i];
        }

        return ans;
    }

    std::vector<int> productExceptSelf(std::vector<int> &nums) {
        const size_t N = nums.size();

        // Build the left product
        std::vector<int> left_product(N);
        left_product[0] = 1;
        for (size_t i = 1; i < N; ++i) {
            left_product[i] = left_product[i - 1] * nums[i - 1];
        }

        // Build the right product
        std::vector<int> right_product(N);
        right_product[N - 1] = 1;
        for (int i = N - 2; i >= 0; --i) {
            std::cout << "i: " << i << " of N: " << N << "\n";
            right_product[i] = right_product[i + 1] * nums[i + 1];
        }

        // Combine the two products to get the answer product
        std::vector<int> ans(N);
        for (size_t i = 0; i < N; ++i) {
            ans[i] = left_product[i] * right_product[i];
        }

        return ans;
    }
};

int main() {
    std::cout << "--- PRODUCT EXCEPT SELF ---\n";
    std::vector<int> input01 = {1, 2, 4, 6};
    std::vector<int> output01 = {48, 24, 12, 8};

    Solution sol;
    std::vector<int> actualOutput = sol.productExceptSelf2(input01);
    for (int num : actualOutput)
        std::cout << num << " ";

    std::cout << "\n";

    assert(actualOutput == output01);

    return 0;
};
