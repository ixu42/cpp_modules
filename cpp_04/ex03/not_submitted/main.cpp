/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:04:50 by ixu               #+#    #+#             */
/*   Updated: 2024/06/13 11:45:18 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

static void	testFromSubject()
{
	IMateriaSource*	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter*	me = new Character("me");
	AMateria*	tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter*	bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

int	main()
{
	std::cout << "\033[96m" << "---TEST FROM SUBJECT---\n" << "\033[0m";
	testFromSubject();

	std::cout << "\033[96m" << "\n---OWN TESTS---\n" << "\033[0m";
	IMateriaSource*	src = new MateriaSource();

	std::cout << "\033[36m" << "\n---learnMateria---\n" << "\033[0m";
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(nullptr);

	std::cout << "\033[36m" << "\n---createMateria & equip---\n" << "\033[0m";
	ICharacter*	me = new Character("me");
	AMateria*	tmp;
	me->equip(nullptr);
	tmp = src->createMateria("fire");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp; // to prevent memory leaks when inventory is full

	std::cout << "\033[36m" << "\n---use---\n" << "\033[0m";
	ICharacter*	bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	me->use(-1, *bob);

	std::cout << "\033[36m" << "\n---unequip---\n" << "\033[0m";
	AMateria*	floor[10];
	for (int i = 0; i < 10; i++)
    	floor[i] = nullptr;
	Character*	me_copy = dynamic_cast<Character*>(me);

	floor[0] = me_copy->getInventory(0);
	me->unequip(0);
	me->use(0, *bob);

	floor[1] = me_copy->getInventory(3);
	me->unequip(3);
	me->use(3, *bob);

	me->equip(floor[0]);
	floor[0] = nullptr;
	me->use(0, *bob);

	me->equip(floor[1]);
	floor[1] = nullptr;
	me->use(3, *bob);

	delete bob;
	delete me;
	delete src;

	for (int i = 0; i < 10; i++)
	{
		if (floor[i] != nullptr)
		{
			delete floor[i];
			floor[i] = nullptr;
		}		
	}

	return (0);
}
