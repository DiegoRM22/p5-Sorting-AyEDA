#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <iostream>

#include "../sort-method.h"

template <class Key>
class HeapSort : public SortMethod<Key> {
  
 public:
  HeapSort(const StaticSequence<Key>& sequence) : SortMethod<Key>(sequence) {}
  void Sort() override {
    std::cout << "HeapSort" << std::endl;
    BuildMaxHeap();
    for (int i = this->sequence_.GetSize() - 1; i > 0; i--) {
      int temp = this->sequence_[0];
      this->sequence_.Set(0, this->sequence_[i]);
      this->sequence_.Set(i, temp);
      MaxHeapify(0, i);
    }
  }

 private:
  void BuildMaxHeap() {
    for (int i = this->sequence_.GetSize() / 2 - 1; i >= 0; i--) {
      MaxHeapify(i, this->sequence_.GetSize());
    }
  }

  void MaxHeapify(int i, int heap_size) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < heap_size && this->sequence_[left] > this->sequence_[largest]) {
      largest = left;
    }
    if (right < heap_size && this->sequence_[right] > this->sequence_[largest]) {
      largest = right;
    }
    if (largest != i) {
      int temp = this->sequence_[i];
      this->sequence_.Set(i, this->sequence_[largest]);
      this->sequence_.Set(largest, temp);
      MaxHeapify(largest, heap_size);
    }
  }
};

#endif