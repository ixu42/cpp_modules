/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:45:04 by ixu               #+#    #+#             */
/*   Updated: 2024/08/26 11:40:58 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _name("default"), _id(42) {}

Data::Data(const Data& other) : _name(other._name), _id(other._id) {}

Data& Data::operator=(const Data& other)
{
	if (this == &other)
		return *this;
	this->_name = other._name;
	this->_id = other._id;
	return *this;
}

Data::~Data() {}

std::string Data::getName()
{
	return _name;
}

int Data::getId()
{
	return _id;
}

std::ostream& operator<<(std::ostream& stream, Data& data)
{
	stream << data.getName() << ", student id " << data.getId() << std::endl;
	return stream;
}

