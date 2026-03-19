#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        const int N = nums.size();
        std::unordered_map<int, int> m;

        for (int i = 0; i < N; ++i) {
            int curr_num = nums[i];
            int diff = target - curr_num;

            if (m.find(diff) != m.end())
                return {m[diff], i};

            m[curr_num] = i;
        }

        return {};

        throw std::runtime_error("Function not implemented...");
    }
};

int main() {
    std::cout << "---TWO SUM---\n";

    Solution sol;

    std::vector<int> test1 = {2, 7, 11, 15};
    std::vector<int> test2 = {3, 2, 4};
    std::vector<int> test3 = {3, 3};

    std::cout << "Test 1: " << (sol.twoSum(test1, 9))[0] << ", "
              << (sol.twoSum(test1, 9))[1] << std::endl;
    std::cout << "Test 2: " << (sol.twoSum(test2, 6))[0] << ", "
              << (sol.twoSum(test2, 6))[1] << std::endl;
    std::cout << "Test 3: " << (sol.twoSum(test3, 6))[0] << ", "
              << (sol.twoSum(test3, 3))[1] << std::endl;

    return 0;
    return 0;
}
