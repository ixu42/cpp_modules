/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:16:42 by ixu               #+#    #+#             */
/*   Updated: 2024/08/23 16:51:48 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}
Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	std::cout << "Intern copy assignment operator called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

std::unique_ptr<AForm> Intern::createShrubberyCreationForm(const std::string& target)
{
	return std::make_unique<ShrubberyCreationForm>(target);
}

std::unique_ptr<AForm> Intern::createRobotomyRequestForm(const std::string& target)
{
	return std::make_unique<RobotomyRequestForm>(target);
}

std::unique_ptr<AForm> Intern::createPresidentialPardonForm(const std::string& target)
{
	return std::make_unique<PresidentialPardonForm>(target);
}

std::unique_ptr<AForm> Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
	std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	FormConstructor formConstructors[] = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};
	int i = 0;
	while (i < 3 && formNames[i].compare(formName))
		i++;
	if (i < 3)
	{
		std::cout << GREEN << "Intern creates " << formName << " form" << RESET << std::endl;
		return (this->*formConstructors[i])(formTarget);
	}
	else
	{
		std::cerr << RED << "Intern::makeForm() error: " << formName
					<< " is an invalid formName" 
					<< RESET << std::endl;
		return nullptr;
	}
}
