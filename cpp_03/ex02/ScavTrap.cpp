/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:12:07 by ixu               #+#    #+#             */
/*   Updated: 2024/06/09 21:22:40 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

/* CONSTRUCTORS AND DESTRUCTOR */

ScavTrap::ScavTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called.\n";
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " constructed.\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << _name << " copy constructor called.\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destroyed.\n";
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
	if (_energyPoints == 0)
		std::cout << "ScavTrap " << _name << " has no energy left to attack.\n";
	else if (_hitPoints == 0)
		std::cout << "ScavTrap " << _name << " is dead. Cannot attack anymore.\n";
	else
	{
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacked " << target
					<< ", causing " << _attackDamage << " points of damage!\n";
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode.\n";
}
