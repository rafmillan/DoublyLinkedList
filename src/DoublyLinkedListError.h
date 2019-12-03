//
// Created by mfbut on 11/24/2019.
//

#ifndef TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTERROR_H
#define TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTERROR_H
#include <string>
class DoublyLinkedListError: public std::exception{
 public:


 protected:
  std::string errorString;

};

#endif //TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTERROR_H
