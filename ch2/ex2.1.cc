#include "./LinkedList.h"
#include <unordered_set>

using namespace std;

template<typename T>
void removeDups(SingleLinkedList<T>& list) {
  if (list._head == nullptr) {
    return;
  }

  unordered_set<T> seen;
  auto node = list._head;
  seen.emplace(node->data);

  while (node->next != nullptr) {
    if (seen.count(node->next->data)) {
      node->next = node->next->next;
    } else {
      seen.emplace(node->next->data);
      node = node->next;
    }
  }
}

template<typename T>
void removeDupsB(SingleLinkedList<T>& list) {
  for (auto nodeA = list._head; nodeA != nullptr; nodeA = nodeA->next) {
    auto nodeB = nodeA;
    while (nodeB->next != nullptr) {
      if (nodeB->next->data == nodeA->data) {
        nodeB->next = nodeB->next->next;
      } else {
        nodeB = nodeB->next;
      }
    }
  }
}

int main() {
  SingleLinkedList<int> list;
  
  for (int i = 0; i < 10; ++i) {
    list.pushBack(i);
  }

  list.print();

  for (int i = 0; i < 20; i+=2) {
    list.pushBack(i);
    list.pushBack(i);
  }

  list.print();

  removeDupsB(list);

  list.print();

  return 0;
}