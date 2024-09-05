/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:27:10 by ixu               #+#    #+#             */
/*   Updated: 2024/09/05 13:44:15 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Error: invalid number of arguments" << std::endl;
		std::cout << "Usage: ./btc <filename>" << std::endl;
		return 1;
	}
	try
	{
		std::string input(argv[1]);
		BitcoinExchange::run(input);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "\033[0;32m" << "[ PRINTING MAP ]" << "\033[0m" << std::endl;
	for (auto& [key, value] : BitcoinExchange::getData())
		std::cout << key << ": " << value << std::endl;
}
