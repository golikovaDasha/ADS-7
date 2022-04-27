// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
template<typename T>
class TPQueue {
 private:
  struct ITEM {
    T value;
    ITEM* next, * prev;
  };
  ITEM* start, * fin;
  TPQueue::ITEM* create(const T& value) {
    ITEM* item = new ITEM;
    item->value = value;
    item->next = item->prev = nullptr;
    return item;
}

 public:
  TPQueue() : start(nullptr), fin(nullptr) {}
  void push(const T& value);
  T pop();
};
template<typename T>
T TPQueue<T>:: pop() {
  if (start && fin) {
    ITEM* temp = start->next;
    if (temp) {
      temp->prev = nullptr;
    }
    T value = start->value;
    delete start;
    start = temp;
    if (!start) {
      fin = nullptr;
    }
  return value;
  } else {
    throw std::string("The queue is empty");
  }
}
template<typename T>
void TPQueue<T>:: push(const T& value) {
  ITEM* temp = start;
  ITEM* item = create(value);
  while (temp && temp->value.prior >= value.prior)
    temp = temp->next;
    if (!temp && start) {
      fin->next = item;
      item->prev = fin;
      fin = item;
    } else if (!temp && !start) {
      start = fin = item;
    } else if (!temp->prev) {
      start->prev = item;
      item->next = start;
      start = item;
    } else {
      temp->prev->next = item;
      item->prev = temp->prev;
      item->next = temp;
      temp->prev = item;
    }
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
