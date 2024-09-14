/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:28:50 by ixu               #+#    #+#             */
/*   Updated: 2024/09/14 19:57:58 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <chrono>

static bool sortWithVector(int argc, char** argv)
{
	try
	{
		auto start = std::chrono::high_resolution_clock::now();
		std::vector<int> unsorted = PmergeMe::loadInputToVec(argc, argv);
		std::vector<int> sorted = PmergeMe::sortVec(unsorted);
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		std::cout << "Before: " << unsorted;
		std::cout << "After:  " << sorted;
		std::cout << "Time to process a range of " << unsorted.size() 
					<< " elements with std::vector: " << duration.count() << " us\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return false;
	}
	return true;
}

static bool sortWithDeque(int argc, char** argv)
{
	try
	{
		auto start = std::chrono::high_resolution_clock::now();
		std::deque<int> unsorted = PmergeMe::loadInputToDeq(argc, argv);
		std::deque<int> sorted = PmergeMe::sortDeq(unsorted);
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		std::cout << "Time to process a range of " << unsorted.size() 
					<< " elements with std::deque: " << duration.count() << " us\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return false;
	}
	return true;
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Arguments expected\n";
		return 1;
	}
	if (!sortWithVector(argc, argv))
		return 1;
	if (!sortWithDeque(argc, argv))
		return 1;
	return 0;	
}
