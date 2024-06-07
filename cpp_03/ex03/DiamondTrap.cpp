/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:06:49 by ixu               #+#    #+#             */
/*   Updated: 2024/06/07 22:37:23 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

/* CONSTRUCTORS AND DESTRUCTOR */

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), name("Unknown")
{
	std::cout << "DiamondTrap default constructor called.\n";
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	hitPoint = FragTrap::hitPoint; // from FragTrap
	energyPoint = ScavTrap::energyPoint; // from ScavTrap
	attackDamage = FragTrap::attackDamage; // from FragTrap
	std::cout << "DiamondTrap " << name << " constructed.\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
	std::cout << "DiamondTrap " << name << " copied.\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " destroyed.\n";
}

/* OPERATOR OVERLOADING */

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		name = other.name;
		std::cout << "DiamondTrap " << name << " assigned.\n";
	}
	return (*this);
}

/* OTHER MEMBER FUNCS */

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target); // from ScavTrap
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->name << ", and my ClapTrap name is "
				<< ClapTrap::name << std::endl;
}
