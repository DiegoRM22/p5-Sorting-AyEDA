#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include <iostream>

#include "../sort-method.h"

template <class Key>
class RadixSort : public SortMethod<Key> {
 public:
  RadixSort(const StaticSequence<Key>& sequence) : SortMethod<Key>(sequence) {}
  void Sort() override {
    Key max = this->sequence_[0];
    for (int i = 1; i < this->sequence_.GetSize(); i++) {
      this->comparisons_++;
      if (this->sequence_[i] > max) {
        max = this->sequence_[i];
      }
    }
    for (int exp = 1; max / exp > 0; exp *= 10) {
      CountingSort(exp);
    }
  }

 private:
  void CountingSort(int exp) {
    StaticSequence<Key> output(this->sequence_.GetSize());
    int count[10] = {0};
    for (int i = 0; i < this->sequence_.GetSize(); i++) {
      count[(this->sequence_[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
      count[i] += count[i - 1];
    }
    for (int i = this->sequence_.GetSize() - 1; i >= 0; i--) {
      output.Set(count[(this->sequence_[i] / exp) % 10] - 1, this->sequence_[i]);
      count[(this->sequence_[i] / exp) % 10]--;
      this->swaps_++;
    }
    for (int i = 0; i < this->sequence_.GetSize(); i++) {
      this->sequence_.Set(i, output[i]);
    }
  }
};

#endif