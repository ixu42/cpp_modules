/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:16:38 by ixu               #+#    #+#             */
/*   Updated: 2024/06/07 22:34:22 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

/* CONSTRUCTORS AND DESTRUCTOR */

ClapTrap::ClapTrap()
	: name("Unknown"), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called.\n";
}

ClapTrap::ClapTrap(const std::string& name)
	: name(name), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " constructed.\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << "ClapTrap " << name << " copied.\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destroyed.\n";
}

/* OPERATOR OVERLOADING */

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		name = other.name;
		hitPoint = other.hitPoint;
		energyPoint = other.energyPoint;
		attackDamage = other.attackDamage;
		std::cout << "ClapTrap " << name << " assigned.\n";
	}
	return (*this);
}

/* OTHER MEMBER FUNCS */

void	ClapTrap::attack(const std::string& target)
{
	if (energyPoint == 0)
		std::cout << "ClapTrap " << name << " has no energy left to attack.\n";
	else if (hitPoint == 0)
		std::cout << "ClapTrap " << name << " is dead. Cannot attack anymore.\n";
	else
	{
		energyPoint--;
		std::cout << "ClapTrap " << name << " attacked " << target
					<< ", causing " << attackDamage << " points of damage!\n";
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoint == 0)
	{
		std::cout << "ClapTrap " << name << " is dead. Cannot take more damage.\n";
		return ;
	}
	unsigned int	actualDamage;
	if (hitPoint >= amount)
		actualDamage = amount;
	else
		actualDamage = hitPoint;
	hitPoint -= actualDamage;
	std::cout << "ClapTrap " << name << " took " << actualDamage 
				<< " points of damage.\n";
	if (hitPoint == 0)
		std::cout << "ClapTrap " << name << " died.\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoint == 0)
		std::cout << "ClapTrap " << name << " has no energy left to repair.\n";
	else if (hitPoint == 0)
		std::cout << "ClapTrap " << name << " is dead. Cannot repair anymore.\n";
	else
	{
		energyPoint--;
		hitPoint += amount;
		std::cout << "ClapTrap " << name << " repaired itself, getting " << amount
					<< " hit points back.\n";
	}
}
