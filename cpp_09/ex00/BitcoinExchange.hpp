/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:27:12 by ixu               #+#    #+#             */
/*   Updated: 2024/09/05 13:44:20 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <map>
#include <regex>

class BitcoinExchange
{
	public:
		static void run(const std::string&);

		static const std::map<std::string, double>& getData();

	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange&);
		BitcoinExchange& operator=(const BitcoinExchange&);
		~BitcoinExchange();

		static bool isLeapYear(int);
		static bool isValidDate(const std::string&);
		static bool isValidValue(const std::string&, double&);

		static std::map<std::string, double> _data;
};
