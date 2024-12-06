#include <bits/stdc++.h>

int main() {
  // Input map
  std::vector<std::string> map;
  std::string row;
  while (std::cin >> row) {
    map.push_back(row);
  }

  // Find player position and initial direction
  int x, y;
  for (int i = 0; i < map.size(); i++) {
    for (int j = 0; j < map[j].length(); j++) {
      if (map[i][j] == '^') {
        x = j;
        y = map.size() - i - 1;
        break;
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
