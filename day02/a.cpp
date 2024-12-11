#include <bits/stdc++.h>

bool isSafeReport(const std::vector < int > & levels) {

    bool isIncreasing = levels[1] > levels[0];
    bool isDecreasing = levels[1] < levels[0];

    for (int i = 1; i < levels.size(); ++i) {
        int diff = levels[i] - levels[i - 1];

        if (std::abs(diff) == 0 || std::abs(diff) > 3) {
            return false;
        }

        if (diff > 0 && !isIncreasing) {
            return false;
        }

        if (diff < 0 && !isDecreasing) {
            return false;
        }
    }
    return true;
}

bool passWithDampener(const std::vector < int > & levels) {
    for (int i = 0; i < levels.size(); i++) {
        std::vector temp = levels;
        temp.erase(temp.begin() + i);
        if (isSafeReport(temp)) {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector < std::string > V;
    std::string input;

    // Input
    while (std::getline(std::cin, input)) {
        if (input.empty()) {
            break;
        }
        V.push_back(input);
    }

    int pass = 0;
    int dampenerPass = 0;

    for (const std::string & line: V) {
        std::istringstream stream(line);
        std::vector < int > levels;
        int num;

        while (stream >> num) {
            levels.push_back(num);
        }

        if (isSafeReport(levels)) {
            pass++;
            dampenerPass++;
        } else if (passWithDampener(levels)) {
            dampenerPass++;
        }
    }

    // Output
    std::cout << "Passes: " << pass << "\n";
    std::cout << "Passes with dampener: " << dampenerPass << "\n";

    return 0;
}
