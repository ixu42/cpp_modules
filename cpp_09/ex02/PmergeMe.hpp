/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:29:22 by ixu               #+#    #+#             */
/*   Updated: 2024/09/09 15:12:35 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <stdexcept>

class PmergeMe
{
	public:
		static std::vector<int> loadInputToVec(int argc, char** argv);
		static std::deque<int> loadInputToDeq(int argc, char** argv);

		static void mergeInsertionSort(std::vector<int>& vec);
		static void mergeInsertionSort(std::deque<int>& deq);

		static void printVector(std::vector<int>& vec);
		static void printDeque(std::deque<int>& deq);

	private:
		PmergeMe() = default;
		PmergeMe(const PmergeMe&) = default;
		PmergeMe& operator=(const PmergeMe&) = default;
		~PmergeMe() = default;

		static void validateInput(int argc, char** argv);
};
