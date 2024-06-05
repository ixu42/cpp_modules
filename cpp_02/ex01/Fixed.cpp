/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:51:39 by ixu               #+#    #+#             */
/*   Updated: 2024/06/05 15:50:43 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Constructors

Fixed::Fixed() : fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue = value << this->fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	float	rounded = roundf((value * (1 << this->fractionalBits)));
	this->fixedPointValue = static_cast<int>(rounded);
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Destructor

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Copy assignment operator overload

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		this->fixedPointValue = other.getRawBits();
	}
	return (*this);
}

// Insertion («) operator overload

std::ostream&	operator<<(std::ostream& stream, const Fixed& num)
{
	stream << num.toFloat();
	return (stream);
}

// Member functions

int	Fixed::getRawBits(void) const
{
	return (this->fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixedPointValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->fixedPointValue) / (1 << this->fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->fixedPointValue >> this->fractionalBits);
}
