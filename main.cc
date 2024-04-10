
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "sort-method/sort-method.h"
#include "sequence/static-sequence/static-sequence.h"
#include "sort-method/select-sort/select-sort.h"
#include "sort-method/quick-sort/quick-sort.h"
#include "sort-method/heap-sort/heap-sort.h"
#include "sort-method/radix-sort/radix-sort.h"
#include "sort-method/shell-sort/shell-sort.h"
#include "instance-generator/instance-generator.h"

void printInstance(int* data, int dataSize) {
  for (int i = 0; i < dataSize; i++) {
    std::cout << data[i] << " ";
  }
}

/**
 * @brief Get the arguments from the command line.
 * @param argc Number of arguments.
 * @param argv Array of arguments.
 * @return std::string All the arguments concatenated.
*/
std::string getArgs(int argc, char** argv) {
  std::string args;
  for (int i = 1; i < argc; i++) {
    args += argv[i];
    if (i < argc - 1) {
      args += " ";
    }
  }
  return args;
}


void SetArguments(std::string arguments, int& size, std::string& method, std::string& inputMode, std::string& fileName, char& trace) {
  // read arguments
  for (int i = 0; i < arguments.size(); i++) {
    if (arguments[i] == '-') {
      if (arguments[i + 1] == 's') {
        // Desde i + 7 hasta encontrar un espacio en blanco
        for (int j = i + 6; j < arguments.size(); j++) {
          if (arguments[j] == ' ') {
            break;
          }
          size = size * 10 + (arguments[j] - '0');
        }
      } else if (arguments[i + 1] == 'o') {
        for (int j = i + 5; j < arguments.size(); j++) {
          if (arguments[j] == ' ') {
            break;
          }
          method += arguments[j];
        }
      } else if (arguments[i + 1] == 'i') {
        for (int j = i + 6; j < arguments.size(); j++) {
          if (arguments[j] == ' ') {
            if (inputMode == "file") {
              for (int k = j + 1; k < arguments.size(); k++) {
                if (arguments[k] == ' ') {
                  break;
                }
                fileName += arguments[k];
              }
            }
            break;
          }
          inputMode += arguments[j];
        }
      } else if (arguments[i + 1] == 't') {
        trace = arguments[i + 7];
      }
    }
  }
}


int main(int argc, char** argv) {
  // Start the seed.
  srand(time(NULL));

  // Read arguments
  int size = 0;
  std::string method = "";
  std::string inputMode = "";
  std::string fileName = "";
  char trace = 'N';
  if (argc > 1) {
    std::string arguments = getArgs(argc, argv);
    std::cout << "Arguments: " << arguments << std::endl;
    SetArguments(arguments, size, method, inputMode, fileName, trace);
  }

  std::cout << "Size: " << size << std::endl;
  std::cout << "Method: " << method << std::endl;
  std::cout << "Input mode: " << inputMode << std::endl;
  std::cout << "File name: " << fileName << std::endl;
  std::cout << "Trace: " << trace << std::endl;

  int* data;
  const int max = 100;
  StaticSequence<int> sequence(size);
  // starts the data
  if (inputMode == "random") {
    InstanceGenerator<int> generator;
    data = generator.GenerateRandomInstance(size, 100);
    sequence = StaticSequence<int>(size, data);
  } else if (inputMode == "file") {
    // read the file
    std::ifstream file(fileName);
    std::string line;
    getline(file, line);
  } else if (inputMode == "manual") {
    std::string input;
    std::vector<int> temporalSequence;
    for (int i = 0; i < size; i++) {
      std::cin >> input;
      sequence.Set(i, std::stoi(input));
    }
  }

  printInstance(sequence.GetData(), size);
  std::cout << std::endl;

  switch (std::stoi(method)) {
    case 1: {
      SelectSort<int> selectSort(sequence);
      selectSort.Sort();
      printInstance(selectSort.GetSequence().GetData(), size);
      break;
    }
    case 2: {
      QuickSort<int> quickSort(sequence);
      quickSort.Sort();
      printInstance(quickSort.GetSequence().GetData(), size);
      break;
    }
    case 3: {
      HeapSort<int> heapSort(sequence);
      heapSort.Sort();
      printInstance(heapSort.GetSequence().GetData(), size);
      break;
    }
    case 4: {
      RadixSort<int> radixSort(sequence);
      radixSort.Sort();
      printInstance(radixSort.GetSequence().GetData(), size);
      break;
    }
    case 5: {
      ShellSort<int> shellSort(sequence);
      shellSort.Sort();
      printInstance(shellSort.GetSequence().GetData(), size);
      break;
    }
  }

  std::cout << std::endl;

  // const int dataSize = 5;
  // const int maxValue = 100;
  // InstanceGenerator<int> generator;
  // int* data = generator.GenerateRandomInstance(dataSize, maxValue);
  // printInstance(data, dataSize);
  // std::cout << std::endl;
  // std::vector<SortMethod<int>*> sort_methods = {
  //   new SelectSort<int>(StaticSequence<int>(5, data)),
  //   new QuickSort<int>(StaticSequence<int>(5, data)),
  //   new HeapSort<int>(StaticSequence<int>(5, data)),
  //   new RadixSort<int>(StaticSequence<int>(5, data)),
  //   new ShellSort<int>(StaticSequence<int>(5, data))
  // };
  // for (auto sort_method : sort_methods) {
  //   sort_method->Sort();
  //   StaticSequence<int> sorted_sequence = sort_method->GetSequence();
  //   printInstance(sorted_sequence.GetData(), dataSize);
  //   std::cout << std::endl;
  // }
  return 0;
}