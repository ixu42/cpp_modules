/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:34:56 by ixu               #+#    #+#             */
/*   Updated: 2024/05/30 10:53:16 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main()
{
	int		zombieCount = 10;
	Zombie*	zombieArray = zombieHorde(zombieCount, "Bar");

	for (int i = 0; i < zombieCount; i++)
		zombieArray[i].announce();

	for (int i = zombieCount - 1; i >= 0; i--)
		zombieArray[i].~Zombie();
	
	operator delete[](zombieArray);

	return (0);
}
