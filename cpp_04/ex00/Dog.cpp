/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:55:54 by ixu               #+#    #+#             */
/*   Updated: 2024/06/08 19:17:27 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called\n";
}

Dog::~Dog()
{
	std::cout << "Dog default destructor called\n";
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		std::cout << "Dog copy assignment operator called\n";
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof!\n";
}
