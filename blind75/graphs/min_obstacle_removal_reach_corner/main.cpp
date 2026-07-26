#include <climits>
#include <deque>
#include <iostream>
#include <utility>
#include <vector>

class Solution {

  public:
    int minimumObstacles(std::vector<std::vector<int>> &grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();

        const int target_row = rows - 1;
        const int target_col = cols - 1;

        const int dirs[4][2] = {
            {-1, 0}, // Up
            {1, 0},  // Down
            {0, -1}, // Left
            {0, 1},  // Right
        };

        std::deque<std::pair<int, int>> dq;
        std::vector<std::vector<int>> obstacles_removed(
            rows, std::vector<int>(cols, INT_MAX));
        obstacles_removed[0][0] = grid[0][0];

        dq.push_back({0, 0});

        while (!dq.empty()) {
            const auto [row, col] = dq.front();
            dq.pop_front();

            if (row == target_row && col == target_col) {
                return obstacles_removed[row][col];
            }

            for (const auto &dir : dirs) {
                int new_row = row + dir[0];
                int new_col = col + dir[1];

                // Bounds check
                if ((new_row < 0 || new_row >= rows) ||
                    (new_col < 0 || new_col >= cols))
                    continue;

                // If this cell has a smaller amount of obstacles removed
                //  -> this path was alr explored and is more optimal
                int new_cost =
                    obstacles_removed[row][col] + grid[new_row][new_col];
                if (new_cost >= obstacles_removed[new_row][new_col])
                    continue;

                obstacles_removed[new_row][new_col] = new_cost;

                // If pos to explore has no obstacles then give it priority
                if (grid[new_row][new_col])
                    dq.push_back({new_row, new_col});
                else
                    dq.push_front({new_row, new_col});
            }
        }

        return -1;
    }
};

int main() {
    std::cout << "--- ---\n";
    return 0;
};
