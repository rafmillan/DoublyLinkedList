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
class DoubleLinkedNode {

 private:
  T data;
  DoubleLinkedNode<T> next;
  DoubleLinkedNode<T> prev;

 public:
  DoubleLinkedNode(T d) : data(d), next(nullptr), prev(nullptr) {}

};

#endif //LINKEDLIST_DOUBLELINKEDNODE_H
