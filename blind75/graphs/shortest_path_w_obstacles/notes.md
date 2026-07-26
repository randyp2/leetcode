# BFS traversal

```cpp
void bfs(const std::vector<std::vector<int>>& grid, int startRow, int startCol) {
    if (grid.empty() || grid[0].empty())
        return;

    int rows = grid.size();
    int cols = grid[0].size();

    if (startRow < 0 || startRow >= rows ||
        startCol < 0 || startCol >= cols) {
        return;
    }

    std::vector<std::vector<bool>> visited(
        rows,
        std::vector<bool>(cols, false)
    );

    // Up, down, left, right
    const int directions[4][2] = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    std::queue<std::pair<int, int>> q;

    q.push({startRow, startCol});
    visited[startRow][startCol] = true;

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        std::cout << grid[row][col] << ' ';

        for (const auto& direction : directions) {
            int newRow = row + direction[0];
            int newCol = col + direction[1];

            bool inBounds =
                newRow >= 0 && newRow < rows &&
                newCol >= 0 && newCol < cols;

            if (inBounds && !visited[newRow][newCol]) {
                visited[newRow][newCol] = true;
                q.push({newRow, newCol});
            }
        }
    }
}
```
---
# DFS traveral

```cpp
void dfsHelper(
    const std::vector<std::vector<int>>& grid,
    int row,
    int col,
    std::vector<std::vector<bool>>& visited
) {
    int rows = grid.size();
    int cols = grid[0].size();

    bool outOfBounds =
        row < 0 || row >= rows ||
        col < 0 || col >= cols;

    if (outOfBounds || visited[row][col])
        return;

    visited[row][col] = true;

    std::cout << grid[row][col] << ' ';

    // Up
    dfsHelper(grid, row - 1, col, visited);

    // Down
    dfsHelper(grid, row + 1, col, visited);

    // Left
    dfsHelper(grid, row, col - 1, visited);

    // Right
    dfsHelper(grid, row, col + 1, visited);
}

void dfs(const std::vector<std::vector<int>>& grid, int startRow, int startCol) {
    if (grid.empty() || grid[0].empty())
        return;

    int rows = grid.size();
    int cols = grid[0].size();

    if (startRow < 0 || startRow >= rows ||
        startCol < 0 || startCol >= cols) {
        return;
    }

    std::vector<std::vector<bool>> visited(
        rows,
        std::vector<bool>(cols, false)
    );

    dfsHelper(grid, startRow, startCol, visited);
}
```
