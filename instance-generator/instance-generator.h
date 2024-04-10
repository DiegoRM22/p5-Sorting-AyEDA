#ifndef INSTANCE_GENERATOR_H
#define INSTANCE_GENERATOR_H

#include <iostream>
#include <stdlib.h>

template <class Key>
class InstanceGenerator {
 public:
  InstanceGenerator() {}
  Key* GenerateRandomInstance(const int size, const int max_value) {
    Key* instance = new Key[size];
    for (int i = 0; i < size; i++) {
      instance[i] = rand() % max_value;
    }
    return instance;
  }
};

#endif