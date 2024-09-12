/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:29:22 by ixu               #+#    #+#             */
/*   Updated: 2024/09/12 22:23:29 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <algorithm>

#define WHITE "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"

class PmergeMe
{
	public:
		struct pair
		{
			int large;
			int small;
			std::size_t largeIndex;
			std::size_t smallIndex;
		};
		
		static std::vector<int> loadInputToVec(int, char**);
		static std::deque<int> loadInputToDeq(int, char**);

		// static std::vector<PmergeMe::pair> mergeInsertionSort(const std::vector<PmergeMe::pair>&);
		static std::vector<PmergeMe::pair> mergeInsertionSort(const std::vector<PmergeMe::pair>&, \
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
		
		static int _recursionCounter;
		static std::size_t _size;

		template<typename... Args>
		static void log(int recursionDepth, const Args&... args) {
			#if DEBUG_MODE
				std::string color = WHITE;
				switch (recursionDepth % 5) {
					case 1: color = GREEN; break;
					case 2: color = CYAN; break;
					case 3: color = YELLOW; break;
					case 4: color = MAGENTA; break;
					case 0: color = BLUE; break;
				}
				std::cout << color << "Recursion depth: " << recursionDepth << " | ";
				if constexpr (sizeof...(args) > 0)
					((std::cout << args), ...) << RESET << std::endl;
				else
					std::cout << RESET << std::endl;
			#else
				static_cast<void>(recursionDepth);
				(static_cast<void>(args), ...);
			#endif
		}
};

std::ostream& operator<<(std::ostream&, const std::vector<PmergeMe::pair>&);
std::ostream& operator<<(std::ostream&, const std::vector<std::vector<int>>&);
std::ostream& operator<<(std::ostream&, const std::vector<std::pair<int, std::size_t>>&);
