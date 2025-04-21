#include "BitcoinExchange.hpp"
#include <exception>
#include <fstream>
#include <stdexcept>
#include <string>

void BitcoinExchange::btc(std::string input_file) {
  parseDatabase("data.csv");
  parseInput(input_file);
}

void BitcoinExchange::exchangeRate(const std::string inputDate,
                                   const double value) {
  auto dateIterator = this->_database.lower_bound(inputDate);
  if (dateIterator == this->_database.end() ||
      dateIterator->first != inputDate) {
    if (dateIterator == this->_database.begin())
      throw std::runtime_error("No data available for " + inputDate);
    dateIterator--;
  }
  double exchangeRate = value * dateIterator->second;
  std::cout << inputDate << " => " << value << " = " << exchangeRate
            << std::endl;
}

void BitcoinExchange::parseDatabase(const std::string databaseFile) {
  std::ifstream file(databaseFile);
  if (!file.is_open())
    throw std::runtime_error("Failed to open Databse File");

  std::string line;
  std::getline(file, line);

  while (std::getline(file, line)) {
    try {
      std::istringstream lineStream(line);
      std::string date, strValue;
      if (line.find(',') == std::string::npos)
        throw std::runtime_error("bad input => " + line);
      if (std::getline(lineStream, date, ',') &&
          std::getline(lineStream, strValue)) {
        if (!isValidDate(date))
          throw std::runtime_error("bad input => " + date);
        if (date.empty() || strValue.empty())
          throw std::runtime_error("empty date or value");
        double bitcoinPrice = std::stod(strValue);
        if (bitcoinPrice < 0)
          throw std::out_of_range("");
        this->_database[date] = bitcoinPrice;
      }
    } catch (const std::exception &e) {
      std::cerr << "Error: " << e.what() << std::endl;
    }
  }
}

void BitcoinExchange::parseInput(const std::string input_file) {
  std::ifstream file(input_file);
  if (!file.is_open())
    throw std::runtime_error("Failed to open Input File");

  std::string line;
  std::getline(file, line);

  while (std::getline(file, line)) {
    try {
      std::istringstream lineStream(line);
      std::string date, strValue;
      if (line.find('|') == std::string::npos)
        throw std::runtime_error("bad input => " + line);
      if (std::getline(lineStream, date, '|') &&
          std::getline(lineStream, strValue)) {
        if (!isValidDate(date))
          date = ft_trim(date);
        strValue = ft_trim(strValue);
        if (!isValidDate(date))
          throw std::runtime_error("bad input => " + date);
        if (date.empty() || strValue.empty())
          throw std::runtime_error("empty date or value");
        double value = std::stod(strValue);
        if (value < 0 || value > 1000)
          throw std::runtime_error("value out of range");
        BitcoinExchange::exchangeRate(date, value);
      }
    } catch (const std::exception &e) {
      std::cerr << "Error: " << e.what() << std::endl;
    }
  }
}

bool isValidDate(const std::string date) {
  int year, month, day;
  char dash1, dash2;

  std::istringstream dateStream(date);
  dateStream >> year >> dash1 >> month >> dash2 >> day;

  if (date.length() != 10 || dash1 != '-' || dash2 != '-')
    return false;
  if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
    return false;
  if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
    return false;
  if (month == 2) {
    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (day > (isLeapYear ? 29 : 28))
      return false;
  }
  return true;
}

std::string ft_trim(const std::string str) {
  const auto first = str.find_first_not_of(" \t");
  if (first == std::string::npos)
    return "";
  const auto last = str.find_last_not_of(" \t");
  const auto range = last - first + 1;
  return str.substr(first, range);
}
