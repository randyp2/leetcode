#include <climits>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

class Solution {

  public:
    int minimumEffortPath(std::vector<std::vector<int>> &heights) {
        using State = std::tuple<int, int, int>;

        const int ROWS = heights.size();
        const int COLS = heights[0].size();

        const int target_row = ROWS - 1;
        const int target_col = COLS - 1;

        constexpr int dirs[4][2] = {
            {-1, 0}, // Up
            {1, 0},  // Down
            {0, -1}, // Left
            {0, 1}   // Right
        };

        std::priority_queue<State, std::vector<State>, std::greater<State>> pq;

        // Record effort in each path (abs difference)
        std::vector<std::vector<int>> efforts(ROWS,
                                              std::vector<int>(COLS, INT_MAX));

        efforts[0][0] = 0;
        pq.push({efforts[0][0], 0, 0});

        while (!pq.empty()) {
            const auto [effort, r, c] = pq.top();
            pq.pop();

            if (effort > efforts[r][c])
                continue;

            if (r == target_row && c == target_col)
                return effort;

            for (const auto &dir : dirs) {
                int new_r = r + dir[0];
                int new_c = c + dir[1];

                // Out of bounds check
                if ((new_r < 0 || new_r >= ROWS) ||
                    (new_c < 0 || new_c >= COLS))
                    continue;

                int abs_diff = std::abs(heights[r][c] - heights[new_r][new_c]);
                int new_effort = std::max(abs_diff, effort);

                if (new_effort >= efforts[new_r][new_c])
                    continue;

                efforts[new_r][new_c] = new_effort;
                pq.push({new_effort, new_r, new_c});
            }
        }

        return -1;
    }
};

int main() {
    std::cout << "--- ---\n";
    return 0;
};
