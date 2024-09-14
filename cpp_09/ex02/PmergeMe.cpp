/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:29:08 by ixu               #+#    #+#             */
/*   Updated: 2024/09/14 12:29:48 by ixu              ###   ########.fr       */
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
		int nbrber;
		std::size_t pos;
		try
		{
			nbrber = std::stoi(str, &pos);
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
		if (nbrber <= 0)
			throw std::runtime_error("not a positive integer => " + str);
	}
}

std::vector<int> PmergeMe::loadInputToVec(int argc, char** argv)
{
	validateInput(argc, argv);

	std::vector<int> vec;
	for (int i = 1; i < argc; ++i)
	{
		int nbrber = std::stoi(argv[i]);
		vec.push_back(nbrber);
	}
	return vec;
}

std::deque<int> PmergeMe::loadInputToDeq(int argc, char** argv)
{
	validateInput(argc, argv);

	std::deque<int> deq;
	for (int i = 1; i < argc; ++i)
	{
		int nbrber = std::stoi(argv[i]);
		deq.push_back(nbrber);
	}
	return deq;
}

void PmergeMe::printVector(std::vector<int>& vec)
{
	for (int nbrber : vec)
		std::cout << nbrber << ' ';

	std::cout << '\n';
}

void PmergeMe::printDeque(std::deque<int>& deq)
{
	for (int nbrber : deq)
		std::cout << nbrber << ' ';

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

std::vector<int> PmergeMe::generateJacobsthalNumbers(int maxVal)
{
	if (maxVal == 1)
		return {3};

	std::vector<int> jacobsthal = {3, 5}; // start with J(0)=3 and J(1)=5

	// generate Jacobsthal numbers until exceeding maxVal
	while (true)
	{
		int next = jacobsthal.back() + 2 * jacobsthal[jacobsthal.size() - 2]; // J(n)=J(n-1)+2*J(n-2)
		if (next > maxVal)
			break; // stop when the next Jacobsthal number exceeds maxVal
		jacobsthal.push_back(next);
	}

	return jacobsthal;
}

// perform binary insertion with custom iteration using the Jacobsthal-based groups in reverse order within each group
void PmergeMe::binaryInsertion(const std::vector<PmergeMe::pair>& pendingNbrs, std::vector<PmergeMe::pair>& mainChain)
{
	// generate Jacobsthal numbers that don't exceed the array size
	std::vector<int> jacobsthalNumbers = generateJacobsthalNumbers(pendingNbrs.size());
	// for (auto i : jacobsthalNumbers)
	// 	std::cout << i << " ";
	// std::cout << "\n";
 
	// j:         0 1 2 3 4 5 6 7 8 9 ...
	// baseIndex: 0 0 2 2 4 4 4 4 4 4 ...
	int baseIndex = 0;
	std::size_t nbrsInserted = 0;

	// compare pairs based on pair.large, used in std::lower_bound()
	auto comp = [](const pair& left, const pair& right) {
		return left.large < right.large;
	};

	if (pendingNbrs.size() > 1)
	{
		// iterate through the Jacobsthal numbers to form groups
		for (int i = 0; i < static_cast<int>(jacobsthalNumbers.size()); ++i)
		{
			int groupSize;
			if (i == 0)
				groupSize = 2;
			else
				groupSize = jacobsthalNumbers[i] - jacobsthalNumbers[i - 1];

			// ensure we don't go out of bounds; stop when array is processed
			if (baseIndex + groupSize > static_cast<int>(pendingNbrs.size())) 
				continue;

			// std::cout << "Processing group of size " << groupSize << ": ";
			
			// iterate in reverse over this group
			for (int j = baseIndex + groupSize - 1; j >= baseIndex; --j) {
				std::vector<PmergeMe::pair>::iterator binarySearchEnd;
				if (pendingNbrs[j].small != 0) // if the pending nbr is odd pair
					binarySearchEnd = mainChain.end();
				else
				{
					binarySearchEnd = mainChain.begin();
					std::advance(binarySearchEnd, j + 2 + nbrsInserted);
				}
				auto insertBefore = std::lower_bound(mainChain.begin(), binarySearchEnd, pendingNbrs[j], comp);
				if (insertBefore != mainChain.end())
					mainChain.insert(insertBefore, pendingNbrs[j]);
				else
					mainChain.insert(mainChain.end(), pendingNbrs[j]);
				nbrsInserted++;
				// std::cout << "j: " << j << "\n";
				// std::cout << "current index: " << baseIndex << "\n";
				// std::cout << "nbrsInserted: " << nbrsInserted << "\n";
				// std::cout << "inserted 1:" << pendingNbrs[j].large << " ";
			}
			// std::cout << "\n";
			
			// move current index forward by group size
			baseIndex += groupSize;

			// stop if the whole array is processed
			if (baseIndex >= static_cast<int>(pendingNbrs.size()))
				break;
		}
	}
	for (int j = static_cast<int>(pendingNbrs.size()) - 1; j >= baseIndex; --j) {
		std::vector<PmergeMe::pair>::iterator binarySearchEnd;
		if (pendingNbrs[j].small != 0) // if the pending nbr is odd pair
			binarySearchEnd = mainChain.end();
		else
		{
			binarySearchEnd = mainChain.begin();
			std::advance(binarySearchEnd, j + 2 + nbrsInserted);
		}
		auto insertBefore = std::lower_bound(mainChain.begin(), binarySearchEnd, pendingNbrs[j], comp);
		if (insertBefore != mainChain.end())
			mainChain.insert(insertBefore, pendingNbrs[j]);
		else
			mainChain.insert(mainChain.end(), pendingNbrs[j]);
		nbrsInserted++;
		// std::cout << "inserted 2:" << pendingNbrs[j].large << " ";
	}
	// std::cout << "\n";
}

/**
 * roman nbrbers: depth of recursion (1st func call, 2nd func call, and so forth)
 * arabic nbrbers: steps as explained in the function body
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

std::vector<PmergeMe::pair> PmergeMe::mergeInsertionSort(\
	const std::vector<PmergeMe::pair>& vec, std::vector<std::vector<int>>& table)
{
	int recursionDepth = _recursionCounter++;

	if (vec.size() <= 1)
		return vec;

	// steps 1 && 2: pair and sort within each pair
	std::vector<PmergeMe::pair> pairs;

	for (std::size_t i = 0; i + 1 < vec.size(); i += 2)	{
		int first = vec[i].large;
		std::size_t firstIndex = vec[i].largeIndex;
		int second;
		std::size_t secondIndex;
		second = vec[i + 1].large;
		secondIndex = vec[i + 1].largeIndex;

		if (first > second)
			pairs.push_back({first, second, firstIndex, secondIndex});
		else
			pairs.push_back({second, first, secondIndex, firstIndex});
	}
	PmergeMe::pair odd = {0, 0, 0, 0};
	if (vec.size() % 2 != 0)
		odd = {vec.back().large, vec.back().small, vec.back().largeIndex, vec.back().smallIndex};

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
			row2.push_back(pairs[i].smallIndex);
			table.push_back(row2);
			_size += 2;
		}
		else
			table[pairs[i].largeIndex].push_back(pairs[i].smallIndex);
	}
	log(recursionDepth, "Steps 1 && 2:\n", pairs);
	log(recursionDepth, "Step 1 && 2:\n", table);

	// step 3: recursively sort the pairs according to larger elements
	std::vector<PmergeMe::pair> mainChain = mergeInsertionSort(pairs, table);
	log(recursionDepth, "Step 3:\n", mainChain);

	// step 4: insert the smallest element into mainChain
	std::size_t smallestIndex;
	int smallest;
	if (mainChain.size() == 1) {
		smallestIndex = mainChain[0].smallIndex;
		smallest = mainChain[0].small;
	}
	else {
		smallestIndex = static_cast<std::size_t>(table[mainChain[0].largeIndex][recursionDepth + 1]);
		smallest = table[smallestIndex][0];
	}
	std::cout << "smallest: " << smallest << "\n";
	std::cout << "smallestIndex: " << smallestIndex << "\n";
	mainChain.insert(mainChain.begin(), {smallest, 0, smallestIndex, 0});

	log(recursionDepth, "Step 4:\n", mainChain);

	// step 5: binary search insert remaining smaller elements into mainChain
	std::vector<PmergeMe::pair> pendingNbrs;
	for (auto it = std::next(mainChain.begin() + 1); it < mainChain.end(); ++it)
	{
		std::size_t nbrToBeInsertedIndex = static_cast<std::size_t>(table[it->largeIndex][recursionDepth + 1]);
		int nbrToBeInserted = table[nbrToBeInsertedIndex][0];
		std::cout << "nbrToBeInserted: " << nbrToBeInserted << "\n";
		std::cout << "nbrToBeInsertedIndex: " << nbrToBeInsertedIndex << "\n";
		pendingNbrs.push_back({nbrToBeInserted, 0, nbrToBeInsertedIndex, 0});
	}
	if (odd.large)
		pendingNbrs.push_back(odd);

	if (!pendingNbrs.empty())
		binaryInsertion(pendingNbrs, mainChain);

	log(recursionDepth, "Step 5:\n", mainChain);

	return mainChain;
}

std::vector<int> PmergeMe::sortVec(const std::vector<int>& vec)
{
	std::vector<PmergeMe::pair> nbrbers;
	for (std::size_t i = 0; i < vec.size(); ++i) {
		PmergeMe::pair nbrber = {vec[i], 0, i, 0};
		nbrbers.push_back(nbrber);
	}
	std::vector<std::vector<int>> table;
	std::vector<PmergeMe::pair> sortedPairs = PmergeMe::mergeInsertionSort(nbrbers, table);
	std::vector <int> sortedVec;
	for (const auto& p : sortedPairs)
		sortedVec.push_back(p.large);
	return sortedVec;
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
