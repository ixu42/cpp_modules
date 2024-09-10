/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:29:08 by ixu               #+#    #+#             */
/*   Updated: 2024/09/10 17:28:52 by ixu              ###   ########.fr       */
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

std::vector<std::pair<int, int>> PmergeMe::pairAndSort(const std::vector<int>& vec)
{
	std::vector<std::pair<int, int>> pairs;

	for (std::size_t i = 0; i < vec.size(); i += 2)
	{
		int first = vec[i];
		int second;
		if (i + 1 < vec.size())
			second = vec[i + 1];
		else
			second = 0;

		std::pair<int, int> elemPair = std::make_pair(first, second);
		
		if (elemPair.first < elemPair.second)
			std::swap(elemPair.first, elemPair.second);

		pairs.push_back(elemPair);
	}

	return pairs;
}

void PmergeMe::printPairs(const std::vector<std::pair<int, int>>& pairs)
{
	for (const auto& p : pairs)
		std::cout << '(' << p.first << ' ' << p.second << ')';
	std::cout << '\n';
}

void PmergeMe::binaryInsert(std::vector<int>& sorted, int value)
{
	auto it = std::lower_bound(sorted.begin(), sorted.end(), value);
	sorted.insert(it, value);
}

/**
 * roman numbers: depth of recursion (1st func call, 2nd func call, and so forth)
 * arabic numbers: steps as explained in the function body
 * 
 * example: unsorted sequence => 6 7 8 5 3 1 2 4
 * 
 * I:
 * 1 && 2      => (6 7)(5 8)(1 3)(2 4)
 * 3           => 7 8 3 4 passed to mergeInsertionSort()
 * 
 * II:
 * 1 && 2      => (7 8)(3 4)
 * 3           => 8 4 passed to mergeInsertionSort()
 * 
 * III:
 * 1 && 2      => (4 8)
 * 3           => 8 passed to mergeInsertionSort()
 * 
 * IV:
 * return vector containing 8
 * 
 * III:
 * 3           => 8
 * 4           => 4 8
 * 5 && return => 4 8
 * 
 * II:
 * 3           => 4 8
 * 4           => 3 4 8
 * 5 && return => 3 4 7 8
 * 
 * I:
 * 3           => 3 4 7 8
 * 4           => 1 3 4 7 8
 * 5 && return => 1 2 3 4 5 6 7 8
 */

std::vector<int> PmergeMe::mergeInsertionSort(const std::vector<int>& vec)
{
	if (vec.size() <= 1)
		return vec;

	// step 1 & 2: pair and sort within each pair
	auto pairs = pairAndSort(vec);
	// printPairs(pairs);

	// step 3: recursively sort larger elements
	std::vector<int> largerElements;
	for (const auto& p : pairs)
		largerElements.push_back(p.first);
	std::vector<int> sortedSequence = mergeInsertionSort(largerElements);
	std::cout << "\033[0;31m";
	printVector(sortedSequence);
	std::cout << "\033[0m" << std::endl;

	// step 4: insert the smallest element and larger elements into sortedSequence
	// std::vector<int> sortedSequence;
	int smallest;
	// for (const auto& p : pairs)
	for (auto it = pairs.begin(); it != pairs.end(); ++it)
	{
		// if (p.first == sortedSequence[0])
		// 	smallest = p.second;
		if (it->first == sortedSequence[0])
		{
			smallest = it->second;
			pairs.erase(it);
			break ;
		}
	}
	sortedSequence.insert(sortedSequence.begin(), smallest);

	std::cout << "\033[0;33m";
	printVector(sortedSequence);
	std::cout << "\033[0m" << std::endl;

	// step 5: binary search insert remaining smaller elements into sortedSequence
	for (size_t i = 0; i < pairs.size(); ++i)
		binaryInsert(sortedSequence, pairs[i].second);

	std::cout << "\033[0;32m";
	printVector(sortedSequence);
	std::cout << "\033[0m" << std::endl;

	return sortedSequence;
}

void PmergeMe::mergeInsertionSort(std::deque<int>& deq)
{
	(void)deq;
	// auto pairs = pairAndSort(deq);
	// printPairs(pairs);
}
