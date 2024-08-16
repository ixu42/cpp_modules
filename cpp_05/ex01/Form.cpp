/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:24:32 by ixu               #+#    #+#             */
/*   Updated: 2024/08/16 16:30:46 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* Constructor & destructor */

Form::Form() : _name("Unknown"), _isSigned(false), _gradeToSign(42), _gradeToExecute(42)
{
	std::cout << "Default form constructed!" << std::endl;
}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Constructing form " << name << "..." << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException("Failed to construct form (grade too high) 🙁");
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException("Failed to construct form (grade too low) 🙁");
	std::cout << "Form " << name << " constructed!" << std::endl;
}

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned),_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "A copy of form " << other._name << " constructed!" << std::endl;
}

Form::~Form()
{
	std::cout << "Form " << _name << " destructed!" << std::endl;
}

/* Operator overloading */

Form& Form::operator=(const Form& other)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	this->_isSigned = other._isSigned;
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const Form& form)
{
	stream << YELLOW
			<< "Name of the form: " << form.getName() << std::endl
			<< "Is form signed:   " << form.getIsSigned() << std::endl
			<< "Grade to sign:    " << form.getGradeToSign() << std::endl
			<< "Grade to execute: " << form.getGradeToExecute()
			<< RESET << std::endl;
	return (stream);
}

/**
 * Exception handlers in the Form class that return error messages
 * indicating whether the grade is too high or too low.
 */

Form::GradeTooHighException::GradeTooHighException(const std::string& msg) : _message(msg) {}

const char* Form::GradeTooHighException::what() const noexcept
{
	return _message.c_str();
}

Form::GradeTooLowException::GradeTooLowException(const std::string& msg) : _message(msg) {}

const char* Form::GradeTooLowException::what() const noexcept
{
	return _message.c_str();
}

/* Getters */

const std::string& Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

const int& Form::getGradeToSign() const
{
	return _gradeToSign;
}

const int& Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

/* Other member funcs */

void Form::beSigned(Bureaucrat& bureau)
{
	if (bureau.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException("the grade is too low for signing 🙁");
}
