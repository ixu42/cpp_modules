/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:21:33 by ixu               #+#    #+#             */
/*   Updated: 2024/09/02 17:31:48 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <stdexcept> // std::length_error, std::logic_error
#include <string> // std::to_string
#include <algorithm> // std::sort, std::minmax_element
#include <utility> // std::pair
#include <limits> // std::numeric_limits
#include <iterator> // std::distance
#include <ostream>

class Span
{
	public:
		// use explicit to avoid implicit type conversion with single arg
		explicit Span(unsigned int);
		Span(const Span&);
		Span& operator=(const Span&);
		Span();
		~Span();

		void					addNumber(int);
		template<typename InputIt>
		void					addNumbers(InputIt first, InputIt last)
		{
			auto num_elems_to_add = std::distance(first, last);
			if (static_cast<unsigned int>(num_elems_to_add) > _maxSize - _vec.size())
				throw std::length_error("No more space to add all numbers");
			_vec.insert(_vec.end(), first, last);
		}

		unsigned int			shortestSpan();
		unsigned int			longestSpan();

		unsigned int			getMaxSize() const;
		const std::vector<int>&	getNumbers() const;
	
	private:
		std::vector<int>		_vec;
		unsigned int			_maxSize;
};

std::ostream& operator<<(std::ostream& stream, const Span&);
