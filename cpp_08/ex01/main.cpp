/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:21:08 by ixu               #+#    #+#             */
/*   Updated: 2024/09/03 18:50:12 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <numeric> // std::iota

static void printString(const std::string& message)
{
	std::cout << "\033[0;36m" << "[ " << message << " ]" << "\033[0m" << std::endl;
}

static void testsFromSubject()
{
	printString("Tests from subject");
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;	
}

static void basictests()
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		printString("Default constructor");
		Span spDefault;
		std::cout << spDefault;

		printString("Copy constructor");
		Span spCopy1(sp);
		std::cout << "sp " << sp;
		std::cout << "spCopy1 " << spCopy1;

		printString("Copy assignment");
		Span spCopy2 = sp;
		std::cout << "spCopy2 " << spCopy2;

		printString("Exception in addNumber()");
		sp.addNumber(1);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

static void testLargeVector()
{
	try
	{
		printString("Filling Span using a range of iterators");
		unsigned int size = 1000000;
		std::vector<int> nums(size);
		std::iota(nums.begin(), nums.end(), 1);

		Span spLarge(size);
		spLarge.addNumbers(nums.begin(), nums.end());
		std::cout << "Shortest span: " << spLarge.shortestSpan() << std::endl;
		std::cout << "Longest span: " << spLarge.longestSpan() << std::endl;

		printString("Exception in addNumbers()");
		spLarge.addNumbers(nums.begin(), nums.end());
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

int main()
{
	testsFromSubject();
	basictests();
	testLargeVector();

	try
	{
		printString("Exception in shortestSpan()");
		Span sp;
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		printString("Exception in longestSpan()");
		Span sp = Span(1);
		sp.addNumber(42);
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}
