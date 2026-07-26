#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

class Solution {

  public:
    int swimInWater(std::vector<std::vector<int>> &grid) {
        // Type alias for readablility
        // <cost, row, col>
        using State = std::tuple<int, int, int>;

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

        // --- Create min heap to process the paths w/ smaller costs first
        std::priority_queue<State, std::vector<State>, std::greater<State>> pq;

        std::vector<std::vector<int>> costs(rows,
                                            std::vector<int>(cols, INT_MAX));
        costs[0][0] = grid[0][0];

        pq.push({costs[0][0], 0, 0});

        while (!pq.empty()) {
            const auto [cost, row, col] = pq.top();
            pq.pop();

            if (row == target_row && col == target_col)
                return cost;

            // Iterate through 4 adjacent neighbors
            for (const auto &dir : dirs) {
                int new_row = row + dir[0];
                int new_col = col + dir[1];

                // Bounds check
                if ((new_row < 0 || new_row >= rows) ||
                    (new_col < 0 || new_col >= cols))
                    continue;

                // If new cost will be greater than the existing cost
                // then that path is not optimal -> dont traverse it
                int new_cost = std::max(cost, grid[new_row][new_col]);
                if (new_cost >= costs[new_row][new_col])
                    continue;

                costs[new_row][new_col] = new_cost;
                pq.push({new_cost, new_row, new_col});
            }
        }

        return -1;
    }
};

int main() {
    std::cout << "--- SWIM IN RISING WATER ---\n";
    return 0;
};
