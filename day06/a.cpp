#include <bits/stdc++.h>

using namespace std;

bool isOutOfBounds(int x, int y, int rows, int cols) {
  return x < 0 || x >= rows || y < 0 || y >= cols;
}

int main() {
  // Input map
  vector<string> map;
  string row;
  while (std::cin >> row) {
    map.push_back(row);
  }

  int rows = map.size();
  int cols = map[0].size();

  vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  char directionSymbols[] = {'^', '>', 'v', '<'};
  int initialDirectionIndex;

  // Find player position and initial direction
  int x, y;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (map[i][j] == '^' || map[i][j] == '>' || map[i][j] == 'v' ||
          map[i][j] == '<') {
        x = i;
        y = j;
      }
    }
  }

  char direction = '^';

  std::cout << x << " " << y << std::endl;

  for (const auto &row : map) {
    std::cout << row << std::endl;
  }
  return 0;
}
