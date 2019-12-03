//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLYLINKEDLIST_H
#define LINKEDLIST_DOUBLYLINKEDLIST_H

#include <vector>
#include <memory>
#include "DoublyLinkedNode.h"
#include "DoublyLinkedListEmptyError.h"
#include "ConstDoublyLinkedListIterator.h"
#include "DoublyLinkedListIterator.h"
#include "ConstReverseDoublyLinkedIterator.h"
#include "ReverseDoublyLinkedListIterator.h"

template<typename T>
class DoublyLinkedList {
 public:
  using Node_Ptr = DoublyLinkedNode<T>*;

  using iterator = DoublyLinkedListIterator<T>; //put the type of your iterator here
  using const_iterator = ConstDoublyLinkedListIterator<T>;//put the type of your const iterator here
  using reverse_iterator = ReverseDoublyLinkedListIterator<T>; //put the type of your reverse iterator here
  using const_reverse_iterator = ConstReverseDoublyLinkedListIterator<T> //put the type of your const reverse iterator here

  //create a Doubly Linked List that has the same values
  //as in the vector and in the same order
  explicit DoublyLinkedList(const std::vector<T>& values); //TODO WHAT IS WRONG HERE

  //create an empty DoublyLinkedList
  DoublyLinkedList(); //DONE

  //destructor
  virtual ~DoublyLinkedList(); //DONE

  //remove all of the elements from your list
  void clear(); //DONE

  //get a reference to the front element in the list
  const T& front() const; //DONE
  T& front(); //DONE

  //get a reference to the last element in the list
  const T& back() const; //DONE
  T& back(); //DONE

  //add a value to the front of the list
  void push_front(const T& value); //DONE

  //add a value to the back of the list
  void push_back(const T& value); //DONE

  //is the list empty?
  bool empty() const; //DOME

  //return the number of elements in the list
  int size() const; //DONE

  //return a constant bidirectional iterator to the front of the list
  const_iterator begin() const; //DONE
  const_iterator end() const; //DONE

  //return a nonconstant bidirectional iterator to the front of the list
  iterator begin(); //DONE
  iterator end(); //DONE

  const_reverse_iterator crbegin() const; //DONE
  const_reverse_iterator crend() const; //DONE

  reverse_iterator rbegin(); //DONE
  reverse_iterator rend(); //DONE

  //insert the value at the position in the list
  //I promise not to use the iterator again after the insertion is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And the iterator was pointing to the 9 and we wanted to
  //insert -22 the result would be
  //1 <-> 22 <-> 9 <-> 17
  void insert(iterator& position, const T& value); //DONE

  //remove the element at the position pointed to
  //by the iterator.
  //I promise not to use the iterator again after the erase is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And when the wanted to erase the iterator was at the 9
  //1 <-> 17
  void erase(iterator& position); //DONE

 private:
  Node_Ptr head;
  Node_Ptr tail;
  int length;

};

//write to the stream each element in the list in order
//with a space in between them
template<typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList); //DONE

//read elements from the stream as long as it is good
// or until a newline (\n) is encountered
//if a newline is encountered it should be consumed
template<typename T>
std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList);//DONE

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()  {
  head = nullptr;
  tail = nullptr;
  length = 0;
}

template<typename T>//todo what?
DoublyLinkedList<T>::DoublyLinkedList(const std::vector<T>& values)  {
  DoublyLinkedList list;
  for (auto elem: values){
    list.push_back(elem);
  }
}

template<typename T>
bool DoublyLinkedList<T>::empty() const {
  return head == nullptr && tail == nullptr;
}

template<typename T>
int DoublyLinkedList<T>::size() const {
  return length;
}

template<typename T>
const T& DoublyLinkedList<T>::front() const {
  return head;
}

template<typename T>
T& DoublyLinkedList<T>::front() {
  return head;
}

template<typename T>
const T& DoublyLinkedList<T>::back() const {
  return tail;
}

template<typename T>
T& DoublyLinkedList<T>::back() {
  return tail;
}

template<typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
  //DoublyLinkedNode<T>* node= new DoublyLinkedNode<T>(value);
  auto* node= new DoublyLinkedNode<T>(value);
  if (head == nullptr){
    head = node;
    tail = node;
  }
  else{
    head->getprev() = node;
    node->getNext() = head;
    head = node;
  }
  length++;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
  //DoublyLinkedNode<T>* currNode = new DoublyLinkedNode<T>(value);
  auto* currNode = new DoublyLinkedNode<T>(value);
  if(head){
    tail->getNext() = currNode;
    currNode->getPrev() = tail;
    currNode->getNext() = nullptr;
  }
  else{
    head = currNode;
    tail = currNode;
  }
  length++;
}

template<typename T>
void DoublyLinkedList<T>::clear() {
  for(int i = 0; i < this->size(); i++) {
    auto headTemp = head;
    delete head;
    head = headTemp->findNext();
  }
  length = 0;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  Node_Ptr curr = head;
  Node_Ptr prev = head;
  while(curr){
    curr = curr -> getNext();
    delete prev;
    prev = curr;
  }
  delete prev;
}

template<typename T>
typename DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::begin() const {
  return head;
}

template<typename T>
typename DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::end() const {
  return tail;
}

template<typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::begin() {
  return head;
}

template<typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::end() {
  return tail;
}

template<typename T>
void DoublyLinkedList<T>::insert(iterator& position, const T& value) {
  Node_Ptr newNode;

  newNode->getValue() = value;
  newNode->getNext() = position;
  newNode->getPrev() = position->getPrev();

  position->getPrev()->getNext() = newNode;
  position->getprev() = newNode;

}

template<typename T>
void DoublyLinkedList<T>::erase(iterator& position) {
  position->getPrev()->getNext() = position->getNext();
  position->getNext()->getPrev() = position->getPrev();
  delete position;
}

template<typename T>
typename DoublyLinkedList<T>::const_reverse_iterator DoublyLinkedList<T>::crbegin() const {
  return ConstReverseDoublyLinkedListIterator<T>(tail);
}

template<typename T>
typename DoublyLinkedList<T>::const_reverse_iterator DoublyLinkedList<T>::crend() const {
  return ConstReverseDoublyLinkedListIterator<T>(nullptr);
}

template<typename T>
typename DoublyLinkedList<T>::reverse_iterator DoublyLinkedList<T>::rbegin() {
  return ReverseDoublyLinkedListIterator<T>(tail);
}

template<typename T>
typename DoublyLinkedList<T>::reverse_iterator DoublyLinkedList<T>::rend() {
  return ReverseDoublyLinkedListIterator<T>(nullptr);
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList) {
  for (auto it = doublyLinkedList.begin(); it != doublyLinkedList.end(); it++) {
    if (it == doublyLinkedList.end()) {
      out << it;
    }
    out << it << " ";
  }
  return out;

}

template<typename T>
std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList) {
  while(in) {
    T data;
    in >> data;
    if (data == '\n' || data == EOF) {
      break;
    }
    doublyLinkedList.push_back(data);
  }
  return in;
}

#endif //LINKEDLIST_DOUBLYLINKEDLIST_H
