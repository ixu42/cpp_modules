/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:15:43 by ixu               #+#    #+#             */
/*   Updated: 2024/08/21 17:39:15 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <memory>

static void printString(const std::string& msg, const std::string& color)
{
	std::cout << color << msg << RESET << std::endl;
}

// static void testExceptionInConstructor()
// {
// 	try
// 	{
// 		Bureaucrat foo = Bureaucrat("Foo", 1);
// 		Bureaucrat bar = Bureaucrat("Bar", 0); // grade too high
// 	}
// 	catch (std::exception & e)
// 	{
// 		std::cerr << RED << "Error: " << e.what() << RESET << std:: endl;
// 	}

// 	try
// 	{
// 		Bureaucrat foo = Bureaucrat("Foo", 150);
// 		Bureaucrat bar = Bureaucrat("Bar", 151); // grade too low
// 	}
// 	catch (std::exception & e)
// 	{
// 		std::cerr << RED << "Error: " << e.what() << RESET << std:: endl;
// 	}
// }

// static void testChangingGrades()
// {
// 	try
// 	{
// 		Bureaucrat foo = Bureaucrat("Foo", 43);
// 		std::cout << foo.getName() << "'s grade before increment: " << foo.getGrade() << std::endl;
// 		foo.incrementGrade();
// 		std::cout << foo.getName() << "'s grade after increment: " << foo.getGrade() << std::endl;

// 		Bureaucrat bar = Bureaucrat("Bar", 1);
// 		std::cout << bar.getName() << "'s grade before increment: " << bar.getGrade() << std::endl;
// 		bar.incrementGrade();
// 		std::cout << bar.getName() << "'s grade after increment: " << bar.getGrade() << std::endl;

// 	}
// 	catch (std::exception & e)
// 	{
// 		std::cerr << RED << "Error: " << e.what() << RESET << std:: endl;
// 	}

// 	try
// 	{
// 		Bureaucrat foo = Bureaucrat("Foo", 41);
// 		std::cout << foo.getName() << "'s grade before decrement: " << foo.getGrade() << std::endl;
// 		foo.decrementGrade();
// 		std::cout << foo.getName() << "'s grade after decrement: " << foo.getGrade() << std::endl;

// 		Bureaucrat bar = Bureaucrat("Bar", 150);
// 		std::cout << bar.getName() << "'s grade before decrement: " << bar.getGrade() << std::endl;
// 		bar.decrementGrade();
// 		std::cout << bar.getName() << "'s grade after decrement: " << bar.getGrade() << std::endl;

// 	}
// 	catch (std::exception & e)
// 	{
// 		std::cerr << RED << "Error: " << e.what() << RESET << std:: endl;
// 	}
// }

// static void testOperatorOverloading()
// {
// 	Bureaucrat foo = Bureaucrat("Foo", 80);
// 	Bureaucrat bar = Bureaucrat("Bar", 120);
// 	std::cout << bar;
// 	bar = foo;
// 	std::cout << bar;
// }

// static void testForEx00()
// {
// 	printString("Exception in constructor", CYAN_BG);
// 	testExceptionInConstructor();

// 	printString("Exception in incrementGrade(), decrementGrade()", CYAN_BG);
// 	testChangingGrades();

// 	printString("Operator overloading", CYAN_BG);
// 	testOperatorOverloading();

// 	printString("Copy constructor", CYAN_BG);
// 	{
// 		Bureaucrat foo = Bureaucrat("Foo", 25);
// 		Bureaucrat foo_cpy = Bureaucrat(foo);
// 		std::cout << "Original: " << foo;
// 		std::cout << "Copy: " << foo_cpy;
// 	}

// 	printString("Default constructor", CYAN_BG);
// 	{
// 		Bureaucrat random = Bureaucrat();
// 		std::cout << random;
// 	}
// }

// static void testFormConstructors()
// {
// 	printString("Form parameterized constructor", CYAN);
// 	{
// 		try
// 		{
// 			Form a = Form("a", 150, 1);
// 			Form b = Form("a", 0, 1); // grade to high
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << RED << "Error: " << e.what() << RESET << std:: endl;
// 		}
// 	}

// 	printString("Form copy constructor", CYAN);
// 	{
// 		Form a = Form("a", 42, 42);
// 		Form b = Form(a);
// 		std::cout << "Original:\n" << a;
// 		std::cout << "Copy:\n" << b;
// 	}

// 	printString("Form default constructor", CYAN);
// 	{
// 		Form random = Form();
// 		std::cout << random;
// 	}
// }

int main()
{
	// printString("TESTS FOR EX00", YELLOW_BG);
	// testForEx00();

	// printString("TESTS FOR EX01", YELLOW_BG);

	// printString("Form constructors", CYAN_BG);
	// testFormConstructors();

	// printString("Operator overloading", CYAN_BG);
	// {
	// 	Form a = Form("a", 1, 2);
	// 	Form b = Form("b", 2, 3);
	// 	std::cout << b;
	// 	b = a;
	// 	std::cout << b;
	// }

	// printString("Bureaucrat::signForm(), Form::beSigned(), getters", CYAN_BG);
	// {
	// 	Bureaucrat foo = Bureaucrat("Foo", 43);
	// 	Bureaucrat bar = Bureaucrat("Bar", 41);
	// 	Form a = Form("a", 42, 42);
	// 	foo.signForm(a);
	// 	bar.signForm(a);
	// }

	// printString("Getters", CYAN_BG);
	// {
	// 	Form a = Form("a", 42, 42);
	// 	std::cout << a.getName() << std::endl;
	// 	std::cout << a.getIsSigned() << std::endl;
	// 	std::cout << a.getGradeToSign() << std::endl;
	// 	std::cout << a.getGradeToExecute() << std::endl;
	// }

	printString("ShrubberyCreationForm::execute()", CYAN_BG);
	try
	{
		Bureaucrat foo = Bureaucrat("Foo", 42);
		std::unique_ptr<AForm> home_shrubbery(new ShrubberyCreationForm("home"));
		foo.signForm(*home_shrubbery);
		home_shrubbery->execute(foo);
		printString("ShrubberyCreationForm executed for home_shrubbery ✅", GREEN);

		std::unique_ptr<AForm> office_shrubbery(new ShrubberyCreationForm("office"));
		office_shrubbery->execute(foo);
		printString("ShrubberyCreationForm executed for office_shrubbery✅", GREEN);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	try
	{
		Bureaucrat bar = Bureaucrat("Bar", 140);
		std::unique_ptr<AForm> park_shrubbery(new ShrubberyCreationForm("park"));
		bar.signForm(*park_shrubbery);
		park_shrubbery->execute(bar);
		printString("ShrubberyCreationForm executed for park_shrubbery ✅", GREEN);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	printString("Bureaucrat::executeForm()", CYAN_BG);
	try
	{
		Bureaucrat foo = Bureaucrat("Foo", 42);
		std::unique_ptr<AForm> home_shrubbery(new ShrubberyCreationForm("home"));
		foo.executeForm(*home_shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	printString("RobotomyRequestForm::execute()", CYAN_BG);
	try
	{
		Bureaucrat foo = Bureaucrat("Foo", 42);
		std::unique_ptr<AForm> baz(new RobotomyRequestForm("Baz"));
		foo.signForm(*baz);
		baz->execute(foo);
		printString("RobotomyRequestForm executed for Baz ✅", GREEN);

		std::unique_ptr<AForm> bar(new RobotomyRequestForm("Bar"));
		bar->execute(foo);
		printString("RobotomyRequestForm executed for Bar ✅", GREEN);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	try
	{
		Bureaucrat alice = Bureaucrat("Alice", 46);
		std::unique_ptr<AForm> bob(new RobotomyRequestForm("Bob"));
		alice.signForm(*bob);
		bob->execute(alice);
		printString("RobotomyRequestForm executed for bob ✅", GREEN);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}
