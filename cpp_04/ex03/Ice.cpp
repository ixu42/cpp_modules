/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:13:38 by ixu               #+#    #+#             */
/*   Updated: 2024/06/12 10:35:17 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice&) : AMateria("ice") {}

Ice::~Ice() {}

Ice&	Ice::operator=(const Ice&)
{
	return (*this);
}

std::string const &	Ice::getType() const
{
	return (this->_type);
}

Ice*	Ice::clone() const
{
	return (new Ice());
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
