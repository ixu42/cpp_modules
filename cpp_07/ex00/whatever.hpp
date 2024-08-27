/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:47:07 by ixu               #+#    #+#             */
/*   Updated: 2024/08/27 23:15:04 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void swap(T& arg1, T& arg2)
{
	T tmp = arg1;
	arg1 = arg2;
	arg2 = tmp;
}

template<typename T>
T min(const T& arg1, const T& arg2)
{
	if (arg1 < arg2)
		return arg1;
	return arg2;
}

template<typename T>
T max(const T& arg1, const T& arg2)
{
	if (arg1 > arg2)
		return arg1;
	return arg2;
}

#endif