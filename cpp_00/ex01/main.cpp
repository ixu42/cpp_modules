/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:59:18 by ixu               #+#    #+#             */
/*   Updated: 2024/05/27 16:56:54 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	std::string	command;
	PhoneBook phoneBook;
	while (true)
	{
		std::cout << "Enter a command (ADD/SEARCH/EXIT): ";
		std::cin >> command;
		if (command == "ADD")
		phoneBook.addContact();
		else if (command == "SEARCH")
			std::cout << "SEARCH entered" << std::endl; // remove
		else if (command == "EXIT")
			break ;
		else
		{
			std::cout << "Invalid command!" << std::endl;
			std::cout << "Please enter one of the three commands: ADD/SEARCH/EXIT" << std::endl;
		}
	}
	std::cout << "Exiting program..." << std::endl;
	return (0);
}
