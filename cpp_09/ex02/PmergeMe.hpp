/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:29:22 by ixu               #+#    #+#             */
/*   Updated: 2024/09/09 13:14:46 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>

class PmergeMe
{
	public:
		std::vector<int> parseInput(int argc, char** argv);
		void mergeInsertionSort(std::vector<int>& vec);
		void mergeInsertionSort(std::deque<int>& deq);

	private:
		PmergeMe() = default;
		PmergeMe(const PmergeMe&) = default;
		PmergeMe& operator=(const PmergeMe&) = default;
		~PmergeMe() = default;
};
