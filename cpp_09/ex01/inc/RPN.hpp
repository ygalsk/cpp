#pragma once

#include <iostream>
#include <sstream>
#include <stack>

class RPN {
public:
  RPN() = default;
  RPN(const RPN &other) = default;
  RPN &operator=(const RPN &other) = default;
  ~RPN() = default;

  int evaluateRPN(const std::string input);
  void isValidInput(const std::string input);
};
