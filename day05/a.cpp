#include <bits/stdc++.h>

bool isSeqValid(const std::vector<std::pair<int, int>> &pairs,
                const std::vector<int> &seq) {
    std::vector<int> takenPages;
    for (int i = 0; i < seq.size(); i++) {
        for (const auto &pair : pairs) {
            if (seq[i] == pair.first) {
                if (count(takenPages.begin(), takenPages.end(), pair.second) >
                    0) {
                    return false;
                }
            }
        }
        takenPages.push_back(seq[i]);
    }
    return true;
}

void sortSeq(const std::vector<std::pair<int, int>> &pairs,
             std::vector<int> &seq) {
    int iterator = 0;
    while (!isSeqValid(pairs, seq)) {
        for (int i = 1; i < seq.size(); i++) {
            for (const auto &pair : pairs) {
                if (seq[i] == pair.first) {
                    auto it = find(seq.begin(), seq.begin() + i, pair.second);
                    if (it != seq.begin() + i) {
                        std::swap(seq[i], seq[i - 1]);
                        iterator++;
                    }
                }
            }
        }
    }
}

int main() {
    std::vector<std::pair<int, int>> pairs;
    std::vector<std::vector<int>> updates;
    std::string line;

    // Catch pages
    while (true) {
        std::getline(std::cin, line);
        if (line.empty()) {
            break;
        }
        int delimiterPos = line.find('|');

        if (delimiterPos != std::string::npos) {
            int num1 = stoi(line.substr(0, delimiterPos));
            int num2 = stoi(line.substr(delimiterPos + 1));

            pairs.push_back(std::make_pair(num1, num2));
        }
    }

    // Catch page sequence
    while (true) {
        std::getline(std::cin, line);
        if (line.empty()) {
            break;
        }

        std::vector<int> currentVector;
        std::stringstream ss(line);
        std::string number;

        while (std::getline(ss, number, ',')) {
            currentVector.push_back(stoi(number));
        }
        updates.push_back(currentVector);
    }

    int sum = 0;
    int unorderedSum = 0;

    for (auto &update : updates) {
        if (isSeqValid(pairs, update)) {
            sum += update[update.size() / 2];
        } else {
            sortSeq(pairs, update);
            unorderedSum += update[update.size() / 2];
        }
    }
    std::cout << "Sum of the middle numbers in ordered lists: " << sum
              << std::endl;
    std::cout << "Sum of the middle numbers in sorted unordered lists: "
              << unorderedSum << std::endl;
}
