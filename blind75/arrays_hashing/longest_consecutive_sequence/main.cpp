#include <iostream>
#include <stdexcept>
#include <unordered_set>
#include <vector>

/**
 * Goal is to do it in: O(n)
 *
 * Fist idea sorting -> but O(nlogn)
 *
 * Second idea:
 *  - Check array if num + 1 exists
 *   - If yes -> increment count
 *
 *  1st Method)
 *    - Double for loop
 *    - Runtime: O(N^2)
 *  2nd Method)
 *    - Use unordered_set<int>();
 *    for num in nums
 *      while num + 1 is in unordered_set:
 *          count++
 *          num = num + 1;
 *    - Runtime: O(n^2) given Gauss' formula
 *  2nd method optimized)
 *    - Be particular in when to start your count
 *    - Start your counting algorithm at the beginning of eahc interval
 *
 *    i.e.) Given [1,2,3,4,5,10,11,12]
 *    Count Starting 1)
 *      - Checks 2 -> Checks 3 -> Checks 4 -> Checks 5
 *    DONT COUNT 2 UNLIKE LAST METHOD
 *    Count Starting 10)
 *      - Checks 11 -> 12 so on
 */

class Solution {
  public:
    int longestConsecutive(std::vector<int> &nums) {

        const int N = nums.size();

        if (N == 0 || N == 1)
            return N;

        std::unordered_set<int> s;

        // Populate unordered set
        for (int num : nums)
            s.insert(num);

        // Count longest length
        // How to keep track of starting interval?
        //  - if num - 1 is not in set -> starting interval
        int max_len = 0;
        for (int num : nums) {

            int count = 1;
            int next_sequential_num = num + 1;

            // Check for start of interval
            if (s.find(num - 1) != s.end())
                continue;

            while (s.find(next_sequential_num) != s.end()) {
                count++;
                next_sequential_num++;
            }

            // Check for new max length
            if (count > max_len)
                max_len = count;
        }

        return max_len;

        // throw std::runtime_error("Function not implemented yet");
    }
};

int main() {

    std::cout << "================================\n";
    std::cout << "Longest consecutive sequence\n";
    std::cout << "================================\n";

    // Sample tests
    std::vector<int> input1 = {2, 20, 4, 10, 3, 4, 5};
    std::vector<int> input2 = {-1, 0, 1, 2, 3};

    return 0;
}
