#include "PMergeMe.hpp"

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Error: No arguments provided" << std::endl;
    return 1;
  }

  PMergeMe sorter;
  if (!sorter.parseInput(argc, argv))
    return 1;

  sorter.sort();
  return 0;
}
