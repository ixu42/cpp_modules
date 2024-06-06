/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:25:34 by ixu               #+#    #+#             */
/*   Updated: 2024/06/06 10:25:46 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

static void	check_point(Point const a, Point const b, Point const c, \
				Point const p, const std::string& name)
{
	if (bsp(a, b, c, p))
		std::cout << "Point " << name << " is inside the triangle" << std::endl;
	else
		std::cout << "Point " << name << " is outside the triangle" << std::endl;
}

int main()
{
	Point	a(0.0f, 0.0f);
	Point	b(5.5f, 0.0f);
	Point	c(0.0f, 5.5f);
	Point	p1(2.2f, 2.2f); // inside the triangle
	Point	p2(5.5f, 5.5f); // outside the triangle
	Point	p3(1.0f, 1.0f); // inside the triangle
	Point	p4(3.5f, 0.0f); // on edge, outside the triangle
	Point	p5(5.5f, 0.0f); // on vertice, outside the triangle

	check_point(a, b, c, p1, "p1");
	check_point(a, b, c, p2, "p2");
	check_point(a, b, c, p3, "p3");
	check_point(a, b, c, p4, "p4");
	check_point(a, b, c, p5, "p5");

	return (0);
}
