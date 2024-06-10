/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:39:21 by ixu               #+#    #+#             */
/*   Updated: 2024/06/10 11:43:48 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "WrongCat default constructor called\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat default destructor called\n";
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat copy assignment operator called\n";
	if (this == &other)
		return (*this);
	WrongAnimal::operator=(other);
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Meow~\n";
}
