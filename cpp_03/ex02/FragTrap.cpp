/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:33:35 by ixu               #+#    #+#             */
/*   Updated: 2024/06/09 21:22:10 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

/* CONSTRUCTORS AND DESTRUCTOR */

FragTrap::FragTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called.\n";
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " constructed.\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap " << _name << " copy constructor called.\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destroyed.\n";
}

/* OPERATOR OVERLOADING */

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assignment operator called.\n";
	if (this == &other)
		return (*this);
	ClapTrap::operator=(other);
	return (*this);
}

/* OTHER MEMBER FUNCS */

void	FragTrap::attack(const std::string& target)
{
	if (_energyPoints == 0)
		std::cout << "FragTrap " << _name << " has no energy left to attack.\n";
	else if (_hitPoints == 0)
		std::cout << "FragTrap " << _name << " is dead. Cannot attack anymore.\n";
	else
	{
		_energyPoints--;
		std::cout << "FragTrap " << _name << " attacked " << target
					<< ", causing " << _attackDamage << " points of damage!\n";
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << ": Awesome! High fives guys 🙌\n";
}
