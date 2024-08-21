/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:58:38 by ixu               #+#    #+#             */
/*   Updated: 2024/08/21 23:53:20 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request Form", 72, 45, "unknown target")
{
	std::cout << "RobotomyRequestForm for unknown target constructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("Robotomy Request Form", 72, 45, target)
{
	std::cout << "RobotomyRequestForm for " << target << " constructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm for " << getTarget() << " destructed" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException("form not signed");
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException("grade too low");

	std::cout << "BZZZZZZZZZZZZZZZZ..." << std::endl;

	std::srand(std::time(0));
	bool success = std::rand() % 2;

	if (success)
		std::cout << getTarget() << " has been robotomized 🤖" << std::endl;
	else
		std::cout << "The robotomy failed" << std::endl;
}
