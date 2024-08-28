/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:22:30 by ixu               #+#    #+#             */
/*   Updated: 2024/08/28 23:36:31 by ixu              ###   ########.fr       */
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

// template func to print non-pointer elements
template<typename T>
void printElem(const T& elem)
{
	std::cout << elem << std::endl;
}

// template func to print elements of pointer type
template<typename T>
void printPtrValue(const T& elem)
{
	if (elem)
		std::cout << *elem << std::endl;
	else
		std::cout << "(null)" << std::endl;	
}

#endif