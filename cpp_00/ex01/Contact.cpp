/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:02:09 by ixu               #+#    #+#             */
/*   Updated: 2024/05/28 17:12:28 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact() 
	: firstName(""), lastName(""), nickName(""), phoneNumber(""), darkestSecret("") {}

void	Contact::displayContactInfo()
{
	std::cout << std::left;
	std::cout << std::setw(15) << "FirstName: " << firstName << std::endl;
	std::cout << std::setw(15) << "LastName: " << lastName << std::endl;
	std::cout << std::setw(15) << "NickName: " << nickName << std::endl;
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
		case NickName:
			std::cout << std::setw(15) << "NickName: ";
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
		case NickName:
			nickName = data;
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
