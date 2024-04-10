#ifndef SORT_METHOD_H
#define SORT_METHOD_H

#include <iostream>

#include "../sequence/static-sequence/static-sequence.h"
template <class Key>
class SortMethod {
 public:
  SortMethod(const StaticSequence<Key>& sequence) : sequence_(sequence) {}
  SortMethod() = default;
  virtual void Sort() = 0;
  StaticSequence<Key> GetSequence() const { return sequence_; }

 protected:
  StaticSequence<Key> sequence_;
};

#endif