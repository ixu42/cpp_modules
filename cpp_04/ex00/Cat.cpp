/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:55:57 by ixu               #+#    #+#             */
/*   Updated: 2024/06/11 16:11:08 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called\n";
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called\n";
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow~\n";
}
