/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:15:43 by ixu               #+#    #+#             */
/*   Updated: 2024/08/08 12:00:06 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat("Foo", 60);
		Bureaucrat("Bar", 0);
	}
	catch (std::exception & e)
	{
		std::cerr << "\033[0;31m" << "Error occurred: " << e.what() << "\033[0m" << std:: endl;
		return 1;
	}
	return 0;
}
