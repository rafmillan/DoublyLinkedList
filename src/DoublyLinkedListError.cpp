//
// Created by mfbut on 11/24/2019.
//
#include <sstream>
#include "DoublyLinkedListError.h"

const char * DoublyLinkedListError::what() const noexcept  {
  return exception::what();
}
DoublyLinkedListError::DoublyLinkedListError() noexcept {
  std::stringstream errorStream;
  errorStream << "Something Broke" << std::endl;
  errorString = errorStream.str();
}
