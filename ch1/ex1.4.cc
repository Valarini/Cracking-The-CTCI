#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

bool isPaliPerm(string& str) {
  unordered_map<char, int> charFreq;

  for (const char c : str) {
    if (c != ' ') {
      charFreq[tolower(c)]++;
    }
  }

  int oddFreqCount = 0;

  for (const auto& vk : charFreq) {
    if (vk.second % 2 != 0) {
      oddFreqCount++;
    }
  }

  return oddFreqCount < 2;
}

int main(void) {
  string target;

  getline(cin, target);
  cout << "The string '" << target << "' is pali perm: ";
  cout << isPaliPerm(target) << endl;

  return 0;
}