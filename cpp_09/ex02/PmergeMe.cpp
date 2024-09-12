/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:29:08 by ixu               #+#    #+#             */
/*   Updated: 2024/09/12 22:34:41 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
std::size_t PmergeMe::_size = 0;
int PmergeMe::_recursionCounter = 1;

void PmergeMe::validateInput(int argc, char** argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string str = argv[i];
		int number;
		std::size_t pos;
		try
		{
			number = std::stoi(str, &pos);
		}
		catch (const std::invalid_argument& e)
		{
			throw std::runtime_error("not an integer => " + str);
		}
		catch (const std::out_of_range& e)
		{
			throw std::runtime_error("out of range => " + str);
		}
		if (pos != str.size())
			throw std::runtime_error("not an integer => " + str);
		if (number <= 0)
			throw std::runtime_error("not a positive integer => " + str);
	}
}

std::vector<int> PmergeMe::loadInputToVec(int argc, char** argv)
{
	validateInput(argc, argv);

	std::vector<int> vec;
	for (int i = 1; i < argc; ++i)
	{
		int number = std::stoi(argv[i]);
		vec.push_back(number);
	}
	return vec;
}

std::deque<int> PmergeMe::loadInputToDeq(int argc, char** argv)
{
	validateInput(argc, argv);

	std::deque<int> deq;
	for (int i = 1; i < argc; ++i)
	{
		int number = std::stoi(argv[i]);
		deq.push_back(number);
	}
	return deq;
}

void PmergeMe::printVector(std::vector<int>& vec)
{
	for (int number : vec)
		std::cout << number << ' ';

	std::cout << '\n';
}

void PmergeMe::printDeque(std::deque<int>& deq)
{
	for (int number : deq)
		std::cout << number << ' ';

	std::cout << '\n';
}

// std::vector<std::pair<int, int>> PmergeMe::pairAndSort(const std::vector<int>& vec)
// {
// 	std::vector<std::pair<int, int>> pairs;

// 	for (std::size_t i = 0; i < vec.size(); i += 2)
// 	{
// 		int first = vec[i];
// 		int second;
// 		if (i + 1 < vec.size())
// 			second = vec[i + 1];
// 		else
// 			second = 0;

// 		std::pair<int, int> elemPair = std::make_pair(first, second);
		
// 		if (elemPair.first < elemPair.second)
// 			std::swap(elemPair.first, elemPair.second);

// 		pairs.push_back(elemPair);
// 	}

// 	return pairs;
// }

// void PmergeMe::printPairs(const std::vector<std::pair<int, int>>& pairs)
// {
// 	for (const auto& p : pairs)
// 		std::cout << '(' << p.first << ' ' << p.second << ')';
// 	std::cout << '\n';
// }

// void PmergeMe::binaryInsert(std::vector<int>& sorted, int value)
// {
// 	auto it = std::lower_bound(sorted.begin(), sorted.end(), value);
// 	sorted.insert(it, value);
// }

/**
 * roman numbers: depth of recursion (1st func call, 2nd func call, and so forth)
 * arabic numbers: steps as explained in the function body
 * 
 * example: unsorted sequence => 6 7 8 5 3 1 2 4
 * 
 * I:
 * 1 && 2      => (6 7)(5 8)(1 3)(2 4)
 * 3           => 7 8 3 4 passed to mergeInsertionSort()
 * 
 * II:
 * 1 && 2      => (7 8)(3 4)
 * 3           => 8 4 passed to mergeInsertionSort()
 * 
 * III:
 * 1 && 2      => (4 8)
 * 3           => 8 passed to mergeInsertionSort()
 * 
 * IV:
 * return vector containing 8
 * 
 * III:
 * 3           => 8
 * 4           => 4 8
 * 5 && return => 4 8
 * 
 * II:
 * 3           => 4 8
 * 4           => 3 4 8
 * 5 && return => 3 4 7 8
 * 
 * I:
 * 3           => 3 4 7 8
 * 4           => 1 3 4 7 8
 * 5 && return => 1 2 3 4 5 6 7 8
 */

std::vector<PmergeMe::pair> PmergeMe::mergeInsertionSort(const std::vector<PmergeMe::pair>& vec, \
	std::vector<std::vector<int>>& table, std::vector<std::pair<int, std::size_t>>& ref)
{
	int recursionDepth = _recursionCounter++;

	if (vec.size() <= 1)
		return vec;

	// steps 1 && 2: pair and sort within each pair
	std::vector<PmergeMe::pair> pairs;

	for (std::size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		int first = vec[i].large;
		std::size_t firstIndex = vec[i].largeIndex;
		int second;
		std::size_t secondIndex;
		second = vec[i + 1].large;
		secondIndex = vec[i + 1].largeIndex;

		if (first > second) {
			pairs.push_back({first, second, firstIndex, secondIndex});
		}
		else {
			pairs.push_back({second, first, secondIndex, firstIndex});
		}
	}
	PmergeMe::pair odd;
	odd.large = -1;
	if (vec.size() % 2 != 0) {
		log(recursionDepth, "odd found here!");
		odd = {vec.back().large, vec.back().small, vec.back().largeIndex, vec.back().smallIndex};
	}

	for (std::size_t i = 0; i < pairs.size(); ++i) {
		if (recursionDepth == 1) {
			pairs[i].smallIndex = i * 2;
			pairs[i].largeIndex = i * 2 + 1;
			std::vector<int> row1;
			row1.push_back(pairs[i].small);
			row1.push_back(i * 2);
			table.push_back(row1);
			std::vector<int> row2;
			row2.push_back(pairs[i].large);
			row2.push_back(i * 2 + 1);
			table.push_back(row2);
			_size += 2;
		}
		else {
			std::cout << "pair: " << pairs[i].small << " " << pairs[i].large << "\n";
			std::cout << "pairIdx: " << pairs[i].smallIndex << " " << pairs[i].largeIndex << "\n";
			std::cout << "_size: " << _size << "\n";
			table[pairs[i].smallIndex].push_back(_size++);
			table[pairs[i].largeIndex].push_back(_size++);
		}
		ref.push_back({pairs[i].small, pairs[i].smallIndex});
		ref.push_back({pairs[i].large, pairs[i].largeIndex});
	}

	log(recursionDepth, "Steps 1 && 2:\n", pairs);

	// step 3: recursively sort the pairs according to larger elements
	std::vector<PmergeMe::pair> mainChain = mergeInsertionSort(pairs, table, ref);
	log(recursionDepth, "Step 3:\n", mainChain);
	log(recursionDepth, "Step 3:\n", table);

	// step 4: insert the smallest element into mainChain
	std::cout << "mainChain[0].largeIndex: " << mainChain[0].largeIndex << "\n";
	std::cout << "recursionDepth: " << recursionDepth << "\n";
	log(recursionDepth, "Step 4:\n", ref);
	int smallest = ref[table[mainChain[0].largeIndex][recursionDepth] - 1].first;
	std::size_t smallestIndex = ref[table[mainChain[0].largeIndex][recursionDepth] - 1].second;
	// std::size_t smallestIndex = mainChain[0].smallIndex;
	std::cout << "smallest: " << smallest << "\n";
	std::cout << "smallestIndex: " << smallestIndex << "\n";
	mainChain.insert(mainChain.begin(), {smallest, 0, smallestIndex, 0});

	log(recursionDepth, "Step 4:\n", mainChain);

	// step 5: binary search insert remaining smaller elements into mainChain
	auto comp = [](const pair& left, const pair& right) {
		return left.large < right.large;
	};

	std::cout << "mainChain.rbegin()->large: " << mainChain.rbegin()->large << "\n";

	std::vector<PmergeMe::pair> mainChainCpy(mainChain.begin(), mainChain.end());
	for (std::size_t i = 2; i < mainChainCpy.size(); ++i) {
		int numToBeInserted = ref[table[mainChainCpy[i].largeIndex][recursionDepth] - 1].first;
		std::size_t numToBeInsertedIndex = ref[table[mainChainCpy[i].largeIndex][recursionDepth] - 1].second;
		std::cout << "numToBeInserted: " << numToBeInserted << "\n";
		std::cout << "numToBeInsertedIndex: " << numToBeInsertedIndex << "\n";
		PmergeMe::pair pending = {numToBeInserted, 0, numToBeInsertedIndex, 0};
		auto insertBefore = std::lower_bound(mainChain.begin(), mainChain.end(), pending, comp); // replace mainChain.end() with paired large
		if (insertBefore != mainChain.end())
			mainChain.insert(insertBefore, pending);
		else
			mainChain.insert(mainChain.end(), pending);
	}

	if (odd.large != -1) {
		log(recursionDepth, "odd number insertion here");
		auto it = std::lower_bound(mainChain.begin(), mainChain.end(), odd, comp);
		if (it != mainChain.end())
			mainChain.insert(it, odd);
		else
			mainChain.insert(mainChain.end(), odd);
	}
	// TODO: implement order of insertion according to the book

	log(recursionDepth, "Step 5:\n", mainChain);

	return mainChain;
}


std::ostream& operator<<(std::ostream& stream, const std::vector<PmergeMe::pair>& vec)
{
	stream << "(small, large):           ";
	for (const auto& v : vec)
		stream << "(" << v.small << " " << v.large << ")";
	stream << "\n";
	stream << "(smallIndex, largeIndex): ";
	for (const auto& v : vec)
		stream << "(" << v.smallIndex << " " << v.largeIndex << ")";
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const std::vector<std::vector<int>>& table)
{
	stream << "== table ==\n";
	for (auto& row : table) {
		for (auto col : row)
			stream << col << " ";
		stream << "\n";
	}
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const std::vector<std::pair<int, std::size_t>>& ref)
{
	stream << "== ref ==\n";
	for (auto& pair : ref)
		stream << pair.first << " ";
	stream << "\n";
	for (auto& pair : ref)
		stream << pair.second << " ";
	return stream;
}

// std::vector<int> PmergeMe::mergeInsertionSort(const std::vector<int>& vec)
// {
// 	if (vec.size() <= 1)
// 		return vec;

// 	// step 1 & 2: pair and sort within each pair
// 	auto pairs = pairAndSort(vec);
// 	// printPairs(pairs);

// 	// step 3: recursively sort larger elements
// 	std::vector<int> largerElements;
// 	for (const auto& p : pairs)
// 		largerElements.push_back(p.first);
// 	std::vector<int> sortedSequence = mergeInsertionSort(largerElements);
// 	// std::cout << "\033[0;31m";
// 	// printVector(sortedSequence);
// 	// std::cout << "\033[0m" << std::endl;

// 	// step 4: insert the smallest element and larger elements into sortedSequence
// 	// std::vector<int> sortedSequence;
// 	int smallest;
// 	// for (const auto& p : pairs)
// 	for (auto it = pairs.begin(); it != pairs.end(); ++it)
// 	{
// 		// if (p.first == sortedSequence[0])
// 		// 	smallest = p.second;
// 		if (it->first == sortedSequence[0])
// 		{
// 			smallest = it->second;
// 			pairs.erase(it);
// 			break ;
// 		}
// 	}
// 	sortedSequence.insert(sortedSequence.begin(), smallest);

// 	// std::cout << "\033[0;33m";
// 	// printVector(sortedSequence);
// 	// std::cout << "\033[0m" << std::endl;

// 	// step 5: binary search insert remaining smaller elements into sortedSequence
// 	for (size_t i = 0; i < pairs.size(); ++i)
// 	{
// 		auto it = std::lower_bound(sortedSequence.begin(), sortedSequence.end(), pairs[i].second);
// 		sortedSequence.insert(it, pairs[i].second);
// 	}
// 		// binaryInsert(sortedSequence, pairs[i].second); // order of the pairs not according to the book

// 	// std::cout << "\033[0;32m";
// 	// printVector(sortedSequence);
// 	// std::cout << "\033[0m" << std::endl;

// 	return sortedSequence;
// }

// void PmergeMe::mergeInsertionSort(std::deque<int>& deq)
// {
// 	(void)deq;
	// auto pairs = pairAndSort(deq);
	// printPairs(pairs);
// }
