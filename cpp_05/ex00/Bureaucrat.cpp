/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:15:39 by ixu               #+#    #+#             */
/*   Updated: 2024/08/16 12:38:36 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* Constructor & destructor */

Bureaucrat::Bureaucrat(const std::string name, int grade)
	: _name(name)
{
	std::cout << "Constructing " << name << "..." << std::endl;
	if (grade < 1)
		throw GradeTooHighException("Failed to construct bureaucrat (grade too high) 🙁");
	else if (grade > 150)
		throw GradeTooLowException("Failed to construct bureaucrat (grade too low) 🙁");
	_grade = grade;
	std::cout << name << " constructed!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	std::cout << "A copy of " << other._name << " constructed!" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << _name << " destructed!" << std::endl;
}

/* Operator overloading */

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	this->_grade = other._grade;
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureau)
{
	stream << bureau.getName() << ", bureaucrat grade " << bureau.getGrade() << "." << std::endl;
	return (stream);
}

/**
 * Exception handlers in the Bureaucrat class that return error messages
 * indicating whether the grade is too high or too low.
 */

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& msg) : _message(msg) {}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return _message.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& msg) : _message(msg) {}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return _message.c_str();
}

/* Getters */

const std::string& Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

/* Member funcs to increment or decrement grades by 1 per func call */

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException("Failed to increment grade 🙁");
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException("Failed to decrement grade 🙁");
	_grade++;
}
