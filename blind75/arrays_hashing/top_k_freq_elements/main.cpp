#include <exception>
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <vector>

/**
 *
 * IMPLEMENTATION PLAN
 *
 * NAIVE SOLUTION:
 *      - Create hashmap to store frequencies of each number
 *      - Iterate hashmap and populate a result vector
 *      - Sort vector in descending order
 *      - Only return the frist k elements
 *
 *      - Runtime: O(nlogn)
 *      - Space complexity: O(n)
 *
 * NOTES:
 *      - Partial ordering so sorting entire list doesnt work here
 *      - !!!!! Frequencies are bounded by n !!!!!
 *          - This means that we can only need to iterate n times
 *          - We can use frequencies as indexing
 *
 * SOLUTION:
 *      - Count frequencies of each element
 *      - Use frequncies as an index
 *          - i.e. [7, 7] -> 7 appears 2 times -> [ ,7]
 *      - More than one element can share the same frequencies so use a 2d
 * vector
 *
 *     Ex) [1, 1, 1, 2, 2, 3]
 *
 *      [
 *          [3] -> index 1
 *          [2, 2] -> index 2
 *          [1, 1, 1] -> index 3
 *      ]
 */

class Solution {

  public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k) {

        if (nums.size() == 1)
            return {nums[0]};

        int num_rows = nums.size() + 1;
        std::vector<std::vector<int>> bucket(num_rows);

        // -- Count frquencies using hashmap
        std::unordered_map<int, int> m; // num -> frequency
        for (int num : nums)
            m[num]++;

        // -- Iterate through hashmap and store it in bucket
        for (const auto &[key, val] : m) {
            bucket[val].push_back(key);
        }

        // -- Return the last k elements in the last k vectors
        std::vector<int> ans;
        ans.reserve(k);
        for (int i = num_rows - 1; i >= 1 && ans.size() < k; --i) {
            for (int num : bucket[i]) {
                if (ans.size() == k)
                    break;

                ans.push_back(num);
            }
        }
        return ans;
    }

    void printAns(std::vector<int>) {}
};

int main() {

    std::cout
        << " ------------------- TOP K FREQUENT ELEMENTS ------------------- "
        << std::endl;

    Solution sol;
    std::vector<int> input1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;

    std::cout << "Output1: " << std::endl;

    return 0;
}
