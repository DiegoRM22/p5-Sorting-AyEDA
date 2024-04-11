
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
#include "NIF/nif.h"

template <class Key>
void printInstance(Key* data, int dataSize) {
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

void CalculatesAverages(SortMethod<int>* sortMethod, std::vector<int*> instances, int size) {
  int comparisons = 0;
  int swaps = 0;
  for (int i = 0; i < 10; i++) {
    StaticSequence<int> sequence(size, instances[i]);
    sortMethod->SetSequence(sequence);
    sortMethod->Sort();
    comparisons += sortMethod->GetComparisons();
    swaps += sortMethod->GetSwaps();
  }
  std::cout << comparisons / 10 << "            " << swaps / 10 << std::endl;
}


int main(int argc, char** argv) {
  // Start the seed.
  srand(time(NULL));
  // Vamos a generar las instancias de tamaños 10, 100 y 1000.
  // Vamos a generar 10 instancias de cada tamaño.
  std::vector<int*> size10Instances;
  InstanceGenerator<int> generator;
  for (int i = 0; i < 10; i++) {
    size10Instances.push_back(generator.GenerateRandomInstance(10, 10));
  }

  std::vector<int*> size100Instances;
  for (int i = 0; i < 10; i++) {
    size100Instances.push_back(generator.GenerateRandomInstance(100, 10));
  }
  
  std::vector<int*> size1000Instances;
  for (int i = 0; i < 10; i++) {
    size1000Instances.push_back(generator.GenerateRandomInstance(1000, 10));
  }
  int sizes[3] = {10, 100, 1000};
  std::vector<int*> instances[3] = {size10Instances, size100Instances, size1000Instances};
  for (int i = 0; i < 3; i++) {
    std::cout << "Tamaño: " << sizes[i] << " Comparaciones" << "  " << "Intercambios" << std::endl; 
    int comparaciones = 0;
    int intercambios = 0;
    StaticSequence<int> sequence(sizes[i], instances[i][0]);
    std::cout << "SelectSort:   ";
    CalculatesAverages(new SelectSort<int>(sequence), instances[i], sizes[i]);
    std::cout << "QuickSort:    ";
    CalculatesAverages(new QuickSort<int>(sequence), instances[i], sizes[i]);
    std::cout << "HeapSort:     ";
    CalculatesAverages(new HeapSort<int>(sequence), instances[i], sizes[i]);
    std::cout << "RadixSort:    ";
    CalculatesAverages(new RadixSort<int>(sequence), instances[i], sizes[i]);
    std::cout << "ShellSort:    ";
    CalculatesAverages(new ShellSort<int>(sequence), instances[i], sizes[i]);
    std::cout << "--------------------------------------------" << std::endl;
  }
    


  







  return 0;
}