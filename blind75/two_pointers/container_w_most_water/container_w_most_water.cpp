#include <algorithm>
#include <climits>
#include <iostream>
#include <stdexcept>
#include <vector>

class Solution {

  public:
    int maxArea(std::vector<int> &height) {

        const int N = height.size();

        int l = 0;
        int r = N - 1;
        int max_area = 0;

        while (l < r) {
            // Calculate new area
            int curr_area = (r - l) * (std::min(height[r], height[l]));

            // Assign new max
            max_area = std::max(curr_area, max_area);

            // Determine shift
            if (height[l] <= height[r])
                ++l;
            else
                --r;
        }

        return max_area;

        throw std::runtime_error("Function not implemented yet...");
    }
};

int main() {
    std::cout << "--- CONTAINER WITH MOST WATER ---\n";

    Solution sol;

    std::vector<int> input1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::vector<int> input2 = {1, 1, 1};
    std::vector<int> input3 = {0, 1, 1};
    int output1 = sol.maxArea(input1);
    int output2 = sol.maxArea(input2);
    int output3 = sol.maxArea(input3);

    std::cout << "Output1: " << output1 << "\n";
    std::cout << "Output2: " << output2 << "\n";
    std::cout << "Output3: " << output3 << "\n";

    return 0;
}
