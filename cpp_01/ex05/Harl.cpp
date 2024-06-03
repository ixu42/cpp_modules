/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:20:21 by ixu               #+#    #+#             */
/*   Updated: 2024/06/03 17:44:52 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. "
				<< "I really do!\n";
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. " 
				<< "You didn't put enough bacon in my burger! "
				<< "If you did, I wouldn't be asking for more!\n";
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. "
				<< "I've been coming for years whereas you started working here since last month.\n";
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level)
{
	int			i  = 0;
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	t_func		funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	while (i < 4 && levels[i].compare(level))
		i++;
	if (i < 4)
		(this->*funcs[i])();
	else
		std::cout << "Invalid level: " << level << std::endl;
}
