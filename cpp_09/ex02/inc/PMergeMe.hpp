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
  bool getInput(int ac, char **av);
  void sort();

private:
  std::vector<int> _vec;
  std::deque<int> _deq;
  template <typename T> void mergeSort(T &container);
};

#include "PMergeMe.tpp"
