/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:02:09 by ixu               #+#    #+#             */
/*   Updated: 2024/05/30 21:31:12 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact() 
	: firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

void	Contact::displayContactInfo()
{
	std::cout << std::left;
	std::cout << std::setw(15) << "FirstName: " << firstName << std::endl;
	std::cout << std::setw(15) << "LastName: " << lastName << std::endl;
	std::cout << std::setw(15) << "Nickname: " << nickname << std::endl;
	std::cout << std::setw(15) << "PhoneNumber: " << phoneNumber << std::endl;
	std::cout << std::setw(15) << "DarkestSecret: " << darkestSecret << std::endl;
}

void	Contact::promptField(int field)
{
	std::cout << std::left;
	switch (field)
	{
		case FirstName:
			std::cout << std::setw(15) << "FirstName: ";
			break;
		case LastName:
			std::cout << std::setw(15) << "LastName: ";
			break;
		case Nickname:
			std::cout << std::setw(15) << "Nickname: ";
			break;
		case PhoneNumber:
			std::cout << std::setw(15) << "PhoneNumber: ";
			break;
		case DarkestSecret:
			std::cout << std::setw(15) << "DarkestSecret: ";
			break;
		default:
			std::cout << "Invalid field" << std::endl;
			break;
	}
}

void	Contact::fillField(int field, std::string &data)
{
	switch (field)
	{
		case FirstName:
			firstName = data;
			break ;
		case LastName:
			lastName = data;
			break ;
		case Nickname:
			nickname = data;
			break ;
		case PhoneNumber:
			phoneNumber = data;
			break ;
		case DarkestSecret:
			darkestSecret = data;
			break ;
		default:
			std::cout << "Invalid field" << std::endl;
			break;
	}
}

std::string	Contact::getFirstName()
{
	return (firstName);
}

std::string	Contact::getLastName()
{
	return (lastName);
}

std::string	Contact::getNickname()
{
	return (nickname);
}
