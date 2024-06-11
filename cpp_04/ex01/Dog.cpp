/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:55:54 by ixu               #+#    #+#             */
/*   Updated: 2024/06/11 15:36:57 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called\n";
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called\n";
	brain = new Brain(*other.brain);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
	delete brain;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator called\n";
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	*brain = *other.brain;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof!\n";
}

Brain*	Dog::getBrain()
{
	return (brain);
}
