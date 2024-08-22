/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:16:44 by ixu               #+#    #+#             */
/*   Updated: 2024/08/22 22:02:18 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <memory>

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		std::unique_ptr<AForm> makeForm(const std::string& formName, const std::string& formTarget);
	
	private:
		std::unique_ptr<AForm> createShrubberyCreationForm(const std::string& target);
		std::unique_ptr<AForm> createRobotomyRequestForm(const std::string& target);
		std::unique_ptr<AForm> createPresidentialPardonForm(const std::string& target);
};

typedef std::unique_ptr<AForm> (Intern::*FormConstructor)(const std::string& target);

#endif