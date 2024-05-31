/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:46:11 by ixu               #+#    #+#             */
/*   Updated: 2024/05/31 15:49:50 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>

int	main()
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << std::left;

	// memory addresses
	std::cout << std::setw(31) << "Address of string variable: " << &str << std::endl;
	std::cout << std::setw(31) << "Address held by stringPTR: " << stringPTR << std::endl;
	std::cout << std::setw(31) << "Address held by stringREF: " << &stringREF << std::endl;

	// values
	std::cout << std::setw(31) << "Value of string variable: " << str << std::endl;
	std::cout << std::setw(31) << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << std::setw(31) << "Value pointed to by stringREF: " << stringREF << std::endl;

	return (0);
}
