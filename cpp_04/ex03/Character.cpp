/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:33:36 by ixu               #+#    #+#             */
/*   Updated: 2024/06/13 11:57:07 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character() : _name("default")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(const std::string& name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(const Character& other) : _name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		delete _inventory[i];
		if (other._inventory[i] != nullptr)	
			_inventory[i] = other._inventory[i];
		else
			_inventory[i] = nullptr;
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

Character&	Character::operator=(const Character& other)
{
	if (this == &other)
		return (*this);
	_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		delete _inventory[i];
		if (other._inventory[i] != nullptr)	
			_inventory[i] = other._inventory[i];
		else
			_inventory[i] = nullptr;
	}
	return (*this);
}

std::string const &	Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	if (m == nullptr)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == nullptr)
		{
			_inventory[i] = m;
			return ;
		}
	}
}

// Save the address of the Materia to be unequipped before calling unequip()

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	else if (_inventory[idx] == nullptr)
		return ;
	else
		_inventory[idx] = nullptr;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	else if (_inventory[idx] != nullptr)
		_inventory[idx]->use(target);
}

AMateria*	Character::getInventory(int idx)
{
	if (idx < 0 || idx > 3)
		return (nullptr);
	return (_inventory[idx]);
}
