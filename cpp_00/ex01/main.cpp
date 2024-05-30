/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:59:18 by ixu               #+#    #+#             */
/*   Updated: 2024/05/30 21:24:49 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <cstdlib>
#include "PhoneBook.hpp"

void	exitOnInputReadFailure()
{
	if (std::cin.eof())
		std::cout << "\nEOF signal received. Exiting...\n";
	else
		std::cout << "\nError reading input. Exiting...\n";
	exit(1);
}

static int getIntegerFromUser()
{
	std::string	input;
	int			number;

	while (true)
	{
		std::cout << "\033[0;36m" << "Enter index of the entry to display: " << "\033[0m";
		if (!std::getline(std::cin, input))
			exitOnInputReadFailure();
		std::istringstream	iss(input);
		if (iss >> number)
			return number;
		else
			std::cout << "Invalid input. Please enter an integer." << std::endl;
	}
}

static void	search(PhoneBook &phoneBook)
{
	if (phoneBook.getContactCount() == 0)
	{
		std::cout << "No entry in the phonebook.\n"; 
		return ;
	}
	phoneBook.displayContacts();
	while (true)
	{
		int	index = getIntegerFromUser();
		if (phoneBook.getContact(index) == 0)
			break ;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		std::cout << "Invalid number of arguments\n";
		return (1);
	}
	std::string	command;
	PhoneBook	phoneBook;
	while (true)
	{
		std::cout << "\033[0;36m" << "Enter a command (ADD/SEARCH/EXIT): " << "\033[0m";
		if (!std::getline(std::cin, command))
			exitOnInputReadFailure();
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			search(phoneBook);
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}
