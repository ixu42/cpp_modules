/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:51:28 by ixu               #+#    #+#             */
/*   Updated: 2024/06/11 15:47:04 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

static void	testFromSubject()
{
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	delete j; // should not create a leak
	delete i;
}

static void	testAnimalArray()
{
	const int		animalCount = 6;
	const Animal*	animals[animalCount];

	std::cout << "\033[36m" << "\n---Constructing dogs---\n\n" << "\033[0m";
	for (int i = 0; i < animalCount / 2; i++)
		animals[i] = new Dog();

	std::cout << "\033[36m" << "\n---Constructing cats---\n\n" << "\033[0m";
	for (int i = animalCount / 2; i < animalCount; i++)
		animals[i] = new Cat();

	std::cout << "\033[36m" << "\n---Animals making sounds---\n\n" << "\033[0m";
	for (int i = 0; i < animalCount; i++)
		animals[i]->makeSound();

	std::cout << "\033[36m" << "\n---Destructing objs---\n\n" << "\033[0m";
	for (int i = 0; i < animalCount; i++)
		delete animals[i];
}

static void	testDeepCopies()
{
	std::cout << "\033[36m" << "\n---Original cat---\n\n" << "\033[0m";
	Cat	catOriginal;
	catOriginal.getBrain()->addIdea("Experts suggest investing in premium wet food");
	catOriginal.getBrain()->addIdea("Veterinarians endorse a steady supply of laser pointers");
	catOriginal.getBrain()->addIdea("Analysts highlight the benefits of catnip investments");
	std::cout << "\033[5;93m" << "\n---Original ideas---\n\n" << "\033[0m";
	catOriginal.getBrain()->printIdeas();

	std::cout << "\033[36m" << "\n---Copy constructor---\n\n" << "\033[0m";
	Cat	catCopy1(catOriginal);
	std::cout << "\033[5;93m" << "\n---Copied ideas---\n\n" << "\033[0m";
	catCopy1.getBrain()->printIdeas();

	std::cout << "\033[36m" << "\n---Copy assignment operator---\n\n" << "\033[0m";
	Cat	catCopy2;
	catCopy2 = catOriginal;
	std::cout << "\033[5;93m" << "\n---Copied ideas---\n\n" << "\033[0m";
	catCopy2.getBrain()->printIdeas();

	std::cout << "\033[36m" << "\n---Destructing objs---\n\n" << "\033[0m";
}

int	main()
{
	std::cout << "\033[96m" << "\n---TEST FROM SUBJECT---\n\n" << "\033[0m";
	testFromSubject();

	std::cout << "\033[96m" << "\n---AN ARRAY OF ANIMALS---\n" << "\033[0m";
	testAnimalArray();

	std::cout << "\033[96m" << "\n---DEEP COPIES---\n" << "\033[0m";
	testDeepCopies();

	return (0);	
}
