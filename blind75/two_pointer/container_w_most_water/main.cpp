#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

class Solution {

  public:
    int maxArea(std::vector<int> &heights) {

        const int N = heights.size();

        int l = 0;
        int r = N - 1;

        int ans = INT_MIN;
        while (l < r) {
            int curr_area = std::min(heights[l], heights[r]) * (r - l);

            ans = std::max(ans, curr_area);

            if (heights[l] < heights[r])
                ++l;
            else
                --r;
        }

        return ans;
    }
};

int main() {
    std::cout << "--- CONTAINER W MOST WATER ---\n";
    return 0;
};
