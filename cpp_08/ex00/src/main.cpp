#include "Easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main() {

    std::vector<int> vec = {10, 20, 30, 40, 50};
    try {
        auto it = easyfind(vec, 30);
        std::cout << "Found: " << *it<< " in vector container" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "---non existing value---" << std::endl;
    try {
        auto it = easyfind(vec, 60);
        std::cout << "Found: " << *it << " in vector container" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::list<int> lst = {5, 10, 15, 20, 25};
    try {
        auto it = easyfind(lst, 15);
        std::cout << "Found: " << *it << " in list container" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::deque<int> deq = {100, 200, 300, 400, 500};
    try {
        auto it = easyfind(deq, 200);
        std::cout << "Found: " << *it << " in deque container" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
