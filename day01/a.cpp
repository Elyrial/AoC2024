#include <bits/stdc++.h>

int main() {
    int l, r;
    std::vector < int > leftList, rightList;

    // Input
    while (std::cin >> l >> r) {
        leftList.push_back(l);
        rightList.push_back(r);
    }

    // Sort lists
    std::sort(leftList.begin(), leftList.end());
    std::sort(rightList.begin(), rightList.end());

    // Part 1
    int sum1 = 0;
    for (int i = 0; i < leftList.size(); i++) {
        sum1 += std::abs(leftList[i] - rightList[i]);
    }

    // Part 2
    int sum2 = 0;
    for (int i = 0; i < leftList.size(); i++) {
        int count = 0;
        for (int number: rightList) {
            if (number == leftList[i]) {
                count++;
            }
        }
        sum2 += leftList[i] * count;
    }

    // Output
    std::cout << "Total list distance: " << sum1 << "\n";
    std::cout << "Similarity score: " << sum2 << "\n";

    return 0;
}
