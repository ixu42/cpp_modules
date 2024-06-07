/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:16:35 by ixu               #+#    #+#             */
/*   Updated: 2024/06/07 22:36:11 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

static void	testClapTrap()
{
	ClapTrap	foo("Foo");

	foo.attack("a Skeleton");
	foo.takeDamage(20);
	foo.beRepaired(10);
}

static void	testScavTrap()
{
	ScavTrap	bar("Bar");

	bar.attack("a Greydwarf");
	bar.guardGate();
}

static void	testFragTrap()
{
	FragTrap	baz("Baz");

	baz.attack("a Troll");
	baz.highFivesGuys();
}

static void	testDiamondTrap()
{
	DiamondTrap	dt("Qux");

	dt.whoAmI();
	dt.attack("a Dvergr");
}

int	main()
{
	std::cout << "---TEST CLAPTRAP---\n\n";
	testClapTrap();
	std::cout << "\n---TEST SCAVTRAP---\n\n";
	testScavTrap();
	std::cout << "\n---TEST FRAGTRAP---\n\n";
	testFragTrap();
	std::cout << "\n---TEST DIAMONDTRAP---\n\n";
	testDiamondTrap();
	return (0);
}
