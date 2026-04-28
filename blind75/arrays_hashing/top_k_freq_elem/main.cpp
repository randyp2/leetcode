#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {

  public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k) {

        const size_t N = nums.size();

        // Create our frequency hashmap
        std::unordered_map<int, int> m;
        m.reserve(N);

        // Keep track of max frequency to prevent overalloating uneccessary
        // space in our bucket vector
        int max_frequency = 0;
        for (int num : nums) {
            m[num]++;
            max_frequency = std::max(max_frequency, m[num]);
        }

        std::vector<std::vector<int>> bucket(max_frequency + 1);

        // Store our key value pairs into the bucket
        // Index our bucket based on the value/frequency
        for (const auto &[key, val] : m)
            bucket[val].push_back(key);

        // Construct our answer vector
        std::vector<int> ans;
        ans.reserve(k);
        for (int i = bucket.size() - 1; i > 0; --i) {
            for (int num : bucket[i]) {
                if (ans.size() == k)
                    return ans;
                ans.push_back(num);
            }
        }

        return ans;
    }
};

int main() {
    std::cout << "--- TOP K FREQ ELEMENTS ---\n";
    return 0;
};
