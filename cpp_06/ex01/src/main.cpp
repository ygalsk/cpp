#include "Serializer.hpp"

int main(){
    // Create and initialize data
    Data data;
    data.rnd_int = 42;
    data.rnd_string = "Hello, World!";

    std::cout << "\n=== Original Values ===" << std::endl;
    std::cout << "Integer: " << data.rnd_int << std::endl;
    std::cout << "String: " << data.rnd_string << std::endl;

    std::cout << "Performing serialization and deserialization" << std::endl;
    uintptr_t serialized = Serializer::serialize(&data);
    Data* deserialized = Serializer::deserialize(serialized);


    std::cout << "\n=== Deserialized Values ===" << std::endl;
    std::cout << "Integer: " << deserialized->rnd_int << std::endl;
    std::cout << "String: " << deserialized->rnd_string << std::endl;

    std::cout << "\n=== Address Comparison ===" << std::endl;
    std::cout << "Original address: " << &data << std::endl;
    std::cout << "Serialized value as dec: " << serialized << std::endl;
    std::cout << "Serialized value as hex: x0"<< std::hex << serialized << std::dec << std::endl;
    std::cout << "Deserialized address: " << deserialized << std::endl;

    std::cout << "\n=== Testing Data Modification ===" << std::endl;
    deserialized->rnd_int = 100;
    deserialized->rnd_string = "Hi there!";
    std::cout << "Modified through deserialized: " << deserialized->rnd_int << std::endl;
    std::cout << "Original data value: " << data.rnd_int << std::endl;
    std::cout << "Modified through deserialized: " << deserialized->rnd_string << std::endl;
    std::cout << "Original data value: " << data.rnd_string << std::endl;

    return 0;
}
