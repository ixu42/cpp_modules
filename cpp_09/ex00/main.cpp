/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:27:10 by ixu               #+#    #+#             */
/*   Updated: 2024/09/08 11:16:16 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Error: invalid number of arguments.\n";
		std::cout << "Usage: ./btc <filename>\n";
		return 1;
	}
	try
	{
		std::string input(argv[1]);
		BitcoinExchange::run(input);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
		return 1;
	}
}
