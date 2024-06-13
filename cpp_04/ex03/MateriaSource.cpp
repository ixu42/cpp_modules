/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:47:59 by ixu               #+#    #+#             */
/*   Updated: 2024/06/13 12:50:21 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& other)
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

MateriaSource::~MateriaSource()
{
	void*	freedObjects[4] = {nullptr};
	int		freedCount = 0;

	for (int i = 0; i < 4; i++)
	{
		int	already_freed = 0;
		for (int j = 0; j < freedCount; j++)
		{
			if (_inventory[i] == freedObjects[j])
			{
				already_freed = 1;
				break;
			}
		}
		if (!already_freed)
		{
			freedObjects[freedCount] = _inventory[i];
			delete _inventory[i];
			freedCount++;
		}
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	if (this == &other)
		return (*this);
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

void	MateriaSource::learnMateria(AMateria* m)
{
	if (m == nullptr)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == nullptr)
		{
			_inventory[i] = m; // copy the Materia so it can be cloned later
			return ;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == m)
			return ; // to prevent double free
	}
	delete m;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != nullptr && _inventory[i]->getType() == type)
			return (_inventory[i]->clone());
	}
	return (0);
}
