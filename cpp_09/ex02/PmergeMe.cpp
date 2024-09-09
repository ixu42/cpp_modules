/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:29:08 by ixu               #+#    #+#             */
/*   Updated: 2024/09/09 15:21:10 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::validateInput(int argc, char** argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string str = argv[i];
		int number;
		std::size_t pos;
		try
		{
			number = std::stoi(str, &pos);
		}
		catch (const std::invalid_argument& e)
		{
			throw std::runtime_error("not an integer => " + str);
		}
		catch (const std::out_of_range& e)
		{
			throw std::runtime_error("out of range => " + str);
		}
		if (pos != str.size())
			throw std::runtime_error("not an integer => " + str);
		if (number <= 0)
			throw std::runtime_error("not a positive integer => " + str);
	}
}

std::vector<int> PmergeMe::loadInputToVec(int argc, char** argv)
{
	validateInput(argc, argv);

	std::vector<int> vec;
	for (int i = 1; i < argc; ++i)
	{
		int number = std::stoi(argv[i]);
		vec.push_back(number);
	}
	return vec;
}

std::deque<int> PmergeMe::loadInputToDeq(int argc, char** argv)
{
	validateInput(argc, argv);

	std::deque<int> deq;
	for (int i = 1; i < argc; ++i)
	{
		int number = std::stoi(argv[i]);
		deq.push_back(number);
	}
	return deq;
}

void PmergeMe::printVector(std::vector<int>& vec)
{
	for (int number : vec)
		std::cout << number << ' ';

	std::cout << '\n';
}

void PmergeMe::printDeque(std::deque<int>& deq)
{
	for (int number : deq)
		std::cout << number << ' ';

	std::cout << '\n';
}
