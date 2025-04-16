#include "Span.hpp"
#include <iostream>

// Color macros for better output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"

int main()
{
    std::cout << BOLD BLUE "=== Subject Test ===" RESET << std::endl;
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    Span sp2 = sp;
    std::cout << "Shortest span: " << GREEN << sp.shortestSpan() << RESET << std::endl;
    std::cout << "Longest span: " << GREEN << sp.longestSpan() << RESET << std::endl;

    std::cout << BOLD BLUE "\n=== Testing with 10000 numbers ===" RESET << std::endl;
    try {
        Span sp(10000);
        for (int i = 0; i < 10000; i++)
            sp.addNumber(i);
        std::cout << "Shortest span: " << GREEN << sp.shortestSpan() << RESET << std::endl;
        std::cout << "Longest span: " << GREEN << sp.longestSpan() << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << BOLD BLUE "\n=== Using range of iterators ===" RESET << std::endl; 
    try {
        std::vector<int> numbers = {6, 3, 17, 9, 11};
        Span sp(5);
        sp.addNumbers(numbers.begin(), numbers.end());
        std::cout << "Shortest span: " << GREEN << sp.shortestSpan() << RESET << std::endl;
        std::cout << "Longest span: " << GREEN << sp.longestSpan() << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << BOLD BLUE "\n=== Testing Invalid Cases ===" RESET << std::endl;
    try {
        std::cout << YELLOW << "-- Testing with size 1 --" << RESET << std::endl;
        Span sp(1);
        sp.addNumber(1);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << YELLOW << "\n-- Testing with size 0 --" << RESET << std::endl;
        Span sp(0);
        sp.addNumber(1);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << YELLOW << "\n-- Adding more elements than size --" << RESET << std::endl;
        Span sp(1);
        sp.addNumber(1);
        sp.addNumber(2);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    return 0;
}
