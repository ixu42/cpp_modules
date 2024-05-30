/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:34:47 by ixu               #+#    #+#             */
/*   Updated: 2024/05/30 10:53:24 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	// allocate raw memory for array without constructing objects
	Zombie*	zombieArray = static_cast<Zombie*>(operator new[](N * sizeof(Zombie)));

	// construct objects in pre-allocated memory using placement new
	for (int i = 0; i < N; i++)
		new(&zombieArray[i]) Zombie(name);

	return (zombieArray);
}
