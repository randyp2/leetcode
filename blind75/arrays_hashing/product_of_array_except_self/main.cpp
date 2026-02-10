#include <array>
#include <iostream>
#include <stdexcept>
#include <vector>

class Solution {
    /**
     * Input: nums = [1,2,4,6]
     *
     * Output: [48,24,12,8]
     *
     * Construct prefix and suffix araray
     *
     * Runtime to construct: O(n)
     * Prefix - Holds products before i
     * Suffix - Holds suffxi after i
     *
     * Creates extra space O(n)
     *
     *
     * --- By using resultng array as a prefix and suffix holder
     *  we save space
     *
     */

  public:
    std::vector<int> productExceptSelf(std::vector<int> &nums) {

        // const int N = nums.size();
        //
        // // Construct prefix & suffix
        // std::vector<int> prefix(N, 0);
        // prefix[0] = 1;
        //
        // std::vector<int> suffix(N, 0);
        // suffix[N - 1] = 1;
        //
        // // Prefix
        // // Nums = [3, 2, 4, 5]
        // // Prefix = [1, 3, 6, 24]
        // for (int i = 1; i < N; ++i)
        //     prefix[i] = nums[i - 1] * prefix[i - 1];
        //
        // // Suffix
        // // Nums = [3, 2, 4, 5]
        // // Suffix = [40, 20, 5, 1]
        // for (int i = N - 2; i >= 0; --i)
        //     suffix[i] = nums[i + 1] * suffix[i + 1];
        //
        // // Construct answer
        // std::vector<int> res(N);
        //
        // for (int i = 0; i < N; ++i)
        //     res[i] = suffix[i] * prefix[i];
        //
        // return res;

        // =========================
        // What if you can use the result array as your prefix & suffix array
        // =========================
        const int N = nums.size();

        // Store product before idx i into result array
        std::vector<int> res(N);
        res[0] = 1;

        // Nums = [3, 2, 4, 5]
        // res = [1, 3, 6, 24]
        for (int i = 1; i < N; ++i)
            res[i] = nums[i - 1] * res[i - 1];

        // Calculate products after idx i
        // Nums = [3, 2, 4, 5]
        // res = [1, 3, 6, 24]
        int rightProduct = 1;
        for (int i = N - 1; i >= 0; --i) {
            res[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return res;
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

    /* ============= SUFFIX AND PREFFIX ============= */
    std::cout << "------- SUFFIX AND PREFIX -------\n";
    std::cout << "Output 1: \n";
    sol.printAns(sol.productExceptSelf(input1));

    std::cout << "Output 2: \n";
    sol.printAns(sol.productExceptSelf(input2));

    std::cout << "Output 3: \n";
    sol.printAns(sol.productExceptSelf(input3)); // FAIL!! MULTIPEL ZEROES CASE

    return 0;
}
