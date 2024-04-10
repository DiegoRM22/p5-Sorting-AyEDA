#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include <iostream>

#include "../sort-method.h"

template <class Key>
class ShellSort : public SortMethod<Key> {
 public:
  ShellSort(const StaticSequence<Key>& sequence) : SortMethod<Key>(sequence) {}
  void Sort() override {
    std::cout << "ShellSort" << std::endl;
    int delta = this->sequence_.GetSize();
    while (delta > 1){
      delta = delta / 2;
      DeltaSort(delta);
    }
  }

 private:
  void DeltaSort(int delta) {
    for (int i = delta; i < this->sequence_.GetSize(); i++) {
      Key x = this->sequence_[i];
      int j = i;
      while (j >= delta && x < this->sequence_[j - delta]) {
        this->sequence_.Set(j, this->sequence_[j - delta]);
        j = j - delta;
      }
      this->sequence_.Set(j, x);
    }
  }
};

#endif