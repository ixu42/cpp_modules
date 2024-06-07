/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:16:35 by ixu               #+#    #+#             */
/*   Updated: 2024/06/07 18:10:03 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

static void	testClapTrap()
{
	ClapTrap	foo("Foo");

	foo.attack("Baz");
	foo.takeDamage(20);
	foo.beRepaired(10);
}

static void	testScavTrap()
{
	// should call ClapTrap constructor first, then ScavTrap constructor
	ScavTrap	bar("Bar");

	bar.attack("Baz");
	bar.guardGate();

	// should call ScavTrap destructor first, then ClapTrap destructor
}

int	main()
{
	std::cout << "---TEST CLAPTRAP---\n\n";
	testClapTrap();
	std::cout << "\n---TEST SCAVTRAP---\n\n";
	testScavTrap();
	return (0);
}
