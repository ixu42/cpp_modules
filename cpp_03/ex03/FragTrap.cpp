/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:33:35 by ixu               #+#    #+#             */
/*   Updated: 2024/06/09 16:32:57 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

/* CONSTRUCTORS AND DESTRUCTOR */

FragTrap::FragTrap() : ClapTrap()
{
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
	std::cout << "FragTrap default constructor called.\n";
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " constructed.\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap " << name << " copied.\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destroyed.\n";
}

/* OPERATOR OVERLOADING */

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap " << name << " assigned.\n";
	if (this == &other)
		return (*this);
	ClapTrap::operator=(other);
	return (*this);
}

/* OTHER MEMBER FUNCS */

void	FragTrap::attack(const std::string& target)
{
	if (energyPoint == 0)
		std::cout << "FragTrap " << name << " has no energy left to attack.\n";
	else if (hitPoint == 0)
		std::cout << "FragTrap " << name << " is dead. Cannot attack anymore.\n";
	else
	{
		energyPoint--;
		std::cout << "FragTrap " << name << " attacked " << target
					<< ", causing " << attackDamage << " points of damage!\n";
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << ": Awesome! High fives guys 🙌\n";
}
