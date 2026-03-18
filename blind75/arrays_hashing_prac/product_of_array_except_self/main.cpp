#include <iostream>
#include <stdexcept>
#include <vector>

class Solution {
  public:
    std::vector<int> productExceptSelf(std::vector<int> &nums) {

        const int N = nums.size();
        std::vector<int> res(N);

        // Create prefix
        res[0] = 1;
        for (int i = 1; i < N - 1; ++i)
            res[i] = nums[i - 1] * res[i - 1];

        // Create suffix
        int product = 1;
        for (int i = N - 1; i >= 0; --i) {
            res[i] = res[i] * product;
            product *= nums[i];
        }

        return res;

        throw std::runtime_error("Function not implemented...");
    };
};
int main() {
    std::cout << "--- PRODUCT EXCEPT SELF ---\n";
    return 0;
}
