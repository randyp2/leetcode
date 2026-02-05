#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    /**
     * Bucket:
     *
     * [freq] -> [numbers_with_frequency]
     */
    std::vector<int> topKFrequent(std::vector<int> &nums, int k) {

        if (nums.size() == 1)
            return {nums[0]};

        // Initialize unordered_map
        // numbers -> frequency
        std::unordered_map<int, int> m;
        for (int num : nums)
            m[num]++;

        int num_rows = nums.size() + 1; // 0 doesnt count as freq
        std::vector<std::vector<int>> bucket(num_rows);

        for (const auto &[key, val] : m) {
            bucket[val].push_back(key);
        }

        std::vector<int> ans;
        ans.reserve(k); // Preallocate/reserve memory
        for (int i = num_rows - 2; i >= 1 && ans.size() < k; --i) {
            for (int num : bucket[i]) {
                if (ans.size() == k)
                    break;
                ans.push_back(num);
            }
        }

        return ans;
    }

    void printAns(std::vector<int> ans) {
        for (int num : ans) {
            std::cout << num << " ";
        }
    }
};

int main() {

    std::cout
        << " ------------------- TOP K FREQUENT ELEMENTS ------------------- "
        << std::endl;

    Solution sol;
    std::vector<int> input1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;

    std::cout << "Output1: " << std::endl;
    sol.printAns(sol.topKFrequent(input1, 2));
    std::cout << "\n";

    return 0;
}
