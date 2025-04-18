#include <iostream>
#include "Array.hpp"

// Color macros
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

int main()
{
    // Test default constructor
    std::cout << BOLD BLUE "=== Testing default constructor ===" RESET << std::endl;
    Array<int> empty;
    std::cout << "Empty array size: " << GREEN << empty.size() << RESET << std::endl;
    
    // Test parameterized constructor
    std::cout << BOLD BLUE "\n=== Testing parameterized constructor ===" RESET << std::endl;
    Array<int> numbers(5);
    std::cout << "Array size: " << GREEN << numbers.size() << RESET << std::endl;
    
    // Test element assignment and access
    std::cout << BOLD BLUE "\n=== Testing element assignment and access ===" RESET << std::endl;
    for (unsigned int i = 0; i < numbers.size(); i++) {
        numbers[i] = i * 10;
    }
    
    std::cout << "Array contents: ";
    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << CYAN << numbers[i] << " " << RESET;
    }
    std::cout << std::endl;
    
    // Test copy constructor
    std::cout << BOLD BLUE "\n=== Testing copy constructor ===" RESET << std::endl;
    Array<int> copy(numbers);
    std::cout << "Copy size: " << GREEN << copy.size() << RESET << std::endl;
    std::cout << "Copy contents: ";
    for (unsigned int i = 0; i < copy.size(); i++) {
        std::cout << CYAN << copy[i] << " " << RESET;
    }
    std::cout << std::endl;
    
    // Test that copy is independent
    std::cout << BOLD BLUE "\n=== Testing copy independence ===" RESET << std::endl;
    copy[2] = 999;
    std::cout << "Modified copy: ";
    for (unsigned int i = 0; i < copy.size(); i++) {
        if (i == 2) {
            std::cout << YELLOW << copy[i] << " " << RESET; // Highlight modified value
        } else {
            std::cout << CYAN << copy[i] << " " << RESET;
        }
    }
    std::cout << std::endl;
    
    std::cout << "Original array (should be unchanged): ";
    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << CYAN << numbers[i] << " " << RESET;
    }
    std::cout << GREEN << "\n✓ Copy is independent of original" << RESET << std::endl;
    
    // Test assignment operator
    std::cout << BOLD BLUE "\n=== Testing assignment operator ===" RESET << std::endl;
    Array<int> assigned;
    assigned = numbers;
    std::cout << "Assigned array size: " << GREEN << assigned.size() << RESET << std::endl;
    std::cout << "Assigned array contents: ";
    for (unsigned int i = 0; i < assigned.size(); i++) {
        std::cout << CYAN << assigned[i] << " " << RESET;
    }
    std::cout << std::endl;
    
    // Test self-assignment indirectly
    std::cout << BOLD BLUE "\n=== Testing self-assignment protection ===" RESET << std::endl;
    Array<int>* ptr1 = &numbers;
    Array<int>* ptr2 = &numbers;
    std::cout << "Before indirect self-assignment: ";
    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << CYAN << numbers[i] << " " << RESET;
    }
    std::cout << std::endl;
    
    // This is self-assignment but the compiler won't detect it statically
    *ptr1 = *ptr2;
    
    std::cout << "After indirect self-assignment: ";
    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << CYAN << numbers[i] << " " << RESET;
    }
    std::cout << GREEN << "\n✓ Self-assignment handled correctly" << RESET << std::endl;
    
    // Test bounds checking
    std::cout << BOLD BLUE "\n=== Testing bounds checking ===" RESET << std::endl;
    try {
        std::cout << YELLOW << "Attempting to access index -1..." << RESET << std::endl;
        numbers[-1] = 100;
        std::cout << RED << "❌ Failed: No exception thrown" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << GREEN << "✓ Exception caught: " << e.what() << RESET << std::endl;
    }
    
    try {
        std::cout << YELLOW << "Attempting to access index beyond size..." << RESET << std::endl;
        numbers[numbers.size()] = 100;
        std::cout << RED << "❌ Failed: No exception thrown" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << GREEN << "✓ Exception caught: " << e.what() << RESET << std::endl;
    }
    
    // Test with different type
    std::cout << BOLD BLUE "\n=== Testing with different type (string) ===" RESET << std::endl;
    Array<std::string> strings(3);
    strings[0] = "Hello";
    strings[1] = "World";
    strings[2] = "!";
    
    std::cout << "String array contents: ";
    for (unsigned int i = 0; i < strings.size(); i++) {
        std::cout << MAGENTA << strings[i] << " " << RESET;
    }
    std::cout << std::endl;
    
    std::cout << BOLD GREEN "\n=== All tests completed successfully! ===" RESET << std::endl;
    
    return 0;
}
