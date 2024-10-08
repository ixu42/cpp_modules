/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:27:14 by ixu               #+#    #+#             */
/*   Updated: 2024/09/16 18:26:08 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::tuple<int, int, int>, double> BitcoinExchange::_exchangeRates;

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange&) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange&)
{
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

const std::map<std::tuple<int, int, int>, double>& BitcoinExchange::getExchangeRates()
{
	return _exchangeRates;
}

void BitcoinExchange::processDataLine(const std::string& line)
{
	std::string dateString, exchangeRateString;
	std::size_t pos = line.find(',');
	if (pos != std::string::npos)
	{
		dateString = line.substr(0, pos);
		exchangeRateString = line.substr(pos + 1);
		if (dateString.empty() || exchangeRateString.empty())
			throw std::runtime_error("invalid data.csv => " + line);
	}
	else
		throw std::runtime_error("invalid data.csv => " + line);

	std::tuple<int, int, int> date;
	if (!isValidDate(dateString, date))
		throw std::runtime_error("data.csv contains invalid date => " + line);
	if (_exchangeRates.find(date) != _exchangeRates.end())
		throw std::runtime_error("data.csv contains a duplicate date");

	double exchangeRate;
	std::size_t last_num_index;
	exchangeRate = std::stod(exchangeRateString, &last_num_index);
	if (last_num_index != exchangeRateString.size() || exchangeRate < 0)
		throw std::runtime_error("data.csv contains invalid exchange rate => " + line);

	_exchangeRates[date] = exchangeRate;
}

void BitcoinExchange::loadExchangeRates()
{
	std::ifstream inFile("data.csv");

	if (!inFile)
		throw std::runtime_error("could not open file data.csv");
	if (inFile.peek() == std::ifstream::traits_type::eof())
		throw std::runtime_error("data.csv is empty");

	std::string line;
	std::getline(inFile, line);
	if (line.compare("date,exchange_rate") != 0)
		throw std::runtime_error("invalid data.csv => " + line);
	while (std::getline(inFile, line))
		processDataLine(line);
}

bool BitcoinExchange::splitLine(const std::string& line, std::string& dateString, std::string& valueString)
{
	std::size_t pos = line.find(" | ");
	if (pos != std::string::npos) {
		dateString = line.substr(0, pos);
		valueString = line.substr(pos + 3);
		if (dateString.find_last_not_of(" \t\n\v\f\r") != dateString.length() - 1
			|| dateString.find_first_not_of(" \t\n\v\f\r") != 0
			|| valueString.find_last_not_of(" \t\n\v\f\r") != valueString.length() - 1
			|| valueString.find_first_not_of(" \t\n\v\f\r") != 0)
			return false;
		if (dateString.empty() || valueString.empty())
			return false ;
	}
	else
		return false ;
	return true;
}

bool BitcoinExchange::isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
bool BitcoinExchange::isValidDate(const std::string& dateString, std::tuple<int, int, int>& date)
{
	// regular expression to match the date format: YYYY-MM-DD
	const std::regex datePattern(R"(^(\d{4})-(\d{2})-(\d{2})$)");
	std::smatch match;

	if (!std::regex_match(dateString, match, datePattern))
		return false;
	
	int year = std::stoi(match[1].str());
	int month = std::stoi(match[2].str());
	int day = std::stoi(match[3].str());
	
	if (month < 1 || month > 12)
		return false;
	
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month == 2 && isLeapYear(year))
		daysInMonth[1] = 29;

	if (day < 1 || day > daysInMonth[month - 1])
		return false;
	
	date = std::make_tuple(year, month, day);
	return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueString, double& value)
{
	try
	{
		std::size_t last_num_index;
		value = std::stod(valueString, &last_num_index);
		if(last_num_index != valueString.size()) {
			std::cout << "Error: not a number.\n";
			return false;
		}
		if (value < 0) {
			std::cout << "Error: not a positive number.\n";
			return false;
		}
		if (value > 1000) {
			std::cout << "Error: too large a number.\n";
			return false;
		}
	}
	catch (const std::invalid_argument& e) {
		std::cout << "Error: not a number.\n";
		return false;
	}
	catch (const std::out_of_range& e) {
		std::cout << "Error: overflow occurred.\n";
		return false;
	}
	catch (const std::exception& e) {
		std::cout << "Error: other exceptions occurred.\n";
		return false;
	}
	return true;
}

bool BitcoinExchange::parseInput(const std::string& line, std::string& dateString,
	std::string& valueString, std::tuple<int, int, int>& date, double& value)
{
	if (!splitLine(line, dateString, valueString))
	{
		if (line.empty())
			std::cout << "Error: empty line.\n";
		else
			std::cout << "Error: bad input => " << line << '\n';
		return false;
	}

	if (!isValidDate(dateString, date))
	{
		std::cout << "Error: invalid date => " << dateString << '\n';
		return false;
	}

	if (!isValidValue(valueString, value))
		return false;
	
	return true;
}

double BitcoinExchange::findExchangeRate(const std::tuple<int, int, int>& date, const std::string& dateString)
{
	if (_exchangeRates.find(date) != _exchangeRates.end())
		return _exchangeRates[date];
	
	auto it = _exchangeRates.upper_bound(date);
	if (it == _exchangeRates.begin())
		throw std::runtime_error("exchange rate not available for date " + dateString);
	else
		--it;
	return it->second;
}

bool BitcoinExchange::processInputLine(const std::string& line)
{
	// parse the line
	std::string dateString, valueString;
	std::tuple<int, int, int> date;
	double value;
	if (!parseInput(line, dateString, valueString, date, value))
		return false;

	// calculate and print the result
	try
	{
		double exchangeRate = findExchangeRate(date, dateString);
		double res = value * exchangeRate;
		std::cout << dateString << " => " << valueString << " = " << res << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
	return true;
}

void BitcoinExchange::run(const std::string& filename)
{
	loadExchangeRates();

	std::ifstream inFile(filename);
	if (!inFile)
		throw std::runtime_error("could not open file " + filename);
	if (inFile.peek() == std::ifstream::traits_type::eof())
		throw std::runtime_error(filename + " is empty");

	std::string line;
	std::getline(inFile, line);
	if (line.compare("date | value") != 0) // validate the first line
		throw std::runtime_error(filename + " not valid => " + line);
	while (std::getline(inFile, line))
	{
		if (!processInputLine(line))
			continue ;
	}
}
