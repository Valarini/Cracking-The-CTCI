#include "./LinkedList.h"
#include <iostream>
#include <memory>

using namespace std;

int turnListToInt(SingleLinkedList<int>& listed_num) {
  int result = 0;
  int digit_power = 1;
  shared_ptr<Node<int>> curr_node = listed_num.head;
  
  while (curr_node != nullptr) {
    result += curr_node->data * digit_power;
    digit_power *= 10;
    curr_node = curr_node->next;
  }

  return result;
}

SingleLinkedList<int> turnIntToList(int number) {
  SingleLinkedList<int> result;

  do {
    result.pushBack(number % 10);
    number /= 10;
  } while (number > 0);

  return result;
}

SingleLinkedList<int> add(SingleLinkedList<int>& listed_a, SingleLinkedList<int>& listed_b) {
  int a = turnListToInt(listed_a);
  int b = turnListToInt(listed_b);
  return turnIntToList(a + b);
}

int main() {
  SingleLinkedList<int> list;

  auto a = turnIntToList(1);
  auto b = turnIntToList(100001);

  add(a, b).print();

  return 0;
}