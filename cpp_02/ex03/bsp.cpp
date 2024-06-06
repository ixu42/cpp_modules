/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:06:09 by ixu               #+#    #+#             */
/*   Updated: 2024/06/06 10:24:17 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

static float	triangleArea(Point const a, Point const b, Point const c)
{
	Fixed	ax = a.getX();
	Fixed	ay = a.getY();
	Fixed	bx = b.getX();
	Fixed	by = b.getY();
	Fixed	cx = c.getX();
	Fixed	cy = c.getY();

	Fixed	area = (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by)) / 2;
	if (area < 0)
		return (area.toFloat() * -1);
	return (area.toFloat());
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	totalArea = triangleArea(a, b, c);
	float	area1 = triangleArea(point, a, b);
	float	area2 = triangleArea(point, b, c);
	float	area3 = triangleArea(point, c, a);

	if (area1 == 0 || area2 == 0 || area3 == 0)
		return (false);

	// a small epsilon used for floating-point comparison
	if (std::abs(totalArea - (area1 + area2 + area3)) < 0.01)
		return (true);
	else
		return (false);
}
