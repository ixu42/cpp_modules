/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:15:43 by ixu               #+#    #+#             */
/*   Updated: 2024/08/23 16:32:12 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <memory>

static void printString(const std::string& msg, const std::string& color)
{
	std::cout << std::endl << color << msg << RESET << std::endl;
}

static void testExceptionInConstructor()
{
	try
	{
		Bureaucrat foo = Bureaucrat("Foo", 1);
		Bureaucrat bar = Bureaucrat("Bar", 0); // grade too high
	}
	catch (std::exception & e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std:: endl;
	}

	try
	{
		Bureaucrat foo = Bureaucrat("Foo", 150);
		Bureaucrat bar = Bureaucrat("Bar", 151); // grade too low
	}
	catch (std::exception & e)
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
	catch (std::exception & e)
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
	catch (std::exception & e)
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

static void testsForBureaucrat()
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

static void	testShrubberyCreationForm()
{
	printString("ShrubberyCreationForm::execute()", CYAN_BG);

	Bureaucrat foo = Bureaucrat("Foo", 42);
	std::unique_ptr<AForm> form_0 = std::make_unique<ShrubberyCreationForm>("home");
	foo.signForm(*form_0);
	foo.executeForm(*form_0); // should succeed

	std::unique_ptr<AForm> form_1 = std::make_unique<ShrubberyCreationForm>("office");
	foo.executeForm(*form_1); // should fail, as form is not signed

	Bureaucrat bar = Bureaucrat("Bar", 140);
	std::unique_ptr<AForm> form_2 = std::make_unique<ShrubberyCreationForm>("park");
	bar.signForm(*form_2);
	bar.executeForm(*form_2); // should fail, as grade is not enough for execution
}

static void testRobotomyRequestForm()
{
	printString("RobotomyRequestForm::execute()", CYAN_BG);

	Bureaucrat foo = Bureaucrat("Foo", 42);
	std::unique_ptr<AForm> form_0 = std::make_unique<RobotomyRequestForm>("Baz");
	foo.signForm(*form_0);
	foo.executeForm(*form_0); // should succeed

	std::unique_ptr<AForm> form_1 = std::make_unique<RobotomyRequestForm>("Bar");
	foo.executeForm(*form_1); // should fail, as form is not signed

	Bureaucrat alice = Bureaucrat("Alice", 46);
	std::unique_ptr<AForm> form_2 = std::make_unique<RobotomyRequestForm>("Bob");
	alice.signForm(*form_2);
	alice.executeForm(*form_2); // should fail, as grade is not enough for execution 
}

static void testPresidentialPardonForm()
{
	printString("PresidentialPardonForm::execute()", CYAN_BG);

	Bureaucrat foo = Bureaucrat("Foo", 1);
	std::unique_ptr<AForm> form_0 = std::make_unique<PresidentialPardonForm>("Baz");
	foo.signForm(*form_0);
	foo.executeForm(*form_0); // should succeed

	std::unique_ptr<AForm> form_1 = std::make_unique<PresidentialPardonForm>("Bar");
	foo.executeForm(*form_1); // should fail, as form is not signed

	Bureaucrat charlie = Bureaucrat("Charlie", 10);
	std::unique_ptr<AForm> form_2 = std::make_unique<PresidentialPardonForm>("David");
	charlie.signForm(*form_2);
	charlie.executeForm(*form_2); // should fail, as grade is not enough for execution 
}

static void testForIntern()
{
	Intern someRandomIntern;
	std::unique_ptr<AForm> form;
	form = someRandomIntern.makeForm("robotomy request", "Bender");
	form = someRandomIntern.makeForm("shrubbery creation", "home");
	form = someRandomIntern.makeForm("presidential pardon", "Bob");
	form = someRandomIntern.makeForm("random", "random");
	form = someRandomIntern.makeForm("random", nullptr); // exception should be thrown
}

int main()
{
	try
	{
		printString("execute() for concrete classes", YELLOW_BG);
		testShrubberyCreationForm();
		testRobotomyRequestForm();
		testPresidentialPardonForm();

		printString("ShrubberyCreationForm copy operations and default constructor", YELLOW_BG);
		{
			ShrubberyCreationForm form_0("campus");
			ShrubberyCreationForm form_1(form_0);
			std::cout << form_1 << std::endl;

			ShrubberyCreationForm form_2("mall");
			form_1 = form_2;
			std::cout << form_1 << std::endl;

			ShrubberyCreationForm form_3;
		}

		printString("Basic tests for Bureaucrat class from ex00", YELLOW_BG);
		testsForBureaucrat();

		printString("Intern::makeForm()", YELLOW_BG);
		testForIntern();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
}
