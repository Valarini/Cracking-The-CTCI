#include <iostream>

#include <unordered_map>
#include <string>
#include <algorithm>

bool isUnique(std::string str) {
  std::unordered_map<char, bool> table;

  for (char& c : str) {
    if (table.count(c) == 1) {
      return false;
    }
    table[c] = true;
  }

  return true;
}

bool isUniqueSort(std::string str) {
  sort(str.begin(), str.end());

  char prevChar = str[0];

  for (int i = 1; i < str.length(); ++i) {
    if (prevChar == str[i]) {
      return false;
    }
    prevChar = str[i];
  }

  return true;
}

using namespace std;

int main(void) {
  cout << "String \"bbc\" is unique: " << isUniqueSort("bbc") << endl;
  cout << "String \"abc\" is unique: " << isUniqueSort("abc") << endl;
  cout << "String \"132\" is unique: " << isUniqueSort("132") << endl;
  cout << "String \"*!*\" is unique: " << isUniqueSort("*!*") << endl;

  return 0;
}