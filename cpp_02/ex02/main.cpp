/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:25:34 by ixu               #+#    #+#             */
/*   Updated: 2024/06/06 11:43:46 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main()
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << "\nADDITIONAL TESTS \n";
	std::cout << "\nComparison operators: \n";
	std::cout << "a > b: " << (a > b) << std::endl; // should eval to 0
	std::cout << "a >= b: " << (a >= b) << std::endl; // should eval to 0
	std::cout << "a < b: " << (a < b) << std::endl; // should eval to 1
	std::cout << "a <= b: " << (a <= b) << std::endl; // should eval to 1
	std::cout << "a == b: " << (a == b) << std::endl; // should eval to 0
	std::cout << "a != b: " << (a != b) << std::endl; // should eval to 1
	
	std::cout << "\nArithmetic operators:\n";
	Fixed	c(10);
	Fixed	d(2);
	std::cout << "c + d: " << (c + d) << std::endl; // should yield 12
	std::cout << "c - d: " << (c - d) << std::endl; // should yield 8
	std::cout << "c * d: " << (c * d) << std::endl; // should yield 20
	std::cout << "c / d: " << (c / d) << std::endl; // should yield 5
	Fixed	e(6.6f);
	Fixed	f(3.3f);
	std::cout << "e + f: " << (e + f) << std::endl; // should yield approx. 9.9
	std::cout << "e - f: " << (e - f) << std::endl; // should yield approx. 3.3
	std::cout << "e * f: " << (e * f) << std::endl; // should yield approx. 21.8
	std::cout << "e / f: " << (e / f) << std::endl; // should yield 2
	Fixed	zero(0);
	std::cout << "c / zero: " << (c / zero) << std::endl;

	return (0);
}
