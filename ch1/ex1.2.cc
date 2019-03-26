#include <string>
#include <unordered_map>

#include <iostream>

using namespace std;

bool isPermutation(string s1, string s2) {
  if (s1.length() != s2.length()) {
    return false;
  }

  unordered_map<char, int> table;

  // Add all chars of s1 to the hash table
  for (const char& c : s1) {
    if (table.count(c) == 1) {
      table[c]++;
    } else {
      table[c] = 1;
    }
  }

  // Check for same char frequency in the s2
  for (const char& c : s2) {
    if (table.count(c) == 0) {
      return false;
    }

    table[c]--;

    if (table[c] < 0) {
      return false;
    }
  }

  return true;
}

int main(void) {

  cout << "\"zvab\" is permutation of \"1zva\": " << isPermutation("zvab", "1zva") << endl;
  cout << "\"abfg\" is permutation of \"fgba\": " << isPermutation("abfg", "fgba") << endl;
  cout << "\"1234\" is permutation of \"5612\": " << isPermutation("1234", "5612") << endl;
  cout << "\"1a2b\" is permutation of \"a1b2\": " << isPermutation("1a2b", "a1b2") << endl;
  cout << "\"bb12\" is permutation of \"1b2b\": " << isPermutation("bb12", "1b2b") << endl;
  cout << "\"baad\" is permutation of \"badd\": " << isPermutation("baad", "badd") << endl;
  cout << "\"1a2\" is permutation of \"a1b2\": " << isPermutation("1a2", "a1b2") << endl;
  cout << "\"\" is permutation of \"a1b2\": " << isPermutation("", "a1b2") << endl;
  cout << "\"\" is permutation of \"\": " << isPermutation("", "") << endl;

  return 0;
}