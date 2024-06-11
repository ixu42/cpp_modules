/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:51:28 by ixu               #+#    #+#             */
/*   Updated: 2024/06/11 16:10:30 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

static void	ownTests()
{
	std::cout << "\033[36m" << "\n---Animal---\n" << "\033[0m";
	{
		std::cout << "\033[95m" << "\n---Constructing obj---\n" << "\033[0m";
		Animal	a;
		std::cout << "\033[95m" << "\n---Sound---\n" << "\033[0m";
		a.makeSound();
		std::cout << "\033[95m" << "\n---Destructing obj---\n" << "\033[0m";
	}
	std::cout << "\033[36m" << "\n---Cat---\n" << "\033[0m";
	{
		std::cout << "\033[95m" << "\n---Constructing obj---\n" << "\033[0m";
		Cat	a;
		std::cout << "\033[95m" << "\n---Sound---\n" << "\033[0m";
		a.makeSound();
		std::cout << "\033[95m" << "\n---Destructing obj---\n" << "\033[0m";
	}
	std::cout << "\033[36m" << "\n---Dog---\n" << "\033[0m";
	{
		std::cout << "\033[95m" << "\n---Constructing obj---\n" << "\033[0m";
		Dog	a;
		std::cout << "\033[95m" << "\n---Sound---\n" << "\033[0m";
		a.makeSound();
		std::cout << "\033[95m" << "\n---Destructing obj---\n" << "\033[0m";
	}
}

static void	testFromSubject()
{
	std::cout << "\033[95m" << "\n---Constructing objs---\n" << "\033[0m";
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << "\033[95m" << "\n---Type---\n" << "\033[0m";
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "\033[95m" << "\n---Sounds---\n" << "\033[0m";
	i->makeSound(); // will output the cat sound!
	j->makeSound(); // will output the dog sound!
	meta->makeSound();

	std::cout << "\033[95m" << "\n---Destructing objs---\n" << "\033[0m";
	delete meta;
	delete j;
	delete i;
}

static void	testWrongAnimal()
{
	std::cout << "\033[95m" << "\n---Constructing obj---\n" << "\033[0m";
	const WrongAnimal*	wrongCat = new WrongCat();

	std::cout << "\033[95m" << "\n---Type---\n" << "\033[0m";
	std::cout << wrongCat->getType() << " " << std::endl;
	std::cout << "\033[95m" << "\n---Sound---\n" << "\033[0m";
	wrongCat->makeSound(); // will output wrong animal sound!

	std::cout << "\033[95m" << "\n---Destructing obj---\n" << "\033[0m";
	delete wrongCat;
}

int	main()
{	
	std::cout << "\033[96m" << "---OWN TESTS---\n" << "\033[0m";
	ownTests();

	std::cout << "\033[96m" << "\n---TEST FROM SUBJECT---\n" << "\033[0m";
	testFromSubject();

	std::cout << "\033[96m" << "\n---TEST WRONGCAT & WRONGANIMAL---\n" << "\033[0m";
	testWrongAnimal();

	return (0);	
}
