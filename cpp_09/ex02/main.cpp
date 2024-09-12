/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:28:50 by ixu               #+#    #+#             */
/*   Updated: 2024/09/12 11:46:01 by ixu              ###   ########.fr       */
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
			std::vector<int> vec = PmergeMe::loadInputToVec(argc, argv);
			PmergeMe::printVector(vec);
			std::vector<std::pair<int, std::size_t>> empty;
			// std::vector<PmergeMe::pair> vec1;
			// for (std::size_t i = 0; i < vec.size(); ++i)
			// 	vec1.push_back({vec[i], 0, nullptr});
			std::vector<std::vector<int>> table;
			
			// for (std::size_t i = 0; i < vec.size(); ++i)
			// {
			// 	std::vector<int> row;
			// 	row.push_back(vec[i]);
			// 	row.push_back(i);
			// 	table.push_back(row);
			// }

			// for (const auto& row : table) {
			// 	for (auto col : row)
			// 		std::cout << col << " ";
			// 	std::cout << "\n";
			// }

			std::vector<PmergeMe::pair> numbers;
			for (std::size_t i = 0; i < vec.size(); ++i)
			{
				PmergeMe::pair number = {vec[i], 0, i, 0};
				numbers.push_back(number);
			}

			// for (const auto& p : numbers) {
			// 	std::cout << "\033[0;36m" << "(" << p.small << " " << p.large << ")" << std::endl;
			// 	std::cout << "\033[0;35m" << "(" << p.smallIndex << " " << p.largeIndex << ")" << "\033[0m" << std::endl;
			// }
			// std::cout << "\033[0m" << std::endl;

			PmergeMe::mergeInsertionSort(numbers, table, empty);
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
