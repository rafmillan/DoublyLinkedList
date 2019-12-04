//
// Created by mfbut on 11/24/2019.
//
#include <sstream>
#include "DoublyLinkedListOutOfBoundsError.h"

DoublyLinkedListOutOfBoundsError::DoublyLinkedListOutOfBoundsError():DoublyLinkedListError() {
  std::stringstream errorStream;
  errorStream << "Out of Bounds!!!" << std::endl;
  errorString = errorStream.str();
}
