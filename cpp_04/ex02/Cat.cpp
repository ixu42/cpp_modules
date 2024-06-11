/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:55:57 by ixu               #+#    #+#             */
/*   Updated: 2024/06/11 13:18:01 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called\n";
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called\n";
	brain = new Brain(*other.brain);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
	delete brain;
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called\n";
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	*brain = *other.brain;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow~\n";
}

Brain*	Cat::getBrain()
{
	return (brain);
}
