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
  int GetComparisons() const { return comparisons_; }
  int GetSwaps() const { return swaps_; }
  void SetSequence(const StaticSequence<Key>& sequence) { sequence_ = sequence; }

 protected:
  StaticSequence<Key> sequence_;
  int comparisons_ = 0;
  int swaps_ = 0;
};

#endif