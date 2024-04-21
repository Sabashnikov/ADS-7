// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct Item {
    T data;
    Item* next;
  };
  Item* head;
  Item* tail;
  int count = 0;

 public:
  TPQueue() : head(nullptr), tail(nullptr) {}
  T pop() {
    if (head) {
      Item* temp = head;
      T result = temp->data;
      head = head->next;
      delete temp;
      return result;
    }
  }
  void push(const T& val) {
    int pr = val.prior;
    Item* temp = new Item;
    temp->data = val;
    temp->next = nullptr;
    if (head == nullptr) {
      head = temp;
      tail = temp;
      count++;
      return;
    }
    if (head->data.prior < pr) {
      temp->next = head;
      head = temp;
      count++;
      return;
    }
    Item* end = head;
    for (; count > 1; count--)
      if (end->next != nullptr && end->next->data.prior >= pr)
        end = end->next;
    temp->next = end->next;
    end->next = temp;
    if (temp->next == nullptr)
      tail = temp;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
