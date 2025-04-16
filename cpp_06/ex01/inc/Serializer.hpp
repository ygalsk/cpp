#pragma once

#include <iostream>

struct Data {
	int rnd_int;
	std::string rnd_string;
};

class Serializer {
public:
		Serializer() = delete;
		Serializer(const Serializer &other) = delete;
		Serializer &operator=(const Serializer &other) = delete;
		~Serializer() = delete;

		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};
