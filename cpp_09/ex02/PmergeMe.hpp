/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:29:22 by ixu               #+#    #+#             */
/*   Updated: 2024/09/12 10:41:35 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <unordered_map>

class PmergeMe
{
	public:
		struct pairs
		{
			int large;
			int small;
			std::size_t largeIndex;
			std::size_t smallIndex;
		};
		
		static std::vector<int> loadInputToVec(int, char**);
		static std::deque<int> loadInputToDeq(int, char**);

		// static std::vector<PmergeMe::pair> mergeInsertionSort(const std::vector<PmergeMe::pair>&);
		static std::vector<PmergeMe::pairs> mergeInsertionSort(const std::vector<PmergeMe::pairs>&, \
			std::vector<std::vector<int>>&, std::vector<std::pair<int, std::size_t>>&);

		static void printVector(std::vector<int>&);
		static void printDeque(std::deque<int>&);


	private:
		PmergeMe() = default;
		PmergeMe(const PmergeMe&) = default;
		PmergeMe& operator=(const PmergeMe&) = default;
		~PmergeMe() = default;

		static void validateInput(int, char**);
		// static std::vector<std::pair<int, int>> pairAndSort(const std::vector<int>&);
		// static void printPairs(const std::vector<std::pair<int, int>>&);
		// static void binaryInsert(std::vector<int>& sorted, int value);
		
		static int recursionCounter;
		static int index;

};
