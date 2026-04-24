#include <iostream>
#include <vector>

class Solution {
  public:
    void dfs(std::vector<std::vector<int>> &image,
             std::vector<std::vector<int>> &dir, int x, int y, int start_color,
             int curr_color) {

        const int ROWS = image.size();
        const int COLS = image[0].size();

        if (x >= ROWS || x < 0)
            return;
        if (y >= COLS || y < 0)
            return;
        if (image[x][y] != start_color)
            return;
        if (start_color == curr_color)
            return;

        image[x][y] = curr_color;

        for (auto &nums : dir) {
            dfs(image, dir, x + nums[0], y + nums[1], start_color, curr_color);
        }
    }

    std::vector<std::vector<int>>
    floodFill(std::vector<std::vector<int>> &image, int sr, int sc, int color) {

        std::vector<std::vector<int>> dir = {
            {0, 1},  // Go right
            {0, -1}, // Go left
            {1, 0},  // Go up
            {-1, 0}  // Go down
        };

        int start_color = image[sr][sc];
        dfs(image, dir, sr, sc, start_color, color);

        return image;
    }
};

int main() {
    std::cout << "--- FLOOD FILL ---\n";
    return 0;
}
