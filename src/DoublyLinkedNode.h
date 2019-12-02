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
class ConstDoublyLinkedListIterator;
template<typename T>
class ConstReverseDoublyLinkedListIterator;

template<typename T>
class DoublyLinkedNode {

 public:
  T data;
  DoublyLinkedNode<T>* next;
  DoublyLinkedNode<T>*  prev;

  DoublyLinkedNode() = default;
  explicit DoublyLinkedNode(T data) : data(data), next(nullptr), prev(nullptr) {}

};

#endif //LINKEDLIST_DOUBLELINKEDNODE_H
