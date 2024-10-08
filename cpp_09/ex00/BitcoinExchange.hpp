/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:27:12 by ixu               #+#    #+#             */
/*   Updated: 2024/09/16 18:26:16 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <fstream>
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

		static void processDataLine(const std::string&);
		static void loadExchangeRates();
		static bool splitLine(const std::string&, std::string&, std::string&);
		static bool isLeapYear(int);
		static bool isValidDate(const std::string&, std::tuple<int, int, int>&);
		static bool isValidValue(const std::string&, double&);
		static bool parseInput(const std::string&, std::string&,std::string&, \
								std::tuple<int, int, int>&, double&);
		static double findExchangeRate(const std::tuple<int, int, int>&, const std::string&);
		static bool processInputLine(const std::string&);

		static std::map<std::tuple<int, int, int>, double> _exchangeRates;
};
