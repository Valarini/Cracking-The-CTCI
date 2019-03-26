#include <memory>
#include <iostream>

template<typename T>
struct Node {
public:
  Node(T data) : data(data), next(nullptr) {};

public:
  T data;
  std::shared_ptr<Node<T>> next;
};

template<typename T>
class SingleLinkedList {
public:
  SingleLinkedList() : head(nullptr) {};
  SingleLinkedList(T data) {
    head = std::make_shared<Node<T>>(data);
  };

public:
  std::shared_ptr<Node<T>> pushBack(T data);
  std::shared_ptr<Node<T>> pushFront(T data);
  bool deleteItem(T data);

public:
  void print();

public:
  std::shared_ptr<Node<T>> head;
};

template<typename T>
std::shared_ptr<Node<T>> SingleLinkedList<T>::pushFront(T data) {
  auto newNode = std::make_shared<Node<T>>(data);

  newNode->next = head;
  head = newNode;

  return newNode;
}

template<typename T>
std::shared_ptr<Node<T>> SingleLinkedList<T>::pushBack(T data) {
  auto newNode = std::make_shared<Node<T>>(data);

  if (head == nullptr) {
    head = newNode;
  } else {
    auto node = head;
    while (node->next != nullptr) {
      node = node->next;
    }
    node->next = newNode;
  }

  return newNode;
}

template<typename T>
bool SingleLinkedList<T>::deleteItem(T targetData) {
  if (head == nullptr) {
    return false;
  }

  if (head->data == targetData) {
    head = head->next;
    return true;
  }

  for (auto node = head; node->next != nullptr; node = node->next) {
    if (node->next->data == targetData) {
      node->next = node->next->next;
      return true;
    }
  }

  return false;
}

template<typename T>
void SingleLinkedList<T>::print() {
  std::cout << "{";

  if (head != nullptr) {
    auto node = head;
    while (node->next != nullptr) {
      std::cout << node->data << ", ";
      node = node->next;
    }

    std::cout << node->data;
  }

  std::cout << "}" << std::endl;
}