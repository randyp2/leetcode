#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    int longestConsecutive(std::vector<int> &nums) {

        const int N = nums.size();

        std::unordered_set<int> s;

        // Insert all numbers in the set
        // - Use set to remove duplicates
        for (int num : nums)
            s.insert(num);

        // for each num:
        //     determine if num - 1 exists (determine starting of range)
        //     if exists
        //          skip
        //     else
        //        begin counting
        int max = 0;
        for (int num : s) {

            if (s.find(num - 1) != s.end())
                continue;

            // Beginning of the range
            int next_num = num + 1;
            int curr_length = 1;
            while (s.find(next_num++) != s.end())
                ++curr_length;

            max = std::max(curr_length, max);
        }

        return max;
    };
};

int main() {
    std::cout << "--- LONGEST CONSECUITVE SEQUENCE ---\n";
    return 0;
}
