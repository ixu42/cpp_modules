/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:58:30 by ixu               #+#    #+#             */
/*   Updated: 2024/08/21 23:54:08 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidential Pardon Form", 25, 5, "unknown target")
{
	std::cout << "PresidentialPardonForm for unknown target constructed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("Presidential Pardon Form", 25, 5, target)
{
	std::cout << "PresidentialPardonForm for " << target << " constructed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "PresidentialPardonForm copy assignment operator called " << std::endl;
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm for " << getTarget() << " destructed" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException("form not signed");
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException("grade too low");

	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
