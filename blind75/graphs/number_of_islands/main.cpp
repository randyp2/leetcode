#include <iostream>
#include <vector>

class Solution {

  public:
    void dfs(int row, int col, auto &grid) {

        // Out of bounds check
        if ((row < 0 || row >= grid.size()) ||
            (col < 0 || col >= grid[0].size()))
            return;

        // If on water dont visit
        if (grid[row][col] == '0')
            return;

        // Process the current cell by marking it as water
        grid[row][col] = '0';

        dfs(row + 1, col, grid); // Up
        dfs(row - 1, col, grid); // Down
        dfs(row, col + 1, grid); // Right
        dfs(row, col - 1, grid); // Left
    }

    int numIslands(std::vector<std::vector<char>> &grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();

        int num_islands = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // If we are on an island traverse the island and mark as
                // visited
                if (grid[i][j] == '1') {
                    ++num_islands;
                    dfs(i, j, grid);
                }
            }
        }

        return num_islands;
    }
};

int main() {
    std::cout << "--- NUMBER OF ISLANDS ---\n";
    return 0;
};
