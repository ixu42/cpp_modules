/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:51:28 by ixu               #+#    #+#             */
/*   Updated: 2024/06/10 11:50:38 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

static void	testAnimal()
{
	Animal	a;
	a.makeSound();
}

static void	testCat()
{
	Cat	a;
	a.makeSound();
}

static void	testDog()
{
	Dog	a;
	a.makeSound();
}

int	main()
{	
	std::cout << "\n---OWN TESTS---\n";
	std::cout << "\n---Animal---\n\n";
	testAnimal();
	std::cout << "\n---Cat---\n\n";
	testCat();
	std::cout << "\n---Dog---\n\n";
	testDog();

	std::cout << "\n---TEST FROM SUBJECT---\n\n";
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound(); // will output the dog sound!
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\n---TEST WRONGCAT & WRONGANIMAL---\n\n";
	const WrongAnimal*	wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound(); // will output wrong animal sound!

	delete wrongCat;

	return (0);	
}
