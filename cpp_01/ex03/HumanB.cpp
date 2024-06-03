/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:56:51 by ixu               #+#    #+#             */
/*   Updated: 2024/06/03 09:54:53 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstddef>
#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : weapon(nullptr), name(name) {}

void	HumanB::attack()
{
	if (weapon && !weapon->getType().empty())
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " does not have a weapon " << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}
