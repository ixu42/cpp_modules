/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:47:59 by ixu               #+#    #+#             */
/*   Updated: 2024/06/13 11:03:27 by ixu              ###   ########.fr       */
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
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
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
			std::cout << "MateriaSource: learned " << m->getType() << std::endl;
			_inventory[i] = m; // copy the Materia so it can be cloned later
			return ;
		}
	}
	std::cout << "MateriaSource: can know at most 4 Materias\n";
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
