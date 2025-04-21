#pragma once

#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

class PMergeMe {
public:
  PMergeMe() = default;
  PMergeMe(const PMergeMe &other) = default;
  PMergeMe &operator=(const PMergeMe &other) = default;
  ~PMergeMe() = default;
  bool parseInput(int argc, char **argv);
  void sort();

private:
  std::vector<int> _vec;
  std::deque<int> _deq;
  template <typename T> void mergeSort(T &container);
  static std::vector<int> generateJacobstahlSequence(int size);
};

#include "PMergeMe.tpp"
