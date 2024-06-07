/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:16:35 by ixu               #+#    #+#             */
/*   Updated: 2024/06/07 21:03:31 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

static void	testClapTrap()
{
	ClapTrap	foo("Foo");

	foo.attack("a skeleton");
	foo.takeDamage(20);
	foo.beRepaired(10);
}

static void	testScavTrap()
{
	// should call ClapTrap constructor first, then ScavTrap constructor
	ScavTrap	bar("Bar");

	bar.attack("a greydwarf");
	bar.guardGate();

	// should call ScavTrap destructor first, then ClapTrap destructor
}

static void	testFragTrap()
{
	// should call ClapTrap constructor first, then FragTrap constructor
	FragTrap	baz("Baz");

	baz.attack("a troll");
	baz.highFivesGuys();

	// should call FragTrap destructor first, then ClapTrap destructor
}

int	main()
{
	std::cout << "---TEST CLAPTRAP---\n\n";
	testClapTrap();
	std::cout << "\n---TEST SCAVTRAP---\n\n";
	testScavTrap();
	std::cout << "\n---TEST FRAGTRAP---\n\n";
	testFragTrap();
	return (0);
}
