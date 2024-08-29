/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:19:39 by ixu               #+#    #+#             */
/*   Updated: 2024/08/29 16:18:10 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>

template<typename T>
class Array
{
	public:
		Array();
		Array(unsigned int);
		Array(const Array<T>&);
		Array<T>& operator=(const Array<T>&);
		~Array();

		T& operator[](int);
		const T& operator[](int) const;
		unsigned int size() const;

	private:
		T*				_data;
		unsigned int	_size;
};

#include "Array.tpp"