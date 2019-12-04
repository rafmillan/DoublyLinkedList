//
// Created by mfbut on 11/24/2019.
//

#include "DoublyLinkedListEmptyError.h"
#include <sstream>

DoublyLinkedListEmptyError::DoublyLinkedListEmptyError():DoublyLinkedListError() {
  std::stringstream errorStream;
  errorStream << "List is Empty" << std::endl;
  errorString = errorStream.str();
}
