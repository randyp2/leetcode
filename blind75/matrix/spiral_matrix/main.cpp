#include <iostream>
#include <vector>

class Solution {

  public:
    // Enclose boundaries on every turn
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {

        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        std::vector<int> res(ROWS * COLS, 0);

        // Boundary indicesc
        int top = 0, bottom = ROWS - 1;
        int left = 0, right = COLS - 1;

        // Continue until boundaries meet
        int idx = 0;
        while (top <= bottom && left <= right) {

            // Traverse top row and bring top border down
            for (int i = left; i <= right; ++i)
                res[idx++] = matrix[top][i];

            ++top;

            // Traverse right col
            for (int i = top; i <= bottom; ++i)
                res[idx++] = matrix[i][right];

            --right;

            // Traverse bottom row
            if (top <= bottom) {
                for (int i = right; i >= left; --i)
                    res[idx++] = matrix[bottom][i];

                --bottom;
            }

            // Traverse left row
            if (left <= right) {
                for (int i = bottom; i >= top; --i)
                    res[idx++] = matrix[i][left];

                ++left;
            }
        }

        return res;
    }
};

int main() {
    std::cout << "--- ---\n";
    return 0;
};
