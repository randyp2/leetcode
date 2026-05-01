#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {

  public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {

        std::unordered_map<int, int> m; // maps number: index
        m.reserve(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            int curr_num = nums[i];
            int diff = target - curr_num;

            // If diff exists in map
            if (m.find(diff) != m.end())
                return {m[diff], i};

            m[curr_num] = i;
        }

        return {};
    }
};

int main() {
    std::cout << "--- TWO SUM ---\n";
    return 0;
};
