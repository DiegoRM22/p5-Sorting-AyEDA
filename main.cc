
#include "sort-method/sort-method.h"
#include "sequence/static-sequence/static-sequence.h"
#include "sort-method/select-sort/select-sort.h"

int main() {
  int data[5] = {5, 4, 3, 2, 1};
  StaticSequence<int> sequence(5, data);
  SelectSort<int> sort_method(sequence);
  sort_method.Sort();
  StaticSequence<int> sorted_sequence = sort_method.GetSequence();
  for (int i = 0; i < 5; i++) {
    std::cout << sorted_sequence[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}