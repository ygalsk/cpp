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
