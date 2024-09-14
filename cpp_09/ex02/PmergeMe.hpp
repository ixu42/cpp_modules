/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:29:22 by ixu               #+#    #+#             */
/*   Updated: 2024/09/14 16:57:48 by ixu              ###   ########.fr       */
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
#include <iterator>

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
		struct Pair
		{
			int large;
			int small;
			std::size_t largeIndex;
			std::size_t smallIndex;
		};

		using PairVec = std::vector<PmergeMe::Pair>;
		using Int2DVec = std::vector<std::vector<int>>;

		static std::vector<int> loadInputToVec(int, char**);
		static std::deque<int> loadInputToDeq(int, char**);
		static std::vector<int> sortVec(const std::vector<int>&);

	private:
		PmergeMe() = default;
		PmergeMe(const PmergeMe&) = default;
		PmergeMe& operator=(const PmergeMe&) = default;
		~PmergeMe() = default;

		static void validateInput(int, char**);
		static PairVec pairAndSort(const PairVec&);
		static void updateTable(Int2DVec&, PairVec&, int);
		static std::size_t getPairedSmallIndex(const Pair&, const Int2DVec&, int);
		static void insertSmallestIntoMainChain(PairVec&, const Int2DVec&, int);
		static PairVec extractPendingNbrs(const PairVec&, const Pair&, const Int2DVec&, int);
		static std::vector<int> generateJacobsthalNbrs(int);
		static void insert(PairVec&, const PairVec&, int, std::size_t&);
		static void binaryInsertion(const PairVec&, PairVec&);
		static PairVec mergeInsertionSort(const PairVec&, Int2DVec&);

		template<typename... Args>
		static void log(int recursionDepth, const Args&... args)
		{
			#if DEBUG_MODE
				if (recursionDepth)
				{
					std::string color = WHITE;
					switch (recursionDepth % 5)
					{
						case 1: color = GREEN; break;
						case 2: color = CYAN; break;
						case 3: color = YELLOW; break;
						case 4: color = MAGENTA; break;
						case 0: color = BLUE; break;
					}
					std::cout << color << "Recursion depth: " << recursionDepth << " | ";
				}
				if constexpr (sizeof...(args) > 0)
					((std::cout << args), ...) << RESET << std::endl;
				else
					std::cout << RESET << std::endl;
			#else
				static_cast<void>(recursionDepth);
				(static_cast<void>(args), ...);
			#endif
		}

		static int _recursionCounter;
};

std::ostream& operator<<(std::ostream&, const PmergeMe::PairVec&);
std::ostream& operator<<(std::ostream&, const PmergeMe::Int2DVec&);
std::ostream& operator<<(std::ostream&, const std::vector<int>&);
