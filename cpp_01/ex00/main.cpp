/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:23:15 by ixu               #+#    #+#             */
/*   Updated: 2024/05/29 20:11:06 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

static void	createZombie()
{
	Zombie zombie = Zombie();
	zombie.announce();
}

int	main()
{
	/* create an instance of Zombie with default name 
	and call member function announce(); */
	createZombie();

	// allocate zombie on the heap
	Zombie *zombie = newZombie("Bar");
	// use the object outside the function scope
	zombie->announce();
	delete zombie;

	// allocate zombie on the stack
	randomChump("Baz");

	return (0);
}
