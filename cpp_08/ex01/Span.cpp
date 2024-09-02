/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:34:15 by ixu               #+#    #+#             */
/*   Updated: 2024/09/02 17:34:36 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) : _vec(other._vec), _maxSize(other._maxSize) {}

Span& Span::operator=(const Span& other)
{
	if (this == &other)
		return *this;
	_maxSize = other._maxSize;
	_vec = other._vec;
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (_vec.size() >= _maxSize)
		throw std::length_error("No more space to add number " + std::to_string(number));
	_vec.push_back(number);
}

unsigned int Span::shortestSpan()
{
	if (_vec.size() < 2)
		throw std::logic_error("Cannot check the shortest span with fewer than 2 numbers stored");
	std::vector<int> sorted_vec = _vec;
	std::sort(sorted_vec.begin(), sorted_vec.end());

	unsigned int minSpan = std::numeric_limits<unsigned int>::max();
	for (unsigned int i = 1; i < sorted_vec.size(); ++i)
	{
		unsigned int span = sorted_vec[i] - sorted_vec[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

unsigned int Span::longestSpan()
{
	if (_vec.size() < 2)
		throw std::logic_error("Cannot check the longest span with fewer than 2 numbers stored");

	auto minMax = std::minmax_element(_vec.begin(), _vec.end());
	return static_cast<unsigned int>(*minMax.second - *minMax.first);
}

unsigned int Span::getMaxSize() const
{
	return _maxSize;
}

const std::vector<int>& Span::getNumbers() const
{
	return _vec;
}

std::ostream& operator<<(std::ostream& stream, const Span& span)
{
	stream << "max size: " << span.getMaxSize() << std::endl;
	stream << "{ ";
	for (int num : span.getNumbers())
		stream << num << " ";
	stream << "}" << std::endl;
	return stream;
}
