#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {

  public:
    std::vector<std::vector<std::string>>
    groupAnagramsOptimized(std::vector<std::string> &strs) {

        const size_t N = strs.size();

        // Maps a frequency array represented as a string to a vector or
        // strings that contain the same frequency array
        std::unordered_map<std::string, std::vector<std::string>> m;
        m.reserve(N);

        for (const auto &str : strs) {

            const std::string copy = str;
            // sort is higly optmized for short strings
            // - Using insertion sort for small input
            // - Fast considering that a whole array could fit in a L1 cache
            //      - We have a lot of cache hits, no cache misses
            std::sort(copy.begin(), copy.end());

            // Sort eliminates the need to create a hashable for loop

            // Insert into our hashmap
            m[copy].push_back(str);
        }

        // Construct our 2d answer vector
        std::vector<std::vector<std::string>> ans;
        ans.reserve(N);
        for (const auto &[_key, val] : m)
            ans.push_back(std::move(val));

        return ans;
    }

    // Standard approach
    std::vector<std::vector<std::string>>
    groupAnagrams(std::vector<std::string> &strs) {

        const size_t N = strs.size();

        // Maps a frequency array represented as a string to a vector or
        // strings that contain the same frequency array
        std::unordered_map<std::string, std::vector<std::string>> m;
        m.reserve(N);

        for (const auto &str : strs) {

            // Find the frquency aray
            std::array<int, 26> freq_array{0};

            for (char c : str)
                freq_array[c - 'a']++;

            // Convert to hashable value
            std::string key = "";
            for (int num : freq_array) {
                key += std::to_string(num) + "#";
            }

            // Insert into our hashmap
            m[key].push_back(str);
        }

        // Construct our 2d answer vector
        std::vector<std::vector<std::string>> ans;
        for (const auto &[_key, val] : m)
            ans.push_back(val);

        return ans;
    }
};

int main() {
    std::cout << "--- CONTAINS DUPLICATE ---\n";
    return 0;
};
