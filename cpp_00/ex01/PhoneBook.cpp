/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:00:35 by ixu               #+#    #+#             */
/*   Updated: 2024/05/27 16:57:40 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string.h>

PhoneBook::PhoneBook()
{
	memset(contacts, 0, sizeof(contacts));
	contactCount = 0;
}

void	PhoneBook::addContact(void)
{
	std::string	input;

	if (contactCount == 8)
		contactCount = 0;
	for (int i = 0; i < 5; i++)
	{
		std::cin >> input;
		if (input == "")
			std::cout << "A saved contact can't have empty fields.\n";
		else
		{
			if (i == 0)
				contacts[contactCount].firstName = input;
			else if (i == 1)
				contacts[contactCount].lastName = input;
			else if (i == 2)
				contacts[contactCount].nickName = input;
			else if (i == 3)
				contacts[contactCount].phoneNumber = input;
			else if (i == 4)
				contacts[contactCount].darkestSecret = input;
		}
	}
	contactCount++;
}
