#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {

  public:
    bool hasDuplicate2(std::vector<int> &nums) {
        const size_t N = nums.size();

        std::sort(nums.begin(), nums.end());

        for (size_t i = 1; i < N; ++i) {
            if (nums[i] == nums[i - 1])
                return true;
        }

        return false;
    }
    bool hasDuplicate(std::vector<int> &nums) {

        const std::size_t N = nums.size();

        std::unordered_set<int> s;
        s.reserve(N); // Allocates space ahead of time w/o default initiliazing

        // Loop over elements in nums
        // Check if it exists else insert
        for (int num : nums) {
            auto [_it, inserted] = s.insert(num);
            if (!inserted)
                return true;
        }

        return false;
    }
};

int main() {
    std::cout << "--- CONTAINS DUPLICATE ---\n";
    return 0;
};
