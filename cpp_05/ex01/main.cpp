/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:15:43 by ixu               #+#    #+#             */
/*   Updated: 2024/08/23 22:04:41 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void printString(const std::string& msg, const std::string& color)
{
	std::cout << std::endl << color << msg << RESET << std:: endl;
}

static void testExceptionInConstructor()
{
	try
	{
		Bureaucrat foo = Bureaucrat("Foo", 1);
		Bureaucrat bar = Bureaucrat("Bar", 0); // grade too high
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std:: endl;
	}

	try
	{
		Bureaucrat foo = Bureaucrat("Foo", 150);
		Bureaucrat bar = Bureaucrat("Bar", 151); // grade too low
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std:: endl;
	}
}

static void testChangingGrades()
{
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
	catch (const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std:: endl;
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
	catch (const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std:: endl;
	}
}

static void testOperatorOverloading()
{
	Bureaucrat foo = Bureaucrat("Foo", 80);
	Bureaucrat bar = Bureaucrat("Bar", 120);
	std::cout << bar;
	bar = foo;
	std::cout << bar;
}

static void testForEx00()
{
	printString("Exception in constructor", CYAN_BG);
	testExceptionInConstructor();

	printString("Exception in incrementGrade(), decrementGrade()", CYAN_BG);
	testChangingGrades();

	printString("Operator overloading", CYAN_BG);
	testOperatorOverloading();

	printString("Copy constructor", CYAN_BG);
	{
		Bureaucrat foo = Bureaucrat("Foo", 25);
		Bureaucrat foo_cpy = Bureaucrat(foo);
		std::cout << "Original: " << foo;
		std::cout << "Copy: " << foo_cpy;
	}

	printString("Default constructor", CYAN_BG);
	{
		Bureaucrat random = Bureaucrat();
		std::cout << random;
	}
}

static void testFormConstructors()
{
	printString("Form parameterized constructor", CYAN);
	{
		try
		{
			Form a = Form("a", 150, 1);
			Form b = Form("b", 0, 1); // grade too high
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << "Error: " << e.what() << RESET << std:: endl;
		}
	}

	printString("Form copy constructor", CYAN);
	{
		Form a = Form("a", 42, 42);
		Form b = Form(a);
		std::cout << "Original:\n" << a;
		std::cout << "Copy:\n" << b;
	}

	printString("Form default constructor", CYAN);
	{
		Form random = Form();
		std::cout << random;
	}
}

static void testFormOperatorOverloading()
{
	Form form_a = Form("a", 1, 2);
	Bureaucrat foo = Bureaucrat("Foo", 1);
	foo.signForm(form_a);
	std::cout << form_a;

	Form form_b = Form("b", 2, 3);
	std::cout << form_b;
	form_b = form_a;  // will only copy boolean _isSigned
	std::cout << form_b;
}

int main()
{
	printString("TESTS FOR EX00", YELLOW_BG);
	testForEx00();

	printString("TESTS FOR EX01", YELLOW_BG);

	printString("Form constructors", CYAN_BG);
	testFormConstructors();

	printString("Form Operator overloading", CYAN_BG);
	testFormOperatorOverloading();

	printString("Bureaucrat::signForm(), Form::beSigned()", CYAN_BG);
	{
		Bureaucrat foo = Bureaucrat("Foo", 43);
		Bureaucrat bar = Bureaucrat("Bar", 41);
		Form a = Form("a", 42, 42);
		foo.signForm(a);
		bar.signForm(a);
	}

	printString("Getters", CYAN_BG);
	{
		Form a = Form("a", 42, 42);
		std::cout << a.getName() << std::endl;
		std::cout << a.getIsSigned() << std::endl;
		std::cout << a.getGradeToSign() << std::endl;
		std::cout << a.getGradeToExecute() << std::endl;
	}
}
