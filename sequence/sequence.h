#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream> 
#include <string>
template <class Key>
class Sequence {
 public:
  Sequence() {}
  virtual Key operator[](const int position) const = 0;
};

#endif
