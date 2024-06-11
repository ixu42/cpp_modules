/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:55:04 by ixu               #+#    #+#             */
/*   Updated: 2024/06/11 15:16:27 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor called\n";
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
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

void	Brain::printIdeas()
{
	for (int i = 0; i < 100; i++)
	{
		if (!ideas[i].empty())
			std::cout << ideas[i] << std::endl;
		else
			break ;
	}
}

void	Brain::addIdea(const std::string& newIdea)
{
	for (int i = 0; i < 100; i++)
	{
		if (ideas[i].empty())
		{
			ideas[i] = newIdea;
			break ;
		}
	}
}
