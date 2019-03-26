#include <string>
#include <cmath>
#include <iostream>

using namespace std;

bool hasOnlyOneExchange(string& sa, string& sb) {
  int diffCount = 0;

  for (int i = 0; i < sa.length(); ++i) {
    if (sa[i] != sb[i]) {
      diffCount++;
    }
  }

  return diffCount < 2;
}

bool hasOnlyOneRemoveAdd(string& sa, string& sb) {
  int diffCount = 0;
  int ia, ib;

  for (ia = 0, ib = 0; ia < sa.length() && ib < sb.length(); ++ia, ++ib) {
    if (sa[ia] != sb[ib]) {
      diffCount++;
      bool isAInc = (ia + 1) < sa.length();
      bool isBInc = (ib + 1) < sb.length();

      if (isAInc && sa[ia+1] == sb[ib]) {
        ia++;
      } else if (isBInc && sb[ib+1] == sa[ia]) {
        ib++;
      }
    }
  }

  if (ia != sa.length() || ib != sb.length()) {
    diffCount++;
  }

  return diffCount < 2;
}

bool isOneWay(string& sa, string& sb) {
  // Check for exchange edit
  if (sa.length() == sb.length()) {
    return hasOnlyOneExchange(sa, sb);
  } else if (abs((int)sa.length() - (int)sb.length()) == 1) {
    return hasOnlyOneRemoveAdd(sa, sb);
  }

  return false;
}

int main(void) {
  string target1, target2;

  cin >> target1 >> target2;
  cout << "Is one way: " << isOneWay(target1, target2) << endl;

  return 0;
}