#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    /**
     * General notes:
     *
     *  ==== First instinct ====
     *   - Create unordered map that stores the number as key and frequency as
     * value
     *
     *    Ex) [1, 2, 2, 3, 3, 3]
     *    map:
     *        1: 1
     *        2: 2
     *        3: 3
     *   - Issue: How do you return the top k elements?
     *   - Hashmap: stores key value pays randomly no way to sort them based on
     * frequency
     *
     *
     *  === Second Instinct ===
     * Aha moment:
     *  - The frequency is constrained by the size of nums
     *  - Meaning we can create a vector/array whose indexes represent
     * frequencies i.e) [0, 1, 2, 3, 4] -> idx 0 = 0 frequencies
     *
     *  - We can use our hashmap in our first instinct to construct which
     * numbers have which frequency O(n)
     *  - Then we can use that hashmap to map numbers into our frequency list
     *
     *  What if more than one number share the same frequency?
     *   - Sol: Make vector 2d or make it an array
     */

    std::vector<int> topKFrequent(std::vector<int> &nums, int k) {

        std::unordered_map<int, int> m;

        for (int num : nums)
            m[num]++;

        // Frequency vector
        std::vector<std::vector<int>> freq(nums.size() + 1);

        for (auto &[key, val] : m) {
            freq[val].push_back(key);
        }

        std::vector<int> ans;
        int count = 0;
        for (int i = freq.size() - 1; i >= 1; --i) {
            for (int j = 0; j < freq[i].size(); ++j) {
                if (count++ == k)
                    return ans;

                ans.push_back(freq[i][j]);
            }
        }

        return ans;
    }
};

int main() {
    std::cout << " ------------ TOP K FREQUENT ELMENTS ------------ \n";
    return 0;
}
