#include "Converter.hpp"

static eType getType(std::string str) {
	if (isChar(str))
		return CHAR;
	else if (isInt(str))
		return INT;
	else if (isFloat(str))
		return FLOAT;
	else if (isDouble(str))
		return DOUBLE;
	else
		return INVALID;
}
