/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:56:45 by ixu               #+#    #+#             */
/*   Updated: 2024/06/03 08:59:02 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(const std::string& typeName)
{
	type = typeName;
}

const std::string&	Weapon::getType()
{
	return (type);
}

void	Weapon::setType(const std::string& newType)
{
	type = newType;
}
