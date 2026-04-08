#include <iostream>
#include <vector>

class Solution {
  public:
    std::vector<int> productExceptSelf(std::vector<int> &nums) {

        const int N = nums.size();

        std::vector<int> res(N, 1);

        // Build products to the left of i
        for (int i = 1; i < N; ++i)
            res[i] = res[i - 1] * nums[i - 1];

        // Build products to the right of i
        int product = 1;
        for (int i = N - 1; i >= 0; --i) {
            res[i] *= product;
            product *= nums[i];
        }

        return res;
    }
};

int main() {
    std::cout << "--- PRODUCT OF ARRAY EXCEPT SELF ---\n";
    return 0;
}
