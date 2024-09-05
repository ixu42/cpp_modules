/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:27:14 by ixu               #+#    #+#             */
/*   Updated: 2024/09/05 13:44:22 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, double> BitcoinExchange::_data;

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange&) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange&)
{
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidValue(const std::string& valueString, double& value)
{
	try
	{
		std::size_t last_num_index;
		value = std::stod(valueString, &last_num_index);
		if( last_num_index != valueString.size()) {
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

bool BitcoinExchange::isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
	// regular expression to match the date format: YYYY-MM-DD
	const std::regex datePattern(R"(^(\d{4})-(\d{2})-(\d{2})$)");
	std::smatch match;

	if (!std::regex_match(date, match, datePattern))
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
	
	return true;
}

void BitcoinExchange::run(const std::string& filename)
{
	std::ifstream inFile(filename);

	if (!inFile)
		throw std::runtime_error("could not open file " + filename);

	std::string line;
	std::getline(inFile, line);
	while (std::getline(inFile, line)) // protect?
	{
		std::string date;
		std::string valueString;
		// split the line
		std::size_t pos = line.find('|');
		if (pos != std::string::npos) {
			date = line.substr(0, pos);
			valueString = line.substr(pos + 1);
			date.erase(date.find_last_not_of(" \t\n\v\f\r") + 1);
			date.erase(0, date.find_first_not_of(" \t\n\v\f\r"));
			valueString.erase(valueString.find_last_not_of(" \t\n\v\f\r") + 1);
			valueString.erase(0, valueString.find_first_not_of(" \t\n\v\f\r"));
			if (date.empty() || valueString.empty()) {
				std::cout << "Error: bad input => " << line << std::endl;
				continue ;
			}
			// std::cout << "date: " << date << std::endl;			
			// std::cout << "valueString: " << valueString << std::endl;
		}
		else {
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		if (!isValidDate(date))	{
			std::cout << "Error: invalid date => " << date << std::endl;
			continue ;
		}
		double value;
		if (!isValidValue(valueString, value))
			continue ;
		std::cout << line << std::endl;
		_data[date] = value;
	}
}

const std::map<std::string, double>& BitcoinExchange::getData()
{
	return _data;
}
