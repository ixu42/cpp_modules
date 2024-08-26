/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:04:24 by ixu               #+#    #+#             */
/*   Updated: 2024/08/26 15:32:09 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <random>
#include <iostream>

#define RED "\033[0;31m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"

Base* generate(void)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 3);
	int random_number = dis(gen);
	switch (random_number) {
		case 1:
			return new A;
		case 2:
			return new B;
	}
	return new C;
}

void identify(Base* p)
{
	std::cout << CYAN << "Actual type of the object pointed to by p: ";

	A* ptrA = dynamic_cast<A*>(p);
	if (ptrA != nullptr) {
		std::cout << "\"A\"" << RESET << std::endl;
		return ;
	}

	B* ptrB = dynamic_cast<B*>(p);
	if (ptrB != nullptr) {
		std::cout << "\"B\"" << RESET << std::endl;
		return ;
	}

	C* ptrC = dynamic_cast<C*>(p);
	if (ptrC != nullptr) {
		std::cout << "\"C\"" << RESET << std::endl;
		return ;
	}

	std::cout << "unknown" << RESET << std::endl;
}

void identify(Base& p)
{
	std::cout << MAGENTA << "Actual type of the object referred to by p: ";
	try	{
		(void)dynamic_cast<A&>(p);
		std::cout << "\"A\"" << RESET << std::endl;
		return ;
	}
	catch(const std::bad_cast& e) {}
	catch(const std::exception& e) {
		std::cout << RED << "error: " << e.what() << RESET << std::endl;
	}
	try	{
		(void)dynamic_cast<B&>(p);
		std::cout << "\"B\"" << RESET << std::endl;
		return ;
	}
	catch(const std::bad_cast& e) {}
	catch(const std::exception& e) {
		std::cout << RED << "error: " << e.what() << RESET << std::endl;
	}
	try	{
		(void)dynamic_cast<C&>(p);
		std::cout << "\"C\"" << RESET << std::endl;
		return ;
	}
	catch(const std::bad_cast& e) {}
	catch(const std::exception& e) {
		std::cout << RED << "error: " << e.what() << RESET << std::endl;
	}
	std::cout << "unknown" << RESET << std::endl;
}

int main()
{
	Base* random = generate();
	identify(random);
	identify(*random);
	delete random;
}
