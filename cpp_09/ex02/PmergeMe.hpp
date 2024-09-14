/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:29:22 by ixu               #+#    #+#             */
/*   Updated: 2024/09/14 20:07:57 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <stdexcept>
#include <algorithm> // std::lower_bound
#include <iterator> // std::next, std::advance

#define WHITE "\033[0;30m"
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

		// std::vector
		using PairVec = std::vector<Pair>;
		using Int2dVec = std::vector<std::vector<int>>;
		static std::vector<int> loadInputToVec(int, char**);
		static std::vector<int> sortVec(const std::vector<int>&);

		// std::deque
		using PairDeq = std::deque<Pair>;
		using Int2dDeq = std::deque<std::deque<int>>;
		static std::deque<int> loadInputToDeq(int, char**);
		static std::deque<int> sortDeq(const std::deque<int>&);

	private:
		PmergeMe() = default;
		PmergeMe(const PmergeMe&) = default;
		PmergeMe& operator=(const PmergeMe&) = default;
		~PmergeMe() = default;

		static void validateInput(int, char**);

		// std::vector
		static PairVec pairAndSort(const PairVec&);
		static void updateTable(Int2dVec&, PairVec&, int);
		static std::size_t getPairedSmallIndex(const Pair&, const Int2dVec&, int);
		static void insertSmallestIntoMainChain(PairVec&, const Int2dVec&, int);
		static PairVec extractPendingNbrs(const PairVec&, const Pair&, const Int2dVec&, int);
		static std::vector<int> genJacobsthalVec(int);
		static void insert(PairVec&, const PairVec&, int, std::size_t&);
		static void binaryInsertion(const PairVec&, PairVec&);
		static PairVec mergeInsertionSort(const PairVec&, Int2dVec&);

		// std::deque
		static PairDeq pairAndSort(const PairDeq&);
		static void updateTable(Int2dDeq&, PairDeq&, int);
		static std::size_t getPairedSmallIndex(const Pair&, const Int2dDeq&, int);
		static void insertSmallestIntoMainChain(PairDeq&, const Int2dDeq&, int);
		static PairDeq extractPendingNbrs(const PairDeq&, const Pair&, const Int2dDeq&, int);
		static std::deque<int> genJacobsthalDeq(int);
		static void insert(PairDeq&, const PairDeq&, int, std::size_t&);
		static void binaryInsertion(const PairDeq&, PairDeq&);
		static PairDeq mergeInsertionSort(const PairDeq&, Int2dDeq&);

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
std::ostream& operator<<(std::ostream&, const PmergeMe::Int2dVec&);
std::ostream& operator<<(std::ostream&, const std::vector<int>&);
std::ostream& operator<<(std::ostream&, const std::deque<int>&);
