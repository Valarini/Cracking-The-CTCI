#include "./LinkedList.h"
#include <iostream>
#include <memory>

using namespace std;

template<typename T>
bool addOrReplace(shared_ptr<Node<T>>& node, shared_ptr<Node<T>>& new_node) {
  if (node == nullptr) {
    new_node->next = nullptr;
    node = new_node;
    return true;
  } else {
    new_node->next = node->next;
    node->next = new_node;
    return false;
  }
}

template<typename T>
void partition(SingleLinkedList<T>& list, T target) {
  // Find the last element in a row that is less then the target
  shared_ptr<Node<T>> lt_node;
  shared_ptr<Node<T>> eq_node;
  shared_ptr<Node<T>> gt_node;

  shared_ptr<Node<T>> node = list._head;
  while (node != nullptr) {
    if (node->data < target) {
      if (addOrReplace(lt_nodes, node)) {
        lt_last = node;
      }
    } else if (node->data > target) {
      if (addOrReplace(gt_nodes, node)) {
        gt_last = node;
      }
    } else {
      if (addOrReplace(eq_nodes, node)) {
        eq_last = node;
      }
    }
    node = node->next;
  }
}

int main() {
  SingleLinkedList<int> list;

  for (int i = 10; i >= 0; --i) {
    list.pushBack(i);
  }
  
  list.print();
  partition(list, 5);
  list.print();

  return 0;
}