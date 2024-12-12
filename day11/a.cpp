#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<long int, long int>
blinkArrangement(std::unordered_map<long int, long int> &stones) {
  std::unordered_map<long int, long int> newStones;

  for (const auto &[stone, count] : stones) {
    std::string numStr = std::to_string(stone);
    long int strLen = numStr.length();

    if (stone == 0) {
      newStones[1] += count;
    } else if (strLen % 2 == 0) {
      long int mid = strLen / 2;
      long int part1 = std::stoi(numStr.substr(0, mid));
      long int part2 = std::stoi(numStr.substr(mid));

      newStones[part1] += count;
      newStones[part2] += count;
    } else {
      newStones[stone * 2024] += count;
    }
  }
  return newStones;
}

int main() {
  std::unordered_map<long int, long int> map;
  long int input;

  while (std::cin >> input) {
    map[input]++;
  }

  for (int i = 0; i < 75; i++) {
    map = blinkArrangement(map);
  }

  long int totalSize = 0;
  for (const auto &[val, count] : map) {
    totalSize += count;
  }

  std::cout << totalSize << std::endl;

  return 0;
}
