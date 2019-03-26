#include <string>
#include <iostream>

using namespace std;

string compress(string& str) {
  string result;
  char currChar = '*';
  int countChar = 0;

  for (const char& c : str) {
    if (c != currChar) {
      if (countChar > 0) {
        result.push_back(currChar);
        result.append(to_string(countChar));
      }
      currChar = c;
      countChar = 1;
    } else {
      countChar++;
    }
  }
  result.push_back(currChar);
  result.append(to_string(countChar));

  return (result.length() < str.length()) ? result : str;
}

int main(void) {
  string target1, target2;

  cin >> target1;
  cout << "Compressed: " << compress(target1) << endl;

  return 0;
}