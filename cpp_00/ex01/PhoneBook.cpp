/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:00:35 by ixu               #+#    #+#             */
/*   Updated: 2024/05/30 12:11:27 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0), oldestContactIndex(0) {}

void	PhoneBook::addContact()
{
	std::string	input;
	Contact		newContact;

	if (oldestContactIndex == 8)
		oldestContactIndex = 0;
	int	i = 0;
	while (i < 5)
	{
		newContact.promptField(i);
		std::getline(std::cin, input);
		if (input == "")
		{
			std::cout << "A saved contact can't have empty fields.\n";
			continue ;
		}
		else
			newContact.fillField(i, input);
		i++;
	}
	contacts[oldestContactIndex] = newContact;
	if (contactCount < 8)
		contactCount++;
	oldestContactIndex++;
}

void	PhoneBook::displayContacts()
{
	std::cout << std::setw(10) << std::right << "Index" << "|"
				<< std::setw(10) << "FirstName" << "|"
				<< std::setw(10) << "LastName" << "|"
				<< std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < contactCount; i++)
	{
		std::cout << std::right 
					<< std::setw(10) << i << "|"
					<< std::setw(10) << formatStr(contacts[i].firstName) << "|"
					<< std::setw(10) << formatStr(contacts[i].lastName) << "|"
					<< std::setw(10) << formatStr(contacts[i].nickname) << std::endl;
	}
}

std::string	PhoneBook::formatStr(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

int	PhoneBook::getContact(int index)
{
	if (index >= contactCount || index < 0)
	{
		std::cout << "Index out of range." << std::endl;
		return (-1);
	}
	else
		contacts[index].displayContactInfo();
	return (0);
}

int	PhoneBook::getContactCount()
{
	return (contactCount);
}