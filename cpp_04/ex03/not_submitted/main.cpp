/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:04:50 by ixu               #+#    #+#             */
/*   Updated: 2024/06/16 20:25:37 by ixu              ###   ########.fr       */
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

static void	useAllFromInventory(ICharacter* player, ICharacter* target)
{
	player->use(0, *target);
	player->use(1, *target);
	player->use(2, *target);
	player->use(3, *target);
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
	if (me_copy == nullptr)
		return (1);
	floor[0] = me_copy->getInventory(1);
	me->unequip(1);
	me->unequip(1);
	me->use(1, *bob);

	floor[1] = me_copy->getInventory(2);
	me->unequip(2);
	me->unequip(2);
	me->use(2, *bob);

	me->equip(floor[1]);
	floor[1] = nullptr;

	me->equip(floor[0]);
	floor[0] = nullptr;

	useAllFromInventory(me, bob);

	std::cout << "\033[36m" << "test3: Character copy constructor\n" << "\033[0m";
	Character	bar0(*me_copy);
	ICharacter*	bar = &bar0;
	useAllFromInventory(bar, bob);

	std::cout << "\033[36m" << "test4: Character copy assignment operator\n" << "\033[0m";
	std::cout << "--before copy assignment operator--\n";
	ICharacter*	foo = new Character("foo");
	useAllFromInventory(foo, bob);
	*dynamic_cast<Character*>(foo) = *me_copy;
	std::cout << "--after copy assignment operator--\n";
	useAllFromInventory(foo, bob);

	// clean up
	delete foo;
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
