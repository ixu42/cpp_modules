/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:12:07 by ixu               #+#    #+#             */
/*   Updated: 2024/06/07 22:33:54 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

/* CONSTRUCTORS AND DESTRUCTOR */

ScavTrap::ScavTrap() : ClapTrap()
{
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
	std::cout << "ScavTrap default constructor called.\n";
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << name << " constructed.\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << name << " copied.\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destroyed.\n";
}

/* OPERATOR OVERLOADING */

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		// call base class's copy assignment operator
		ClapTrap::operator=(other);
		std::cout << "ScavTrap " << name << " assigned.\n";
	}
	return (*this);
}

/* OTHER MEMBER FUNCS */

void	ScavTrap::attack(const std::string& target)
{
	if (energyPoint == 0)
		std::cout << "ScavTrap " << name << " has no energy left to attack.\n";
	else if (hitPoint == 0)
		std::cout << "ScavTrap " << name << " is dead. Cannot attack anymore.\n";
	else
	{
		energyPoint--;
		std::cout << "ScavTrap " << name << " attacked " << target
					<< ", causing " << attackDamage << " points of damage!\n";
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode.\n";
}
