/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:05:55 by ixu               #+#    #+#             */
/*   Updated: 2024/09/06 17:44:41 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <exception>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: invalid number of arguments" << std::endl;
		std::cout << "Usage: ./RPN \"<inverted Polish mathematical expression>\"" << std::endl;
		return 1;
	}
	std::string input(argv[1]);
	try
	{
		RPN::run(input);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
