#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
    /**
     *
     * RUNTIMES
     *  - (SORTING OPTION): O(nlogn)
     *  - (UNORDERD SET): O(n)
     *
     * Why on leetcode sorting option runs after?
     *  - Because of the overhead using an unorderd_set
     *  - Sorting uses just a vector that utilizes spatial locality
     *  - unorderd_set involves pointer chasing, rehashing and so on
     */
  public:
    // Time complexity: O(nlogn) Space complexity: O(1)
    bool containsDuplicate2(std::vector<int> &nums) {

        if (nums.size() == 1)
            return false;

        // Sort nums
        std::sort(nums.begin(), nums.end());

        // Iterate & Compare adjacent values
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1])
                return true;
        }

        return false;
    }

    bool containsDuplicate(std::vector<int> &nums) {

        const int N = nums.size();
        std::unordered_set<int> s;
        s.reserve(N); // Reserve space to avoid rehashing due to load factor

        for (int num : nums) {
            // Returns pair:
            //  * first -> iterator pionting to inserted number
            //  * second -> boolean: false -> num already exists, true -> num
            //  doesn't exist
            auto [it, inserted] = s.insert(num); // use structured binding

            if (!inserted)
                return true;
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
