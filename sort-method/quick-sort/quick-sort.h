#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <iostream>

#include "../sort-method.h"

template <class Key>
class QuickSort : public SortMethod<Key> {
 public:
  QuickSort(const StaticSequence<Key>& sequence) : SortMethod<Key>(sequence) {}
  void Sort() override {
    QuickSorting(0, this->sequence_.GetSize() - 1);
  }

 private:
  void QuickSorting(int low, int high) {
    if (low < high) {
      Key pivot = Partition(low, high);
      QuickSorting(low, pivot - 1);
      QuickSorting(pivot + 1, high);
    }
  }

  int Partition(int low, int high) {
    Key pivot = this->sequence_[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
      this->comparisons_++;
      if (this->sequence_[j] < pivot) {
        i++;
        Key temp = this->sequence_[i];
        this->sequence_.Set(i, this->sequence_[j]);
        this->sequence_.Set(j, temp);
        this->swaps_++;
      }
    }
    Key temp = this->sequence_[i + 1];
    this->sequence_.Set(i + 1, this->sequence_[high]);
    this->sequence_.Set(high, temp);
    this->swaps_++;
    return i + 1;
  }
};

#endif