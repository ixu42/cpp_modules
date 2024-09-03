/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:27:14 by ixu               #+#    #+#             */
/*   Updated: 2024/09/03 15:11:29 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::run(const std::string& filename)
{
	std::ifstream inFile(filename);

	if (!inFile)
		throw std::runtime_error("Could not open file " + filename);

	std::stringstream buffer;
	buffer << inFile.rdbuf();
	std::cout << buffer.str() << std::endl;
}
