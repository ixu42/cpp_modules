/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:16:38 by ixu               #+#    #+#             */
/*   Updated: 2024/06/09 17:36:12 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

/* CONSTRUCTORS AND DESTRUCTOR */

ClapTrap::ClapTrap()
	: name("Unknown"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called.\n";
}

ClapTrap::ClapTrap(const std::string& name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " constructed.\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints),
		attackDamage(other.attackDamage)
{
	std::cout << "ClapTrap " << name << " copied.\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destroyed.\n";
}

/* OPERATOR OVERLOADING */

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called.\n";
	if (this == &other)
		return (*this);
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	return (*this);
}

/* OTHER MEMBER FUNCS */

void	ClapTrap::attack(const std::string& target)
{
	if (energyPoints == 0)
		std::cout << "ClapTrap " << name << " has no energy left to attack.\n";
	else if (hitPoints == 0)
		std::cout << "ClapTrap " << name << " is dead. Cannot attack anymore.\n";
	else
	{
		energyPoints--;
		std::cout << "ClapTrap " << name << " attacked " << target
					<< ", causing " << attackDamage << " points of damage!\n";
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is dead. Cannot take more damage.\n";
		return ;
	}
	unsigned int	actualDamage;
	if (hitPoints >= amount)
		actualDamage = amount;
	else
		actualDamage = hitPoints;
	hitPoints -= actualDamage;
	std::cout << "ClapTrap " << name << " took " << actualDamage 
				<< " points of damage.\n";
	if (hitPoints == 0)
		std::cout << "ClapTrap " << name << " died.\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints == 0)
		std::cout << "ClapTrap " << name << " has no energy left to repair.\n";
	else if (hitPoints == 0)
		std::cout << "ClapTrap " << name << " is dead. Cannot repair anymore.\n";
	else
	{
		energyPoints--;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " repaired itself, getting " << amount
					<< " hit points back.\n";
	}
}
