/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:16:38 by ixu               #+#    #+#             */
/*   Updated: 2024/06/06 16:09:10 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
	: name("Unknown"), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "ClapTrap Unknown constructed" << std::endl;
}

ClapTrap::ClapTrap(std::string& name)
	: name(name), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " constructed" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (energyPoint <= 0 || hitPoint <= 0)
		return ;
	energyPoint--;
	std::cout << "ClapTrap " << name << " attacks " << target 
				<< ", causing " << attackDamage << " points of damage!"
				<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	
}
