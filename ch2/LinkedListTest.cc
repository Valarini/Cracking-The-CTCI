#include "./LinkedList.h"

int main() {
  SingleLinkedList<int> list;
  
  for (int i = 0; i < 10; ++i) {
    list.pushBack(i);
  }

  list.print();

  for (int i = 0; i < 10; i+=2) {
    list.deleteItem(i);
  }

  list.print();

  for (int i = 10; i < 20; ++i) {
    list.pushBack(i);
  }

  list.print();

  return 0;
}