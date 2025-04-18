#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _data;  // Changed from _numbers to _data to match your header

public:
    Span();
    Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int value);
    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
    
    class SpanException : public std::exception {
    private:
        std::string message;
    public:
        SpanException(const char *msg) : message(msg) {}
        const char *what() const noexcept override {  // Fixed the override
            return message.c_str();
        }
    };
};
