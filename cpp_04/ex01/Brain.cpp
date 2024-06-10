/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:55:04 by ixu               #+#    #+#             */
/*   Updated: 2024/06/10 17:16:55 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor called\n";
	for (int i = 0; i < 100; i++)
		ideas[i] = "default";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called\n";
	std::copy(std::begin(other.ideas), std::end(other.ideas), std::begin(ideas));
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}

Brain&	Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment operator called\n";
	if (this == &other)
		return (*this);
	std::copy(std::begin(other.ideas), std::end(other.ideas), std::begin(ideas));
	return (*this);
}
