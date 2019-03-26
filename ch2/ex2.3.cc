#include "./LinkedList.h"
#include <iostream>
#include <memory>

using namespace std;

template<typename T>
void removeMiddle(shared_ptr<Node<T>> node) {
  node->data = node->next->data;
  node->next = node->next->next;
}

int main() {
  SingleLinkedList<int> list;
  
  list.pushBack(1);
  auto n = list.pushBack(2);
  list.pushBack(3);
  list.pushBack(4);

  list.print();
  removeMiddle(n);
  list.print();

  return 0;
}