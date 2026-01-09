#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {

  public:
    // Time complexity: O(nlogn) Space complexity: O(1)
    // bool containsDuplicate(std::vector<int> &nums) {
    //
    //     if (nums.size() == 1)
    //         return false;
    //
    //     // Sort nums
    //     std::sort(nums.begin(), nums.end());
    //
    //     // Iterate & Compare adjacent values
    //     for (int i = 0; i < nums.size() - 1; ++i) {
    //         if (nums[i] == nums[i + 1])
    //             return true;
    //     }
    //
    //     return false;
    // }

    bool containsDuplicate(std::vector<int> &nums) {

        if (nums.size() == 1)
            return false;

        std::unordered_set<int> s;

        for (int num : nums) {
            if (s.find(num) == s.end()) {
                s.insert(num);
            } else {
                return true;
            }
        }

        return false;
    }
};

int main() {

    std::vector<int> test1 = {1, 2, 3, 1};
    std::vector<int> test2 = {1, 2, 3, 4};
    std::vector<int> test3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    Solution sol;

    std::cout << "Contains duplicate: " << sol.containsDuplicate(test1)
              << std::endl;
    std::cout << "Contains duplicate test2: " << sol.containsDuplicate(test2)
              << std::endl;
    std::cout << "Contains duplicate test3: " << sol.containsDuplicate(test3)
              << std::endl;

    return 0;
}
