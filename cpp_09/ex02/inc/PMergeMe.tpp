#include "PMergeMe.hpp"
#include <algorithm>
#include <cstddef>

template <typename T> void PMergeMe::mergeSort(T &container) {
  if (container.size() <= 1)
    return;

  int unpairedElement = -1;
  if (container.size() % 2 != 0) {
    unpairedElement = container.back();
    container.pop_back();
  }

  std::vector<std::pair<int, int>> elementPairs;
  for (size_t i = 0; i < container.size(); i += 2) {
    int firstElement = container[i];
    int secondElement = container[i + 1];

    if (firstElement > secondElement)
      std::swap(firstElement, secondElement);
    elementPairs.push_back(std::make_pair(firstElement, secondElement));
  }

  struct PairCompare {
    bool operator()(const std::pair<int, int> &a,
                    const std::pair<int, int> &b) const {
      return a.second < b.second;
    }
  };

  std::sort(elementPairs.begin(), elementPairs.end(), PairCompare());

  T sortedSequence;
  std::vector<int> pendingElements;

  for (size_t i = 0; i < elementPairs.size(); i++) {
    sortedSequence.push_back(elementPairs[i].second);
    pendingElements.push_back(elementPairs[i].first);
  }

  sortedSequence.insert(sortedSequence.begin(), pendingElements[0]);

  std::vector<int> insertionOrder =
      generateJacobstahlSequence(pendingElements.size() - 1);
  for (size_t i = 0; i < insertionOrder.size(); i++) {
    int index = insertionOrder[i];
    int element = pendingElements[index];
    typename T::iterator position =
        std::lower_bound(sortedSequence.begin(), sortedSequence.end(), element);
    sortedSequence.insert(position, element);
  }

  if (unpairedElement != -1) {
    typename T::iterator position = std::lower_bound(
        sortedSequence.begin(), sortedSequence.end(), unpairedElement);
    sortedSequence.insert(position, unpairedElement);
  }
  container = sortedSequence;
}
