#include <bits/stdc++.h>
#include <utility>

using namespace std;

bool isSeqValid(const vector<pair<int, int>> &pairs, const vector<int> &seq) {
  vector<int> takenPages;
  for (int i = 0; i < seq.size(); i++) {
    for (const auto &pair : pairs) {
      if (seq[i] == pair.first) {
        if (count(takenPages.begin(), takenPages.end(), pair.second) > 0) {
          return false;
        }
      }
    }
    takenPages.push_back(seq[i]);
  }
  return true;
}

void sortSeq(const vector<pair<int, int>> &pairs, vector<int> &seq) {
  int iterator = 0;
  while (!isSeqValid(pairs, seq)) {
    for (int i = 1; i < seq.size(); i++) {
      for (const auto &pair : pairs) {
        if (seq[i] == pair.first) {
          auto it = find(seq.begin(), seq.begin() + i, pair.second);
          if (it != seq.begin() + i) {
            swap(seq[i], seq[i - 1]);
            iterator++;
          }
        }
      }
    }
  }
  cout << "Iterations on each sequence: " << iterator << "\n";
}

int main() {
  vector<pair<int, int>> pairs;
  vector<vector<int>> updates;
  string line;

  // Catch pages
  while (true) {
    getline(cin, line);
    if (line.empty()) {
      break;
    }
    int delimiterPos = line.find('|');

    if (delimiterPos != string::npos) {
      int num1 = stoi(line.substr(0, delimiterPos));
      int num2 = stoi(line.substr(delimiterPos + 1));

      pairs.push_back(make_pair(num1, num2));
    }
  }

  // Catch page sequence
  while (true) {
    getline(cin, line);
    if (line.empty()) {
      break;
    }

    vector<int> currentVector;
    stringstream ss(line);
    string number;

    while (getline(ss, number, ',')) {
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
  cout << "Sum of the middle numbers in ordered lists: " << sum << endl;
  cout << "Sum of the middle numbers in sorted unordered lists: "
       << unorderedSum << endl;
}
