#pragma once

#include <iostream>
#include <iomanip>
#include <string>


enum eType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

class Converter
{
	public:
			Converter() = delete;
			Converter(const Converter &other) = delete;
			Converter &operator=(const Converter &other) = delete;
			~Converter() = delete;
			static void convert(std::string str);
			static void intConvert(std::string str);
			static void charConvert(std::string str);
			static void floatConvert(std::string str);
			static void doubleConvert(std::string str);
			static eType getType(std::string str);
};

bool isChar(std::string str);
bool isInt(std::string str);
bool isFloat(std::string str);
bool isDouble(std::string str);
