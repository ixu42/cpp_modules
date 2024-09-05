/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:27:12 by ixu               #+#    #+#             */
/*   Updated: 2024/09/05 15:43:08 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <map>
#include <tuple>
#include <regex>

class BitcoinExchange
{
	public:
		static void run(const std::string&);

		static const std::map<std::tuple<int, int, int>, double>& getData();
		static const std::map<std::tuple<int, int, int>, double>& getExchangeRates();

	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange&);
		BitcoinExchange& operator=(const BitcoinExchange&);
		~BitcoinExchange();

		static bool isLeapYear(int);
		static bool isValidDate(const std::string&, std::tuple<int, int, int>&);
		static bool isValidValue(const std::string&, double&);

		static void loadExchangeRates();
		static double findExchangeRate(const std::tuple<int, int, int>&, const std::string&);

		static std::map<std::tuple<int, int, int>, double> _data;
		static std::map<std::tuple<int, int, int>, double> _exchangeRates;
};
