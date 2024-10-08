/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:58:43 by ixu               #+#    #+#             */
/*   Updated: 2024/08/21 23:41:58 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation Form", 145, 137, "unknown target")
{
	std::cout << "ShrubberyCreationForm for unknown target constructed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery Creation Form", 145, 137, target)
{
	std::cout << "ShrubberyCreationForm for " << target << " constructed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm for " << getTarget() << " destructed" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	// ensure that the form is signed and that the executor's grade is sufficient
	if (!getIsSigned())
		throw FormNotSignedException("form not signed");
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException("grade too low");

	// create filename based on target
	std::string filename = getTarget() + "_shrubbery";

	// open the file for writing
	std::ofstream outfile(filename.c_str());
	if (!outfile)
		throw std::runtime_error("Error in ShrubberyCreationForm::execute(): could not open file for writing");

	// write ASCII trees to the file
	outfile << "    /\\    " << std::endl;
	outfile << "   /  \\   " << std::endl;
	outfile << "  /    \\  " << std::endl;
	outfile << " /______\\ " << std::endl;
	outfile << "    ||     " << std::endl;

	outfile.close();
}
