/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:02:26 by ixu               #+#    #+#             */
/*   Updated: 2024/06/12 10:34:43 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria& other) : AMateria(other._type) {}

AMateria::~AMateria() {}

AMateria&	AMateria::operator=(const AMateria&)
{
	return (*this);
}

std::string const &	AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << target.getName() << " uses AMateria " << _type << std::endl;
}
