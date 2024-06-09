/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:16:38 by ixu               #+#    #+#             */
/*   Updated: 2024/06/09 21:17:35 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

/* CONSTRUCTORS AND DESTRUCTOR */

ClapTrap::ClapTrap()
	: _name("Unknown"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called.\n";
}

ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructed.\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name), _hitPoints(other._hitPoints),
		_energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap " << _name << " copy constructor called.\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destroyed.\n";
}

/* OPERATOR OVERLOADING */

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called.\n";
	if (this == &other)
		return (*this);
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

/* OTHER MEMBER FUNCS */

void	ClapTrap::attack(const std::string& target)
{
	if (_energyPoints == 0)
		std::cout << "ClapTrap " << _name << " has no energy left to attack.\n";
	else if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name << " is dead. Cannot attack anymore.\n";
	else
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacked " << target
					<< ", causing " << _attackDamage << " points of damage!\n";
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead. Cannot take more damage.\n";
		return ;
	}
	unsigned int	actualDamage;
	if (_hitPoints >= amount)
		actualDamage = amount;
	else
		actualDamage = _hitPoints;
	_hitPoints -= actualDamage;
	std::cout << "ClapTrap " << _name << " took " << actualDamage 
				<< " points of damage.\n";
	if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name << " died.\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints == 0)
		std::cout << "ClapTrap " << _name << " has no energy left to repair.\n";
	else if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name << " is dead. Cannot repair anymore.\n";
	else
	{
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " repaired itself, getting " << amount
					<< " hit points back.\n";
	}
}
