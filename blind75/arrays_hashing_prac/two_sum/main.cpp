#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {

        const int N = nums.size();
        std::unordered_map<int, int> m;

        for (int i = 0; i < N; ++i) {
            int diff = target - nums[i];

            if (m.find(diff) == m.end())
                m[nums[i]] = i;
            else
                return {m[diff], i};
        }

        return {};
    }
};

int main() {
    std::cout << "--- TWO SUM ---\n";

    return 0;
}
