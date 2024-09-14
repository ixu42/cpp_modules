/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:28:50 by ixu               #+#    #+#             */
/*   Updated: 2024/09/14 17:38:56 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <chrono>

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Arguments expected\n";
		return 1;
	}

	{
		try
		{
			auto start = std::chrono::high_resolution_clock::now();
			std::vector<int> unsorted = PmergeMe::loadInputToVec(argc, argv);
			// std::cout << unsorted;
			std::vector<int> sorted = PmergeMe::sortVec(unsorted);
			// std::cout << sorted;
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
