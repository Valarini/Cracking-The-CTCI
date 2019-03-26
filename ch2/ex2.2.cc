#include "./LinkedList.h"
#include <iostream>
#include <memory>
#include <functional>

using namespace std;

template<typename T>
T last(SingleLinkedList<T> list, unsigned int n) {
  unsigned int counter = 0;

  function<T(shared_ptr<Node<T>>)> finder;
  finder = [&counter, &n, &finder] (shared_ptr<Node<T>> node) -> T {
    if (node->next == nullptr) {
      counter++;
      return node->data;
    } else {
      T pValue = last(node->next, n, counter);
      counter++;
      if (counter <= n) {
        return node->data;
      } else {
        return pValue;
      }
    }
  };

  return finder(list._head);
}

int main() {
  SingleLinkedList<int> list;
  unsigned int index;
  cin >> index;
  
  for (int i = 0; i < 10; ++i) {
    list.pushBack(i);
  }

  list.print();

  cout << last(list, index) << endl;

  return 0;
}