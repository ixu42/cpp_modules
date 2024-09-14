/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:28:50 by ixu               #+#    #+#             */
/*   Updated: 2024/09/14 16:56:16 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Arguments expected\n";
		return 1;
	}

	std::cout << "std::vector\n";
	{
		try
		{
			std::vector<int> unsorted = PmergeMe::loadInputToVec(argc, argv);
			std::cout << unsorted;
			std::vector<int> sorted = PmergeMe::sortVec(unsorted);
			std::cout << sorted;
		}
		catch (const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
			return 1;
		}
	}

	// std::cout << "std::deque\n";
	// {
	// 	try
	// 	{
	// 		std::deque<int> deq = PmergeMe::loadInputToDeq(argc, argv);
	// 		PmergeMe::printDeque(deq);
	// 		PmergeMe::mergeInsertionSort(deq);
	// 	}
	// 	catch (const std::exception& e)
	// 	{
	// 		std::cerr << "Error: " << e.what() << '\n';
	// 		return 1;
	// 	}
	// }
	
}
