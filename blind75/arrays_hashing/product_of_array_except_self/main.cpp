#include <iostream>
#include <stdexcept>
#include <vector>

class Solution {
    /**
     * Input: nums = [1,2,4,6]
     *
     * Output: [48,24,12,8]
     *
     *
     *
     */

  public:
    std::vector<int> productExceptSelf(std::vector<int> &nums) {

        throw std::runtime_error("Function not implemented");
    }

    // Use division operator
    // output[i] = (0 * 1 * ... * i * i + 1 * ... n)/i
    // Runtime: O(n)
    // FAILS MULTIPLE ZEROES
    std::vector<int> productExceptSelfDivision(std::vector<int> &nums) {
        const int N = nums.size();
        std::vector<int> ans(N, 0);

        // Calculate one time product
        int product_of_list = 1;
        int product_of_list_zero = 1;
        for (int num : nums) {
            product_of_list *= num;
            product_of_list_zero *= (num == 0 ? 1 : num);
        }

        // Apply formula
        for (int i = 0; i < N; ++i)
            if (nums[i] == 0) {
                ans[i] = product_of_list_zero;
            } else {
                ans[i] = product_of_list / nums[i];
            }

        return ans;
    }

    // Iterate the array twice for each num and calculate the productExceptSelf
    // Runtime: O(n^2)
    std::vector<int> producetExceptSelfBruteForce(std::vector<int> &nums) {

        const int n = nums.size();

        std::vector<int> ans(n, 0);

        for (int i = 0; i < nums.size(); ++i) {

            int product = 1;
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j)
                    continue;

                product *= nums[j];
            }

            ans[i] = product;
        }

        return ans;
    }

    // Helper
    void printAns(const std::vector<int> &ans) {
        for (int num : ans) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    std::cout << "================================\n";
    std::cout << "Product of array except itself\n";
    std::cout << "================================\n";

    // Sample tests
    std::vector<int> input1 = {1, 2, 4, 6};
    std::vector<int> input2 = {-1, 0, 1, 2, 3};
    std::vector<int> input3 = {0, 0, 2, 3};

    /* ============= BRUTE FORCE ============= */
    std::cout << "------- BRUTE FORCE -------\n";
    Solution sol;
    std::cout << "Output 1: \n";
    sol.printAns(sol.producetExceptSelfBruteForce(input1));

    std::cout << "Output 2: \n";
    sol.printAns(sol.producetExceptSelfBruteForce(input2));

    /* ============= DIVISION OPERATOR ============= */
    std::cout << "------- DIVISION OPERATOR -------\n";
    std::cout << "Output 1: \n";
    sol.printAns(sol.productExceptSelfDivision(input1));

    std::cout << "Output 2: \n";
    sol.printAns(sol.productExceptSelfDivision(input2));

    std::cout << "Output 3: \n";
    sol.printAns(
        sol.productExceptSelfDivision(input3)); // FAIL!! MULTIPEL ZEROES CASE

    return 0;
}
