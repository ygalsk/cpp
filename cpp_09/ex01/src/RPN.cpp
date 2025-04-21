#include "RPN.hpp"

int RPN::evaluateRPN(const std::string input) {

  std::stack<int> stack;
  std::istringstream inputStream(input);
  std::string token;

  while (inputStream >> token) {
    if (isdigit(token[0]))
      stack.push(std::stoi(token));
    else {
      if (stack.size() < 2)
        throw std::runtime_error("Insufficient operands");
      int a = stack.top();
      stack.pop();
      int b = stack.top();
      stack.pop();

      if (token == "+")
        stack.push(b + a);
      else if (token == "-")
        stack.push(b - a);
      else if (token == "*")
        stack.push(b * a);
      else if (token == "/") {
        if (a == 0)
          throw std::runtime_error("Division by zero");
        stack.push(b / a);
      }
    }
  }
  if (stack.size() != 1)
    throw std::runtime_error("Invalid RPN expression");
  return stack.top();
}

void RPN::isValidInput(const std::string input) {
  std::istringstream inputStream(input);
  std::string token;

  while (inputStream >> token) {
    if (token == "+" || token == "-" || token == "*" || token == "/")
      continue;
    if (token.size() != 1 ||
        token.find_first_not_of("0123456789") != std::string::npos)
      throw std::runtime_error("Invalid character in input: " + token);
  }
}
