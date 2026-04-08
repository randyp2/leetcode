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

            // Calculate area
            int width = r - l;
            int length = height[r] - height[l];

            int curr_area = width * length;

            max_area = std::max(curr_area, max_area);

            if (height[l] < height[r])
                ++l;
            else
                --r;
        }

        return max_area;
        throw std::runtime_error("Function not implemented yet...");
    }
};

int main() {
    std::cout << "--- CONTAINER W/ MOST WATER ---\n";
    return 0;
}
