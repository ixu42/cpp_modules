/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:15:41 by ixu               #+#    #+#             */
/*   Updated: 2024/08/21 12:48:28 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

		class GradeTooHighException : public std::exception
		{
			private:
				std::string _message;
			public:
				GradeTooHighException(const std::string& msg);
				virtual const char* what() const noexcept override;
		};

		class GradeTooLowException : public std::exception
		{
			private:
				std::string _message;
			public:
				GradeTooLowException(const std::string& msg);
				virtual const char* what() const noexcept override;
		};

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();
		Bureaucrat&			operator=(const Bureaucrat& other);
		const std::string&	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm& form);
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureau);

#endif