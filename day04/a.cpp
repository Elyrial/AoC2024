#include <bits/stdc++.h>

int countSubstr(const std::vector<std::string> &grid, const std::string &word) {
    int rows = grid.size();
    int cols = grid[0].size();
    int wordLen = word.size();
    int count = 0;

    // Define directions
    std::vector<std::pair<int, int>> directions = {
        {0, 1},    // right
        {0, -1},   // left
        {1, 0},    // up
        {-1, 0},   // down
        {1, 1},    // down-right
        {-1, -1},  // up-left
        {1, -1},   // down-left
        {-1, 1}    // up-right
    };

    auto isMatch = [&](int startRow, int startCol, int dRow, int dCol) {
        for (int i = 0; i < wordLen; i++) {
            int newRow = startRow + i * dRow;
            int newCol = startCol + i * dCol;
            if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols ||
                grid[newRow][newCol] != word[i]) {
                return false;
            }
        }
        return true;
    };

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (const auto &[dRow, dCol] : directions) {
                if (isMatch(i, j, dRow, dCol)) {
                    count++;
                }
            }
        }
    }
    return count;
}

int countXMAS(const std::vector<std::string> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    for (int i = 1; i < rows - 1; ++i) {
        for (int j = 1; j < cols - 1; ++j) {
            if (grid[i][j] == 'A') {
                if ((i > 0 && i < rows - 1 && j > 0 && j < cols - 1) &&
                    ((grid[i - 1][j - 1] == 'M' && grid[i + 1][j + 1] == 'S') ||
                     (grid[i - 1][j - 1] == 'S' &&
                      grid[i + 1][j + 1] == 'M')) &&
                    ((grid[i + 1][j - 1] == 'M' && grid[i - 1][j + 1] == 'S') ||
                     (grid[i + 1][j - 1] == 'S' &&
                      grid[i - 1][j + 1] == 'M'))) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    std::string subStr = "XMAS";
    std::string input;
    std::vector<std::string> grid;
    while (std::cin >> input) {
        grid.push_back(input);
    }
    int occurences = countSubstr(grid, subStr);
    int XMASOccurences = countXMAS(grid);
    std::cout << "Occurences: " << occurences << std::endl;
    std::cout << "XMAS-Occurences: " << XMASOccurences << std::endl;

    return 0;
}

