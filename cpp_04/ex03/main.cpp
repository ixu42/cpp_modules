/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:04:50 by ixu               #+#    #+#             */
/*   Updated: 2024/06/13 12:51:49 by ixu              ###   ########.fr       */
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

static void	useAllFromInventory(ICharacter* me, ICharacter* bob)
{
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
}

int	main()
{
	std::cout << "\033[96m" << "---TEST FROM SUBJECT---\n" << "\033[0m";
	testFromSubject();

	std::cout << "\033[96m" << "\n---OWN TESTS---\n" << "\033[0m";
	IMateriaSource*	src = new MateriaSource();

	AMateria*	ice = new Ice();
	AMateria*	cure = new Cure();

	// learnMateria
	src->learnMateria(ice);
	src->learnMateria(cure);
	src->learnMateria(ice);
	src->learnMateria(cure);
	src->learnMateria(ice);
	src->learnMateria(nullptr);

	// createMateria & equip
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

	// use
	std::cout << "\033[36m" << "test1: use all Materias from inventory\n" << "\033[0m";
	ICharacter*	bob = new Character("bob");
	useAllFromInventory(me, bob);
	// pass invalid indexes to Character::use()
	me->use(4, *bob);
	me->use(-1, *bob);

	// unequip
	std::cout << "\033[36m" << "test2: exchange Materias at slot 1 and 2 "
				<< "and use all Materias from inventory\n" << "\033[0m";
	AMateria*	floor[10];
	for (int i = 0; i < 10; i++)
    	floor[i] = nullptr;
	Character*	me_copy = dynamic_cast<Character*>(me);

	floor[0] = me_copy->getInventory(1);
	me->unequip(1);
	me->unequip(1); // should output nothing
	me->use(1, *bob); // should output nothing

	floor[1] = me_copy->getInventory(2);
	me->unequip(2);
	me->unequip(2); // should output nothing
	me->use(2, *bob); // should output nothing

	me->equip(floor[1]);
	floor[1] = nullptr;

	me->equip(floor[0]);
	floor[0] = nullptr;

	useAllFromInventory(me, bob);

	// clean up
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
