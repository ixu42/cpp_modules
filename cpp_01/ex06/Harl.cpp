/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 08:52:53 by ixu               #+#    #+#             */
/*   Updated: 2024/06/04 08:52:55 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n"
				<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n"
				<< "I really do!\n\n";
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\n"
				<< "I cannot believe adding extra bacon costs more money.\n" 
				<< "You didn't put enough bacon in my burger!\n"
				<< "If you did, I wouldn't be asking for more!\n\n";
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\n"
				<< "I think I deserve to have some extra bacon for free.\n"
				<< "I've been coming for years whereas you started working here since last month.\n\n";
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]\n"
				<< "This is unacceptable, I want to speak to the manager now.\n\n";
}

void	Harl::complain(std::string level)
{
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"}; 
	int			i;
	for (i = 0; i < 4; i++)
	{
		if (levels[i].compare(level) == 0)
			break ;
	}
	switch (i)
	{
		case 0:
			debug();
			info();
			warning();
			error();
			break ;
		case 1:
			info();
			warning();
			error();
			break ;
		case 2:
			warning();
			error();
			break ;
		case 3:
			error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break ;
	}
}
