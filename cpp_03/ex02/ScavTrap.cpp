/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:12:07 by ixu               #+#    #+#             */
/*   Updated: 2024/06/09 17:36:12 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

/* CONSTRUCTORS AND DESTRUCTOR */

ScavTrap::ScavTrap() : ClapTrap()
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap default constructor called.\n";
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << name << " constructed.\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << name << " copy constructor called.\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destroyed.\n";
}

/* OPERATOR OVERLOADING */

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment operator called.\n";
	if (this == &other)
		return (*this);
	ClapTrap::operator=(other);
	return (*this);
}

/* OTHER MEMBER FUNCS */

void	ScavTrap::attack(const std::string& target)
{
	if (energyPoints == 0)
		std::cout << "ScavTrap " << name << " has no energy left to attack.\n";
	else if (hitPoints == 0)
		std::cout << "ScavTrap " << name << " is dead. Cannot attack anymore.\n";
	else
	{
		energyPoints--;
		std::cout << "ScavTrap " << name << " attacked " << target
					<< ", causing " << attackDamage << " points of damage!\n";
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode.\n";
}
