// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <stdexcept>
template<typename T>
class TPQueue {
 private:
  struct Node {
    T value;
    Node* next;
    explicit Node(const T& val) : value(val), next(nullptr) {}
  };
  Node* front;

 public:
  TPQueue() : front(nullptr) {}
  void push(const T& item) {
    Node* newNode = new Node(item);
    if (!front || item.prior > front->value.prior) {
      newNode->next = front;
      front = newNode;
      return;
    }
    Node* curent = front;
    while (curent->next && curent->next->value.prior>= item.prior) {
      curent = curent->next;
    }
    newNode->next = curent->next;
    curent->next = newNode;
  }
  T pop() {
    if (!front) {
      throw std::runtime_error("Очередь пуста");
    }
    Node* temp = front;
    T result = temp->value;
    front = front->next;
    delete temp;
    return result;
  }
  ~TPQueue() {
    Node* current = front;
    Node* next = nullptr;
    while (current) {
      next = current->next;
      delete current;
      current = next;
    }
  }
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
