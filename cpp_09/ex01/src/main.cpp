#include "RPN.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: ./rpn [input]" << std::endl;
    return 1;
  }
  try {
    RPN rpn;
		rpn.isValidInput(argv[1]);
    std::cout << rpn.evaluateRPN(argv[1]) << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  return 0;
}
