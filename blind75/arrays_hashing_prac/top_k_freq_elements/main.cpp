#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k) {

        // Count frequencies
        std::unordered_map<int, int> freq_map;
        for (int num : nums)
            freq_map[num]++;

        /**
         * Indices act as frequencies
         * Elements are vectors of ints that contain those frequencies
         */
        std::vector<std::vector<int>> freq_buckets;

        for (auto &[key, val] : freq_map)
            freq_buckets.push_back()

                throw std::runtime_error("Function not implemented yet");
    }
};

int main() {
    std::cout << "=== TOP K FREQUENT ELEMENTS ===\n";

    return 0;
}
