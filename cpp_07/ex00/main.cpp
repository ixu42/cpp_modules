/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:47:02 by ixu               #+#    #+#             */
/*   Updated: 2024/08/29 22:05:18 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <memory>

#define GREEN "\033[0;32m"
#define GREEN_BG "\033[0;42m"
#define RESET "\033[0m"

static void printString(const std::string& message, const std::string& colorCode)
{
	std::cout << colorCode << "[ " << message << " ]" << RESET << std::endl;
}

static void testsFromSubject()
{
	printString("int", GREEN);
	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	printString("std::string", GREEN);
	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
}

static void AdditionalTests()
{
	printString("double", GREEN);
	double e = 1.1;
	double f = 2.2;

	::swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
	std::cout << "max(e, f) = " << ::max(e, f) << std::endl;

	printString("float", GREEN);
	float g = 4.2f;
	float h = 3.14f;
	::swap( g, h );
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "min(g, h) = " << ::min(g, h) << std::endl;
	std::cout << "max(g, h) = " << ::max(g, h) << std::endl;

	printString("char", GREEN);
	char i = 'b';
	char j = 'z';
	::swap(i, j);
	std::cout << "i = " << i << ", j = " << j << std::endl;
	std::cout << "min(i, j) = " << ::min(i, j) << std::endl;
	std::cout << "max(i, j) = " << ::max(i, j) << std::endl;

	printString("std::unique_ptr<int>", GREEN);
	auto k = std::make_unique<int>(1);
	auto l = std::make_unique<int>(2);
	std::cout << "*k = " << *k << ", *l = " << *l << std::endl;
	std::swap(*k, *l);
	std::cout << "*k = " << *k << ", *l = " << *l << std::endl;
	std::cout << "min(*k, *l) = " << std::min(*k, *l) << std::endl;
	std::cout << "max(*k, *l) = " << std::max(*k, *l) << std::endl;
}

int main()
{
	printString("Tests from the subject", GREEN_BG);
	testsFromSubject();

	printString("Additional tests", GREEN_BG);
	AdditionalTests();
}
