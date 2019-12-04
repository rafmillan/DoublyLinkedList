//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLELINKEDNODE_H
#define LINKEDLIST_DOUBLELINKEDNODE_H
#include <iostream>

template<typename T>
class DoublyLinkedList;
template<typename T>
class DoublyLinkedListIterator;
template<typename T>
class ReverseDoublyLinkedListIterator;
template<typename T>
class ConstDoublyLinkedListIterator;
template<typename T>
class ConstReverseDoublyLinkedListIterator;

template<typename T>
class DoublyLinkedNode {

 public:
  T value = new T;
  DoublyLinkedNode<T>* next = new DoublyLinkedNode<T>*;
  DoublyLinkedNode<T>* prev = new DoublyLinkedNode<T>*;
  DoublyLinkedNode() = default;
  explicit DoublyLinkedNode(T val) : value(val), next(nullptr), prev(nullptr) {}

  DoublyLinkedNode<T>* getNext() const{
    return this->next;
  }

  DoublyLinkedNode<T>* getPrev() const{
    return this->prev;
  }
  T& getValue() {
    return this->value;
  }

  void assignNext(DoublyLinkedNode<T> *node) {
    this->next = node;
  }

  void assignPrevious(DoublyLinkedNode<T> *node) {
    this->prev = node;
  }

};

#endif //LINKEDLIST_DOUBLELINKEDNODE_H
