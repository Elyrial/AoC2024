#include <bits/stdc++.h>

std::vector < int > calculateSum(const std::string & memory) {
    std::regex mulPattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
    std::regex doPattern(R"(do\(\))");
    std::regex dontPattern(R"(don't\(\))");

    std::smatch match;
    std::vector < int > result;

    int firstPartTotal = 0, secondPartTotal = 0;
    auto it = memory.cbegin();

    // Part 1
    while (std::regex_search(it, memory.cend(), match, mulPattern)) {
        int x = std::stoi(match[1].str());
        int y = std::stoi(match[2].str());
        firstPartTotal += x * y;
        it = match.suffix().first;
    }
    result.push_back(firstPartTotal);

    // Part 2
    it = memory.cbegin(); // Reset iterator
    bool isMulEnabled = true;

    while (it != memory.cend()) {
        if (std::regex_search(it, memory.cend(), match, mulPattern) &&
            match.position() == 0) {
            if (isMulEnabled) {
                int x = std::stoi(match[1]);
                int y = std::stoi(match[2]);
                secondPartTotal += x * y;
            }
            it += match.length();
        } else if (std::regex_search(it, memory.cend(), match, doPattern) && match.position() == 0) {
            isMulEnabled = true;
            it += match.length();
        } else if (std::regex_search(it, memory.cend(), match, dontPattern) && match.position() == 0) {
            isMulEnabled = false;
            it += match.length();
        } else {
            ++it;
        }
    }
    result.push_back(secondPartTotal);
    return result;
}

int main() {
    std::string memory, line;
    while (std::getline(std::cin, line)) {
        memory += line;
    }
    std::vector < int > result = calculateSum(memory);
    std::cout << "Part 1: " << result[0] << "\n";
    std::cout << "Part 2: " << result[1] << "\n";
    return 0;
}
