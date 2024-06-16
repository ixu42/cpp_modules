/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:33:36 by ixu               #+#    #+#             */
/*   Updated: 2024/06/16 20:23:40 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>
#include "debug.hpp"

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
		if (other._inventory[i] != nullptr)	
			_inventory[i] = other._inventory[i]->clone();
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
			_inventory[i] = other._inventory[i]->clone();
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
	{
		DEBUG_MSG("Character::equip(): invalid Materia");
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == nullptr)
		{
			_inventory[i] = m;
			DEBUG_MSG("Character::equip(): equipped " << m->getType());
			return ;
		}
	}
	DEBUG_MSG("Character::equip(): inventory full");
}

// Save the address of the Materia to be unequipped before calling unequip()

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		DEBUG_MSG("Character::unequip(): idx out of bounds");	
	else if (_inventory[idx] == nullptr)
		DEBUG_MSG("Character::unequip(): no Materia at slot " << idx);
	else
		_inventory[idx] = nullptr;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		DEBUG_MSG("Character::use(): idx out of bounds");
	else if (_inventory[idx] == nullptr)
		DEBUG_MSG("Character::use(): no Materia at slot " << idx);	
	else
		_inventory[idx]->use(target);
}

AMateria*	Character::getInventory(int idx)
{
	if (idx < 0 || idx > 3)
	{
		DEBUG_MSG("Character::use(): idx out of bounds");
		return (nullptr);
	}
	return (_inventory[idx]);
}
