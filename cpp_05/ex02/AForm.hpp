/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:24:35 by ixu               #+#    #+#             */
/*   Updated: 2024/08/21 17:06:35 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <fstream>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define CYAN "\033[0;36m"
# define CYAN_BG "\033[46;30m"
# define YELLOW_BG "\033[43;30m"
# define RESET "\033[0m"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
		const std::string	_target;

	public:
		AForm();
		AForm(const std::string& name, int signGrade, int execGrade, const std::string& target);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const std::string&	getName() const;
		const std::string&	getTarget() const;
		bool				getIsSigned() const;
		const int&			getSignGrade() const;
		const int&			getExecGrade() const;
		void				beSigned(Bureaucrat& bureau);
		virtual void		execute(Bureaucrat const & executor) const = 0;

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

		class FormNotSignedException : public std::exception
		{
			private:
				std::string _message;
			public:
				FormNotSignedException(const std::string& msg);
				virtual const char* what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& stream, const AForm& form);

#endif