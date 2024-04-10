#ifndef STATIC_SEQUENCE_H
#define STATIC_SEQUENCE_H

#include <iostream>
#include <string>

#include "../sequence.h"

template <class Key>
class StaticSequence : public Sequence<Key> {
 public:
  StaticSequence(const int size, const Key data[]) : size_(size) {
    data_ = new Key[size];
    for (int i = 0; i < size; i++) {
      data_[i] = data[i];
    }
  }
  Key operator[](const int position) const override {
    return data_[position];
  }
  void Set(const int position, const Key key) {
    data_[position] = key;
  }
  int GetSize() const { return size_; }
 private:
  int size_;
  Key* data_;
};

#endif