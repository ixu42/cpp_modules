/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:51:28 by ixu               #+#    #+#             */
/*   Updated: 2024/06/11 17:47:43 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

static void	ownTests()
{
	std::cout << "\033[33m" << "\n---Cat---\n" << "\033[0m";
	{
		std::cout << "\033[36m" << "\n---Constructing obj---\n" << "\033[0m";
		Cat	a;
		std::cout << "\033[36m" << "\n---Sound---\n" << "\033[0m";
		a.makeSound();
		std::cout << "\033[36m" << "\n---Destructing obj---\n" << "\033[0m";
	}
	std::cout << "\033[33m" << "\n---Dog---\n" << "\033[0m";
	{
		std::cout << "\033[36m" << "\n---Constructing obj---\n" << "\033[0m";
		Dog	a;
		std::cout << "\033[36m" << "\n---Sound---\n" << "\033[0m";
		a.makeSound();
		std::cout << "\033[36m" << "\n---Destructing obj---\n" << "\033[0m";
	}
}

static void	testFromSubjectEx00()
{
	std::cout << "\033[36m" << "\n---Constructing objs---\n" << "\033[0m";
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << "\033[36m" << "\n---Type---\n" << "\033[0m";
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "\033[36m" << "\n---Sounds---\n" << "\033[0m";
	i->makeSound(); // will output the cat sound!
	j->makeSound(); // will output the dog sound!

	std::cout << "\033[36m" << "\n---Destructing objs---\n" << "\033[0m";
	delete j;
	delete i;
}

static void	testWrongAnimal()
{
	std::cout << "\033[36m" << "\n---Constructing obj---\n" << "\033[0m";
	const WrongAnimal*	wrongCat = new WrongCat();

	std::cout << "\033[36m" << "\n---Type---\n" << "\033[0m";
	std::cout << wrongCat->getType() << " " << std::endl;
	std::cout << "\033[36m" << "\n---Sound---\n" << "\033[0m";
	wrongCat->makeSound(); // will output wrong animal sound!

	std::cout << "\033[36m" << "\n---Destructing obj---\n" << "\033[0m";
	delete wrongCat;
}

static void	testFromSubjectEx01()
{
	std::cout << "\033[36m" << "\n---Constructing objs---\n" << "\033[0m";
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << "\033[36m" << "\n---Destructing objs---\n" << "\033[0m";
	delete j; // should not create a leak
	delete i;
}

static void	testAnimalArray()
{
	const int		animalCount = 6;
	const Animal*	animals[animalCount];

	std::cout << "\033[36m" << "\n---Constructing dogs---\n" << "\033[0m";
	for (int i = 0; i < animalCount / 2; i++)
		animals[i] = new Dog();

	std::cout << "\033[36m" << "\n---Constructing cats---\n" << "\033[0m";
	for (int i = animalCount / 2; i < animalCount; i++)
		animals[i] = new Cat();

	std::cout << "\033[36m" << "\n---Animals making sounds---\n" << "\033[0m";
	for (int i = 0; i < animalCount; i++)
		animals[i]->makeSound();

	std::cout << "\033[36m" << "\n---Destructing objs---\n" << "\033[0m";
	for (int i = 0; i < animalCount; i++)
		delete animals[i];
}

static void	testDeepCopies()
{
	std::cout << "\033[36m" << "\n---Original cat---\n" << "\033[0m";
	Cat	catOriginal;
	catOriginal.getBrain()->addIdea("Experts suggest investing in premium wet food");
	catOriginal.getBrain()->addIdea("Veterinarians endorse a steady supply of laser pointers");
	catOriginal.getBrain()->addIdea("Analysts highlight the benefits of catnip investments");
	std::cout << "\033[5;93m" << "\n---Original ideas---\n" << "\033[0m";
	catOriginal.getBrain()->printIdeas();

	std::cout << "\033[36m" << "\n---Copy constructor---\n" << "\033[0m";
	Cat	catCopy1(catOriginal);
	std::cout << "\033[5;93m" << "\n---Copied ideas---\n" << "\033[0m";
	catCopy1.getBrain()->printIdeas();

	std::cout << "\033[36m" << "\n---Copy assignment operator---\n" << "\033[0m";
	Cat	catCopy2;
	catCopy2 = catOriginal;
	std::cout << "\033[5;93m" << "\n---Copied ideas---\n" << "\033[0m";
	catCopy2.getBrain()->printIdeas();

	std::cout << "\033[36m" << "\n---Destructing objs---\n" << "\033[0m";
}

int	main()
{
	std::cout << "\033[7;96m" << "\n---TESTS FROM EX00---\n" << "\033[0m";
	{
		std::cout << "\033[96m" << "\n---OWN TESTS---\n" << "\033[0m";
		ownTests();

		std::cout << "\033[96m" << "\n---TEST FROM SUBJECT---\n" << "\033[0m";
		testFromSubjectEx00();

		std::cout << "\033[96m" << "\n---WRONGCAT & WRONGANIMAL---\n" << "\033[0m";
		testWrongAnimal();
	}

	std::cout << "\033[7;96m" << "\n---TESTS FROM EX01---\n" << "\033[0m";
	{
		std::cout << "\033[96m" << "\n---TEST FROM SUBJECT---\n" << "\033[0m";
		testFromSubjectEx01();

		std::cout << "\033[96m" << "\n---AN ARRAY OF ANIMALS---\n" << "\033[0m";
		testAnimalArray();

		std::cout << "\033[96m" << "\n---DEEP COPIES---\n" << "\033[0m";
		testDeepCopies();
	}

	// uncomment the following to instantiate abstract class of Animal (should be impossible)
	/* Animal	nonsense;
	nonsense.makeSound(); */

	return (0);	
}
