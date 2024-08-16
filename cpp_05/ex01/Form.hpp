/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:24:35 by ixu               #+#    #+#             */
/*   Updated: 2024/08/16 16:25:39 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define CYAN "\033[0;36m"
# define CYAN_BG "\033[46;30m"
# define YELLOW_BG "\033[43;30m"
# define RESET "\033[0m"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

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
		Form();
		Form(const std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		~Form();
		Form&				operator=(const Form& other);
		const std::string&	getName() const;
		bool				getIsSigned() const;
		const int&			getGradeToSign() const;
		const int&			getGradeToExecute() const;
		void				beSigned(Bureaucrat& bureau);
};

std::ostream& operator<<(std::ostream& stream, const Form& form);

#endif