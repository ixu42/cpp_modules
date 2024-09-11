/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:29:22 by ixu               #+#    #+#             */
/*   Updated: 2024/09/11 18:50:37 by ixu              ###   ########.fr       */
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
		static std::vector<int> loadInputToVec(int, char**);
		static std::deque<int> loadInputToDeq(int, char**);

		static std::vector<int> mergeInsertionSort(const std::vector<int>&);

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
		
		static int counter;
		

};
