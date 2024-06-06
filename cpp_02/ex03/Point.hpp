/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:05:39 by ixu               #+#    #+#             */
/*   Updated: 2024/06/05 23:31:54 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;
	public:
		Point(); 
		Point(const float x_value, const float y_value);
		Point(const Point& other);
		~Point();

		Point&		operator=(const Point& other);

		Fixed		getX() const;
		Fixed		getY() const;
};

#endif
