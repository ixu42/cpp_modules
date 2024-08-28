/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:22:30 by ixu               #+#    #+#             */
/*   Updated: 2024/08/28 22:07:35 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T, typename F>
void iter(T* array, size_t length, F func)
{
	for (size_t i = 0; i < length; ++i)
		func(array[i]);
}

template<typename T>
void printArray(const T& elem)
{
	std::cout << elem << std::endl;
}

#endif