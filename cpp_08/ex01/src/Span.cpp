#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _data(other._data) {
}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _data = other._data;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int value) {
    if (_data.size() >= _maxSize) {
        throw SpanException("Span is full");
    }
    _data.push_back(value);  // Fixed: using value instead of number
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    while (begin != end) {
        addNumber(*begin);
        begin++;
    }
}

unsigned int Span::shortestSpan() const {
    if (_data.size() < 2) {
        throw SpanException("Not enough numbers to find a span");
    }
    std::vector<int> sortedNumbers = _data;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    unsigned int minSpan = UINT_MAX;
    for (size_t i = 1; i < sortedNumbers.size(); ++i) {
        unsigned int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

unsigned int Span::longestSpan() const {
    if (_data.size() < 2) {
        throw SpanException("Not enough numbers to find a span");
    }
    int min = *std::min_element(_data.begin(), _data.end());
    int max = *std::max_element(_data.begin(), _data.end());
    return max - min;
}
