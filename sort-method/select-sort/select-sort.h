#ifndef SELECT_SORT_H
#define SELECT_SORT_H

#include <iostream>

#include "../sort-method.h"

template <class Key>
class SelectSort : public SortMethod<Key> {
 public:
  SelectSort(const StaticSequence<Key>& sequence) : SortMethod<Key>(sequence) {}
  void Sort() override {
    std::cout << "SelectSort" << std::endl;
    for (int i = 0; i < this->sequence_.GetSize(); i++) {
      int min = i;
      for (int j = i + 1; j < this->sequence_.GetSize(); j++) {
        if (this->sequence_[j] < this->sequence_[min]) {
          min = j;
        }
      }
      if (min != i) {
        Key temp = this->sequence_[i];
        this->sequence_.Set(i, this->sequence_[min]);
        this->sequence_.Set(min, temp);
      }
    }
  }
};

#endif