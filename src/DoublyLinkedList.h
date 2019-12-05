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
  using const_reverse_iterator = ConstReverseDoublyLinkedListIterator<T>; //put the type of your const reverse iterator here

  //create a Doubly Linked List that has the same values
  //as in the vector and in the same order
  explicit DoublyLinkedList(const std::vector<T>& values); //Done, tests passed, BUT there is a possibility something here is messing with our clear function

  //create an empty DoublyLinkedList
  DoublyLinkedList(); //DONE

  //destructor
  virtual ~DoublyLinkedList(); //broken, does not properly destroys memory

  //remove all of the elements from your list
  void clear(); //Not Done, very broke, same as destructor

  //get a reference to the front element in the list
  const T& front() const; //Not Done, need to implement error handling
  T& front(); //not Done, need to implement error handling

  //get a reference to the last element in the list
  const T& back() const; //not DOne, need to implement error handling
  T& back(); //Not done, need to implement error handling

  //add a value to the front of the list
  void push_front(const T& value); //DONE, passed test cases, but may be messing with clear function

  //add a value to the back of the list
  void push_back(const T& value); //DONE, passed test cases, but may be messing with clear function

  //is the list empty?
  bool empty() const; //DONE

  //return the number of elements in the list
  int size() const; //DONE

  //return a constant bidirectional iterator to the front of the list
  const_iterator begin() const; //DONE,
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

  DoublyLinkedNode<T>* getTail() const;
  void setTail(DoublyLinkedNode<T> *node);
  void incLength();

 private:
  Node_Ptr head = nullptr;
  Node_Ptr tail = nullptr;
  int length = 0;


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

//Todo: is this right?
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const std::vector<T>& values)  {
  for (auto elem: values) {
    push_back(elem);
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

//Todo: Need to add the empty error for front and back
template<typename T>
const T& DoublyLinkedList<T>::front() const {
  try{
    return head->value;
  }
  catch(DoublyLinkedListOutOfBoundsError& out){
    std::cout << out.what() << std::endl;
  }


}

template<typename T>
T& DoublyLinkedList<T>::front() {


  if(head){
    return head->value;
  }
    else throw DoublyLinkedListEmptyError();
}

template<typename T>
const T& DoublyLinkedList<T>::back() const {
  if(head){
    return tail->value;
  }
  else throw DoublyLinkedListEmptyError();

}

template<typename T>
T& DoublyLinkedList<T>::back() {
  if(head){
    return tail->value;
  }
  else throw DoublyLinkedListEmptyError();

}

template<typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
  DoublyLinkedNode<T>* node = new DoublyLinkedNode<T>(value);
  if(head == nullptr) {
    head = node;
    tail = node;
  }
  else {
    node->next = head;
    node->next->prev = node;
    node -> prev = nullptr;
    head = node;
  }
  this->length++;
}


template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
  DoublyLinkedNode<T>* node = new DoublyLinkedNode<T>(value);
  if(tail == nullptr) {
    tail = node;
    head = node;
  }
  else{
    node->prev = tail;
    node->prev->next = node;
    node->next = nullptr;
    tail = node;
  }
  length++;
}

//todo: is broken :(, Not properly deleting all memory
//Only thing I can think of that might be wrong is the way we are creating the doubly Linked List that is causing us problems.
//Something, somewhere in our code is breaking this. Tutor couldn't figure it out, but he said we may be debugging at the wrong place.
template<typename T>
void DoublyLinkedList<T>::clear() {
  while(head){
    DoublyLinkedNode<T>* Node = head;
    head = head->next;
    head->prev = nullptr;
    delete Node;
    length--;
  }
  tail = nullptr;
}

//Another Possiblity is that this is breaking my code?
//Automatically called whenever constructor is called, supposed to happen
template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  //clear();
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
  return DoublyLinkedListIterator<T>(head);
}

template<typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::end() {
  return DoublyLinkedListIterator<T>(nullptr);
}

template<typename T>
void DoublyLinkedList<T>::insert(iterator& position, const T& value) {
  DoublyLinkedNode<T>* newNode = new DoublyLinkedNode<T>(value);

  if(position.getNode() == head){
    push_front(value);
  }
  else if(position.getNode() == nullptr){
    push_back(value);
  }
  else{
    position.getNode()->prev->next = newNode;
    newNode->prev = position.getNode()->prev;
    newNode->next = position.getNode();
    position.getNode()->prev = newNode;
    length++;
  }
}

template<typename T>
void DoublyLinkedList<T>::erase(iterator& position) {
  if (position.getNode() == head) {
    head = head->next;
    if (head != nullptr) {
      head->prev = nullptr;
    }
    else {
      tail = nullptr;
    }
  }
  else if (position.getNode() == tail) {
    tail = tail->prev;
    tail->next = nullptr;
  }
  else {
    position.getNode()->next->prev = position.getNode()->prev;
    position.getNode()->prev->next = position.getNode()->next;
  }
  length--;
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
DoublyLinkedNode<T>* DoublyLinkedList<T>::getTail() const {
  return tail;
}
template<typename T>
void DoublyLinkedList<T>::setTail(DoublyLinkedNode<T> *node) {
  DoublyLinkedList::tail = node;
}

template<typename T>
void DoublyLinkedList<T>::incLength() {
  DoublyLinkedList::length = length + 1;
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
//  T data;
//  while(in >> data){
//    DoublyLinkedNode<T>* newNode = new DoublyLinkedNode<T>(data);
//    newNode->prev = doublyLinkedList.getTail();
//    doublyLinkedList.getTail()->next = newNode;
//    doublyLinkedList.setTail(newNode);
//    doublyLinkedList.incLength();
//  }
//  return in;

  T data;
  auto c = in.peek();
  while(c != EOF){
    in >> data;
    doublyLinkedList.push_back(data);
    c = in.peek();
  }
  return in;
}

#endif //LINKEDLIST_DOUBLYLINKEDLIST_H
