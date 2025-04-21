#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class BitcoinExchange {
private:
	std::map<std::string, float> _database;
	void parseDatabase(const std::string db_file);
	void exchangeRate(const std::string date, const double value);
	void parseInput(const std::string input_file);
public:
		BitcoinExchange() = default;
		BitcoinExchange(const BitcoinExchange &other) = default;
		BitcoinExchange &operator=(const BitcoinExchange &other) = default;
		~BitcoinExchange() = default;

	void btc(const std::string filename);
};

bool isValidDate(const std::string date);
std::string ft_trim(std::string str);
