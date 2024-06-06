/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:05:37 by ixu               #+#    #+#             */
/*   Updated: 2024/06/06 09:45:59 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(), y() {}

Point::Point(const float x_value, const float y_value) : x(x_value), y(y_value) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point::~Point() {}

Point& Point::operator=(const Point& other)
{
	// assignment operator cannot modify const members, so do nothing
	(void)other;
	return (*this);
}

Fixed	Point::getX() const
{
	return (this->x);
}

Fixed	Point::getY() const
{
	return (this->y);
}
