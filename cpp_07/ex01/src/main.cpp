#include "Iter.hpp"
#include <string>
#include <iostream>

int main() {
    // Test with integers
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Int array:" << std::endl;
    iter(intArray, intSize, print);

    // Test with strings
    std::string strArray[] = {"hello", "world", "template", "fun"};
    size_t strSize = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "\nString array:" << std::endl;
    iter(strArray, strSize, print);

    // Test with chars
    char charArray[] = {'A', 'B', 'C'};
    size_t charSize = sizeof(charArray) / sizeof(charArray[0]);

    std::cout << "\nChar array:" << std::endl;
    iter(charArray, charSize, print);

    return 0;
}
