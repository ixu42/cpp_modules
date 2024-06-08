/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:54:17 by ixu               #+#    #+#             */
/*   Updated: 2024/06/08 19:17:44 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Unknown")
{
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "Animal copy constructor called\n";
}

Animal::~Animal()
{
	std::cout << "Animal default destructor called\n";
}

Animal&	Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		this->type = other.type;
		std::cout << "Animal copy assignment operator called\n";
	}
	return (*this);
}

std::string	Animal::getType() const
{
	return (type);
}

void	Animal::makeSound() const
{
	std::cout << "Unknown sound...\n";
}
