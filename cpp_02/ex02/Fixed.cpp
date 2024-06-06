/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:25:41 by ixu               #+#    #+#             */
/*   Updated: 2024/06/06 11:42:36 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/* CONSTRUCTORS */

Fixed::Fixed() : fixedPointValue(0) {}

Fixed::Fixed(const int value)
{
	this->fixedPointValue = value << this->fractionalBits;
}

Fixed::Fixed(const float value)
{
	float	rounded = roundf((value * (1 << this->fractionalBits)));
	this->fixedPointValue = static_cast<int>(rounded);
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

/* DESTRUCTOR */

Fixed::~Fixed() {}

/* OVERLOADING OPERATORS */

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		this->fixedPointValue = other.getRawBits();
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, const Fixed& num)
{
	stream << num.toFloat();
	return (stream);
}

// Overloading 6 comparison operators: >, <, >=, <=, == and !=

bool	Fixed::operator>(const Fixed& other)
{
	return (this->fixedPointValue > other.fixedPointValue);
}

bool	Fixed::operator<(const Fixed& other)
{
	return (this->fixedPointValue < other.fixedPointValue);
}

bool	Fixed::operator>=(const Fixed& other)
{
	return (this->fixedPointValue >= other.fixedPointValue);
}

bool	Fixed::operator<=(const Fixed& other)
{
	return (this->fixedPointValue <= other.fixedPointValue);
}

bool	Fixed::operator==(const Fixed& other)
{
	return (this->fixedPointValue == other.fixedPointValue);
}

bool	Fixed::operator!=(const Fixed& other)
{
	return (this->fixedPointValue != other.fixedPointValue);
}

// Overloading 4 arithmetic operators: +, -, *, and /

Fixed	Fixed::operator+(const Fixed& other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	if (other.fixedPointValue == 0)
	{
		std::cout << "Cannot divide by ";
		return (0);
	}
	return (Fixed(this->toFloat() / other.toFloat()));
}

// Overloading pre-increment operator

Fixed&	Fixed::operator++()
{
	++fixedPointValue;
	return (*this);
}

// Overloading post-increment operator

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	++(*this);
	return (temp);
}

// Overloading pre-decrement operator

Fixed&	Fixed::operator--()
{
	--fixedPointValue;
	return (*this);
}

// Overloading post-decrement operator

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	--(*this);
	return (temp);
}

/* OVERLOADED MEMBER FUNCS ON MAX, MIN */

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}

/* OTHER MEMBER FUNCS */

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
