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
  explicit DoublyLinkedList(const std::vector<T>& values); //DONE

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
  void push_back(const T& value);

  //is the list empty?
  bool empty() const;

  //return the number of elements in the list
  int size() const;

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
  void insert(iterator& position, const T& value);

  //remove the element at the position pointed to
  //by the iterator.
  //I promise not to use the iterator again after the erase is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And when the wanted to erase the iterator was at the 9
  //1 <-> 17
  void erase(iterator& position);

 private:
  Node_Ptr head;
  Node_Ptr tail;
  int length;

};

//write to the stream each element in the list in order
//with a space in between them
template<typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList);

//read elements from the stream as long as it is good
// or until a newline (\n) is encountered
//if a newline is encountered it should be consumed
template<typename T>
std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList);

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()  {
  head = nullptr;
  tail = nullptr;
  length = 0;
}

template<typename T>
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
  DoubleLinkedNode<T>* node= new DoublyLinkedNode<T>(value);
  if (head == nullptr){
    head = node;
    tail = node;
  }
  else{
    head->prev = node;
    node->next = head;
    head = node;
  }
  length++;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
  DoubleLinkedNode<T>* currNode = new DoubleLinkedNode<T>(value);
  if(head){
    tail->next = currNode;
    currNode->prev = tail;
    currNode->next = nullptr;
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
    curr = curr -> next;
    delete prev;
    prev = curr;
  }
  delete prev;
}

template<typename T>
typename DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::begin() const {
  return ConstDoublyLinkedListIterator<T>(head);
}

template<typename T>
typename DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::end() const {
  return ConstDoublyLinkedListIterator<T>(nullptr);
}

template<typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::begin() {
  return ConstDoublyLinkedListIterator<T>(head);
}

template<typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::end() {
  return ConstDoublyLinkedListIterator<T>(nullptr);
}

template<typename T>
void DoublyLinkedList<T>::insert(iterator& position, const T& value) {
}

template<typename T>
void DoublyLinkedList<T>::erase(iterator& position) {
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
  node* currNode = doublyLinkedList.head;
  while (currNode){
    out << currNode -> data << " ";
    currNode = currNode -> next;
  }
  std::cout << std::endl;
  return out;
}

template<typename T>
std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList) {
  T data;
  char c = in.peek();
  while(c != "\n" || c != EOF){
    in >> data;
    doublyLinkedList.push_back(data);
    c = in.peek();
  }
  return in;
}

#endif //LINKEDLIST_DOUBLYLINKEDLIST_H
