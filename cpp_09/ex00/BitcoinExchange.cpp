/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:27:14 by ixu               #+#    #+#             */
/*   Updated: 2024/09/03 18:13:21 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): _data(other._data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this == &other)
		return *this;
	this->_data = other._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::run(const std::string& filename)
{
	std::ifstream inFile(filename);

	if (!inFile)
		throw std::runtime_error("could not open file " + filename);

	std::string line;
	while (std::getline(inFile, line)) // protect?
	{
		std::string date;
		std::string value;
		std::cout << line << std::endl;
		// split
		std::size_t pos = line.find('|');
		if (pos != std::string::npos)
		{
			date = line.substr(0, pos);
			value = line.substr(pos + 1);
			date.erase(date.find_last_not_of(" \t\n\v\f\r") + 1);
			date.erase(0, date.find_first_not_of(" \t\n\v\f\r"));
			value.erase(value.find_last_not_of(" \t\n\v\f\r") + 1);
			value.erase(0, value.find_first_not_of(" \t\n\v\f\r"));
			std::cout << date << std::endl;
			std::cout << value << std::endl;
		}
		else
			throw std::runtime_error("bad input => " + line);
		// validate date
		// validate value: std::stod
		// _data[date] = value;
	}
}
