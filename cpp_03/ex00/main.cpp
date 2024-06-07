/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:16:35 by ixu               #+#    #+#             */
/*   Updated: 2024/06/07 12:53:48 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	foo("Foo");
	ClapTrap	bar("Bar");
	ClapTrap	baz("Baz");

	foo.attack("Bar");
	bar.takeDamage(5);
	bar.beRepaired(3);
	foo.attack("Bar");
	bar.takeDamage(10);

	bar.attack("Foo");

	for (int i = 0; i < 10; i++)
		foo.attack("Baz");

	return (0);
}
