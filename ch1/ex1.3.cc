#include <string>
#include <iostream>

using namespace std;

struct WordPosition {
  int start;
  int length;
};

WordPosition findPrevWordFrom(string& str, int start) {
  WordPosition word = {start, 0};

  while(word.start > 0 && str[word.start] == ' ') {
    word.start--;
  }

  while(word.start > 0 && str[word.start] != ' ') {
    word.start--;
    word.length++;
  }
  word.start++;

  return word;
}

void moveWordTo(string& str, WordPosition word, int target) {
  for(int i = word.length-1; i >= 0; --i) {
    str[target+i] = str[word.start+i];
  }
}

int countPrevSpacesFrom(string& str, int from) {
  int numSpaces = 0;
  
  while(from > 0 && str[from] == ' ') {
    numSpaces++;
    from--;
  }

  return numSpaces;
}

void insertURLSpacesTo(string& str, int numSpaces, int target) {
  for (int j = 0, i = target; j < numSpaces && target < str.length(); ++j, target += 3) {
    str[target] = '%';
    str[target+1] = '2';
    str[target+2] = '0';
  }
}

void urlifly(string& str) {
  int targetPos = str.length() - 1;
  int lastPos = targetPos;

  while (targetPos > 0) {
    // Move previous word
    auto word = findPrevWordFrom(str, lastPos);
    lastPos = word.start - 1;
    moveWordTo(str, word, targetPos - word.length + 1);
    targetPos = targetPos - word.length;

    // Add url spaces
    int numSpaces = countPrevSpacesFrom(str, lastPos);
    lastPos = lastPos - numSpaces;
    insertURLSpacesTo(str, numSpaces, targetPos - numSpaces*3 + 1);
    targetPos = targetPos - numSpaces*3;
  }
}

int main(void) {
  // string target = "Mr John  ";
  string target;

  getline(cin, target);
  cout << "URLify '"<< target <<"' to ";
  urlifly(target);
  cout << target << endl;

  return 0;
}