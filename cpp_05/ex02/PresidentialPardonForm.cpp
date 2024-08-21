/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:58:30 by ixu               #+#    #+#             */
/*   Updated: 2024/08/21 17:27:38 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("unknown", 72, 45, "unknown")
{
	std::cout << "PresidentialPardonForm for unknown constructed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("Presidential Pardon", 72, 45, target)
{
	std::cout << "PresidentialPardonForm for " << target << " constructed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other)
{
	std::cout << "PresidentialPardonForm copy constructor called " << std::endl;
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
	(void)executor;
}