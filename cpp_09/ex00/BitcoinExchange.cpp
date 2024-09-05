/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:27:14 by ixu               #+#    #+#             */
/*   Updated: 2024/09/05 16:07:15 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::tuple<int, int, int>, double> BitcoinExchange::_data;
std::map<std::tuple<int, int, int>, double> BitcoinExchange::_exchangeRates;

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange&) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange&)
{
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

const std::map<std::tuple<int, int, int>, double>& BitcoinExchange::getData()
{
	return _data;
}

const std::map<std::tuple<int, int, int>, double>& BitcoinExchange::getExchangeRates()
{
	return _exchangeRates;
}

void BitcoinExchange::loadExchangeRates()
{
	std::ifstream inFile("data.csv");

	if (!inFile)
		throw std::runtime_error("could not open file data.csv");

	std::string line;
	std::getline(inFile, line);
	while (std::getline(inFile, line)) // protect?
	{
		std::string dateString;
		std::string exchangeRateString;
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
}

bool BitcoinExchange::getDateValue(const std::string& line, std::string& dateString, std::string& valueString)
{
	std::size_t pos = line.find('|');
	if (pos != std::string::npos) {
		dateString = line.substr(0, pos);
		valueString = line.substr(pos + 1);
		dateString.erase(dateString.find_last_not_of(" \t\n\v\f\r") + 1);
		dateString.erase(0, dateString.find_first_not_of(" \t\n\v\f\r"));
		valueString.erase(valueString.find_last_not_of(" \t\n\v\f\r") + 1);
		valueString.erase(0, valueString.find_first_not_of(" \t\n\v\f\r"));
		if (dateString.empty() || valueString.empty())
			return false ;
		// std::cout << "date: " << date << std::endl;			
		// std::cout << "valueString: " << valueString << std::endl;
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
			std::cout << "Error: not a number" << std::endl;
			return false;
		}
		if (value < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			return false;
		}
		if (value > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			return false;
		}
	}
	catch (const std::invalid_argument& e) {
		std::cout << "Error: not a number" << std::endl;
		return false;
	}
	catch (const std::out_of_range& e) {
		std::cout << "Error: overflow occurred" << std::endl;
		return false;
	}
	catch (const std::exception& e) {
		std::cout << "Error: other exceptions occurred" << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::parseInput(const std::string& line, std::string& dateString,
	std::string& valueString, std::tuple<int, int, int>& date, double& value)
{
	if (!getDateValue(line, dateString, valueString))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return false;
	}

	if (!isValidDate(dateString, date))
	{
		std::cout << "Error: invalid date => " << dateString << std::endl;
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
		throw std::runtime_error("exchange rate not available for the date " + dateString);
	else
		--it;
	return it->second;
}

void BitcoinExchange::run(const std::string& filename)
{
	loadExchangeRates();

	std::ifstream inFile(filename);
	if (!inFile)
		throw std::runtime_error("could not open file " + filename);

	std::string line;
	std::getline(inFile, line);
	while (std::getline(inFile, line)) // protect?
	{
		// parse input
		std::string dateString;
		std::string valueString;
		std::tuple<int, int, int> date;
		double value;
		if (!parseInput(line, dateString, valueString, date, value))
			continue ;

		// store data in map
		_data[date] = value;

		// calculate and print the result
		try
		{
			double exchangeRate = findExchangeRate(date, dateString);
			double res = value * exchangeRate;
			std::cout << line << " => " << res << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
}
