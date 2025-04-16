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

bool isChar(std::string str) {
	if (str.length() == 1 && isprint(str[0]))
		return true;
	return false;
}

bool isInt(std::string str) {
	if (str.length() == 0)
		return false;
	if (str[0] == '-' || str[0] == '+')
		str = str.substr(1);
	for (size_t i = 0; i < str.length(); i++) {
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

bool isFloat(std::string str) {
	if (str.length() == 0)
		return false;
	if (str[0] == '-' || str[0] == '+')
		str = str.substr(1);
	size_t dotCount = 0;
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == '.') {
			dotCount++;
			if (dotCount > 1)
				return false;
		} else if (!isdigit(str[i])) {
			return false;
		}
	}
	return dotCount == 1;
}

bool isDouble(std::string str) {
	if (str.length() == 0)
		return false;
	if (str[0] == '-' || str[0] == '+')
		str = str.substr(1);
	size_t dotCount = 0;
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == '.') {
			dotCount++;
			if (dotCount > 1)
				return false;
		} else if (!isdigit(str[i])) {
			return false;
		}
	}
	return dotCount == 1;
}
