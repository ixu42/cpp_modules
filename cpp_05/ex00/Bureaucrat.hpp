/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:15:41 by ixu               #+#    #+#             */
/*   Updated: 2024/08/08 12:00:07 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const noexcept;
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const noexcept;
		};

	public:
		Bureaucrat() = delete;
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		Bureaucrat&			operator=(const Bureaucrat& other);

		std::string& getName() const;
		int getGrade() const;

		void				incrementGrade();
		void				decrementGrade();
};

#endif