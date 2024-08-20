/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:58:43 by ixu               #+#    #+#             */
/*   Updated: 2024/08/20 13:27:14 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("unknown", 145, 137, "unknown")
{
	std::cout << "ShrubberyCreationForm unknown constructed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery Creation", 145, 137, target)
{
	std::cout << "ShrubberyCreationForm " << target << " constructed" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << getTarget() << " destructed" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	// ensure that the form is signed and that the executor's grade is sufficient


	// create filename based on target
	std::string filename = this->getTarget() + "_shrubbery";

	// open the file for writing
	std::ofstream outfile(filename.c_str());
	if (!outfile)
		throw std::runtime_error("Error: Could not open file for writing.");

	// write ASCII trees to the file
	outfile << "    /\\    " << std::endl;
	outfile << "   /  \\   " << std::endl;
	outfile << "  /    \\  " << std::endl;
	outfile << " /______\\ " << std::endl;
	outfile << "    ||     " << std::endl;

	outfile.close();
}
