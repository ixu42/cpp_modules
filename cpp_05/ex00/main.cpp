/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:15:43 by ixu               #+#    #+#             */
/*   Updated: 2024/08/16 12:41:18 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void printString(const std::string& title)
{ 
	std::cout << std::endl << "\033[46;30m" << title << "\033[0m" << std:: endl;
}

static int testExceptionInConstructor()
{
	int status = 0;
	try
	{
		Bureaucrat foo = Bureaucrat("Foo", 1);
		Bureaucrat bar = Bureaucrat("Bar", 0); // grade too high
	}
	catch (std::exception & e)
	{
		std::cerr << "\033[0;31m" << "Error: " << e.what() << "\033[0m" << std:: endl;
		status = 1;
	}

	try
	{
		Bureaucrat foo = Bureaucrat("Foo", 150);
		Bureaucrat bar = Bureaucrat("Bar", 151); // grade too low
	}
	catch (std::exception & e)
	{
		std::cerr << "\033[0;31m" << "Error: " << e.what() << "\033[0m" << std:: endl;
		status = 1;
	}
	return status;
}

static int testChangingGrades()
{
	int status = 0;
	try
	{
		Bureaucrat foo = Bureaucrat("Foo", 43);
		std::cout << foo.getName() << "'s grade before increment: " << foo.getGrade() << std::endl;
		foo.incrementGrade();
		std::cout << foo.getName() << "'s grade after increment: " << foo.getGrade() << std::endl;

		Bureaucrat bar = Bureaucrat("Bar", 1);
		std::cout << bar.getName() << "'s grade before increment: " << bar.getGrade() << std::endl;
		bar.incrementGrade();
		std::cout << bar.getName() << "'s grade after increment: " << bar.getGrade() << std::endl;

	}
	catch (std::exception & e)
	{
		std::cerr << "\033[0;31m" << "Error: " << e.what() << "\033[0m" << std:: endl;
		status = 1;
	}

	try
	{
		Bureaucrat foo = Bureaucrat("Foo", 41);
		std::cout << foo.getName() << "'s grade before decrement: " << foo.getGrade() << std::endl;
		foo.decrementGrade();
		std::cout << foo.getName() << "'s grade after decrement: " << foo.getGrade() << std::endl;

		Bureaucrat bar = Bureaucrat("Bar", 150);
		std::cout << bar.getName() << "'s grade before decrement: " << bar.getGrade() << std::endl;
		bar.decrementGrade();
		std::cout << bar.getName() << "'s grade after decrement: " << bar.getGrade() << std::endl;

	}
	catch (std::exception & e)
	{
		std::cerr << "\033[0;31m" << "Error: " << e.what() << "\033[0m" << std:: endl;
		status = 1;
	}
	return status;
}

void testOperatorOverloading()
{
	Bureaucrat foo = Bureaucrat("Foo", 80);
	Bureaucrat bar = Bureaucrat("Bar", 120);
	std::cout << bar;
	bar = foo;
	std::cout << bar;
}

int main()
{
	int status = 0;

	printString("Exception in constructor");
	status = testExceptionInConstructor();

	printString("Exception in incrementGrade(), decrementGrade()");
	status = testChangingGrades();

	printString("Operator overloading");
	testOperatorOverloading();

	printString("Copy constructor");
	Bureaucrat foo = Bureaucrat("Foo", 25);
	Bureaucrat foo_cpy = Bureaucrat(foo);
	std::cout << "Original: " << foo;
	std::cout << "Copy: " << foo_cpy;

	return status;
}
