#include <iostream>
#include <queue>
#include <utility>
#include <vector>

class Solution {

  public:
    int shortestPath(std::vector<std::vector<int>> &grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int row_target = rows - 1;
        int col_target = cols - 1;

        int dirs[4][2] = {
            {-1, 0}, // Going up
            {1, 0},  // Going down
            {0, -1}, // Going left
            {0, 1}   // Going right
        };

        /*
            Hold the following:
             - (r,c): the new position to move at
             - k: remaining budget left to remove an obstacle
             - s: amount of steps we have taken (return value)

            Use bfs to guarantee shortest path
         */
        struct State {
            std::pair<int, int> pos; // Position to move to
            int curr_steps;
            int remaining_k;
        };

        /*
            Visited array will keep track of the remaning k
             - this is a safety guard when we need to remove more obstacles
             - dont visit a path if new_remaining_k <= visited[row][col]
        */
        std::vector<std::vector<int>> visited(rows, std::vector<int>(cols, -1));

        std::queue<State> q;
        q.push(State{.pos = {0, 0}, .curr_steps = 0, .remaining_k = k});

        while (!q.empty()) {
            State curr_state = q.front();
            q.pop();

            const auto &[pos, steps, remaining_k] = curr_state;
            if (pos.first == row_target && pos.second == col_target)
                return steps;

            for (const auto &dir : dirs) {
                int new_row = pos.first + dir[0];
                int new_col = pos.second + dir[1];

                // Valid bounds
                if ((new_row >= 0 && new_row < rows) &&
                    (new_col >= 0 && new_col < cols)) {
                    int new_remaining_k = remaining_k - grid[new_row][new_col];
                    int new_steps = steps + 1;

                    // Proccess a cell iff we have a higher reamining k
                    if (visited[new_row][new_col] < new_remaining_k) {
                        visited[new_row][new_col] = new_remaining_k;
                        q.push(State{.pos = {new_row, new_col},
                                     .curr_steps = new_steps,
                                     .remaining_k = new_remaining_k});
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    std::cout << "--- SHORTEST PATH W/ OBSTACLES ---\n";
    return 0;
};
