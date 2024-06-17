/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:55:04 by ixu               #+#    #+#             */
/*   Updated: 2024/06/17 11:54:00 by ixu              ###   ########.fr       */
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
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
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
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
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
