/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:24:32 by ixu               #+#    #+#             */
/*   Updated: 2024/08/21 12:27:06 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* Constructors & destructor */

AForm::AForm() : _name("unknown"), _isSigned(false), _signGrade(42), _execGrade(42), _target("unknown")
{
	std::cout << "AForm unknown constructed!" << std::endl;
}

AForm::AForm(const std::string& name, int signGrade, int execGrade, const std::string& target)
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade), _target(target)
{
	std::cout << "Constructing AForm " << name << "..." << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException("Failed to construct AForm (grade too high) 🙁");
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException("Failed to construct AForm (grade too low) 🙁");
	std::cout << "AForm " << name << " constructed!" << std::endl;
}

AForm::AForm(const AForm& other)
	: _name(other._name), _isSigned(other._isSigned),_signGrade(other._signGrade), _execGrade(other._execGrade)
{
	std::cout << "A copy of AForm " << other._name << " constructed!" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm " << _name << " destructed!" << std::endl;
}

/* Operator overloading */

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	this->_isSigned = other._isSigned;
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const AForm& form)
{
	stream << YELLOW
			<< "Name of form: " << form.getName() << std::endl
			<< "Is form signed:   " << form.getIsSigned() << std::endl
			<< "Grade to sign:    " << form.getSignGrade() << std::endl
			<< "Grade to execute: " << form.getExecGrade()
			<< RESET << std::endl;
	return (stream);
}

/**
 * Exception handlers in the Form class that return error messages
 * indicating whether the grade is too high or too low.
 */

AForm::GradeTooHighException::GradeTooHighException(const std::string& msg) : _message(msg) {}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return _message.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(const std::string& msg) : _message(msg) {}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return _message.c_str();
}

AForm::FormNotSignedException::FormNotSignedException(const std::string& msg) : _message(msg) {}

const char* AForm::FormNotSignedException::what() const noexcept
{
	return _message.c_str();
}

/* Getters */

const std::string& AForm::getName() const
{
	return _name;
}

const std::string& AForm::getTarget() const
{
	return _target;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

const int& AForm::getSignGrade() const
{
	return _signGrade;
}

const int& AForm::getExecGrade() const
{
	return _execGrade;
}

/* Other member funcs */

void AForm::beSigned(Bureaucrat& bureau)
{
	if (bureau.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw GradeTooLowException("the grade is too low for signing 🙁");
}
