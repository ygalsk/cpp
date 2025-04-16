#include "Converter.hpp"

void Converter::convert(std::string str) {
	eType type = getType(str);
	switch (type) {
		case CHAR:
			charConvert(str);
			break;
		case INT:
			intConvert(str);
			break;
		case FLOAT:
			floatConvert(str);
			break;
		case DOUBLE:
			doubleConvert(str);
			break;
		default:
			std::cerr << "Invalid type" << std::endl;
			break;
	}
}

void Converter::intConvert(std::string str) {
	if (str == "-inf" || str == "+inf" || str == "nan") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
		return;
	}
	int value = std::stoi(str);
	char c = static_cast<char>(value);
	if (isprint(c)) {
		std::cout << "char: '" << c << "'" << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}
void Converter::charConvert(std::string str) {
	if (str.length() != 1 || !isChar(str)) {
		std::cerr << "Invalid char" << std::endl;
		return;
	}
	char c = str[0];
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}
