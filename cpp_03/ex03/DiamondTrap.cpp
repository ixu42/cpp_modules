/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:06:49 by ixu               #+#    #+#             */
/*   Updated: 2024/06/09 21:27:22 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

/* CONSTRUCTORS AND DESTRUCTOR */

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), _name("Unknown")
{
	std::cout << "DiamondTrap default constructor called.\n";
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	_hitPoints = FragTrap::_hitPoints; // from FragTrap
	_energyPoints = ScavTrap::_energyPoints; // from ScavTrap
	_attackDamage = FragTrap::_attackDamage; // from FragTrap
	std::cout << "DiamondTrap " << _name << " constructed.\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap " << _name << " copied.\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " destroyed.\n";
}

/* OPERATOR OVERLOADING */

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap " << _name << " assigned.\n";
	if (this == &other)
		return (*this);
	ClapTrap::operator=(other);
	ScavTrap::operator=(other);
	FragTrap::operator=(other);
	_name = other._name;
	return (*this);
}

/* OTHER MEMBER FUNCS */

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target); // from ScavTrap
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->_name << ", and my ClapTrap name is "
				<< ClapTrap::_name << std::endl;
}
