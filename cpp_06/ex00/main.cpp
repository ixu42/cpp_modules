/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:19:19 by ixu               #+#    #+#             */
/*   Updated: 2024/08/25 23:42:48 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		std::cout << "Usage: ./convert <input>" << std::endl;
		return 1;
	}
	const std::string input(argv[1]);
	ScalarConverter::convert(input);
}
