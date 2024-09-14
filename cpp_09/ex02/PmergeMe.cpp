/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:29:08 by ixu               #+#    #+#             */
/*   Updated: 2024/09/14 16:57:39 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int PmergeMe::_recursionCounter = 1;

void PmergeMe::validateInput(int argc, char** argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string str = argv[i];
		int nbr;
		std::size_t pos;
		try
		{
			nbr = std::stoi(str, &pos);
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
		if (nbr <= 0)
			throw std::runtime_error("not a positive integer => " + str);
	}
}

std::vector<int> PmergeMe::loadInputToVec(int argc, char** argv)
{
	validateInput(argc, argv);

	std::vector<int> vec;
	for (int i = 1; i < argc; ++i)
	{
		int nbr = std::stoi(argv[i]);
		vec.push_back(nbr);
	}
	return vec;
}

std::deque<int> PmergeMe::loadInputToDeq(int argc, char** argv)
{
	validateInput(argc, argv);

	std::deque<int> deq;
	for (int i = 1; i < argc; ++i)
	{
		int nbr = std::stoi(argv[i]);
		deq.push_back(nbr);
	}
	return deq;
}

PmergeMe::PairVec PmergeMe::pairAndSort(const PairVec& vec)
{
	PairVec pairs;

	for (std::size_t i = 0; i + 1 < vec.size(); i += 2)
	{
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

	return pairs;
}

void PmergeMe::updateTable(Int2DVec& table, PairVec& pairs, int recursionDepth)
{
	for (std::size_t i = 0; i < pairs.size(); ++i)
	{
		if (recursionDepth == 1)
		{
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
		}
		else
			table[pairs[i].largeIndex].push_back(pairs[i].smallIndex);
	}
}

std::size_t PmergeMe::getPairedSmallIndex(const Pair& pair, \
	const Int2DVec& table, int recursionDepth)
{
	return static_cast<std::size_t>(table[pair.largeIndex][recursionDepth + 1]);
}

void PmergeMe::insertSmallestIntoMainChain(PairVec& mainChain, \
	const Int2DVec& table, int recursionDepth)
{
	std::size_t smallestIndex;
	int smallest;
	if (mainChain.size() == 1)
	{
		smallestIndex = mainChain[0].smallIndex;
		smallest = mainChain[0].small;
	}
	else 
	{
		smallestIndex = getPairedSmallIndex(mainChain[0], table, recursionDepth);
		smallest = table[smallestIndex][0];
	}
	log(0, "smallest: ", smallest);
	log(0, "smallestIndex: ", smallestIndex);
	mainChain.insert(mainChain.begin(), {smallest, 0, smallestIndex, 0});
}

PmergeMe::PairVec PmergeMe::extractPendingNbrs(const PairVec& mainChain, \
	const Pair& odd, const Int2DVec& table, int recursionDepth)
{
	PairVec pendingNbrs;
	for (auto it = std::next(mainChain.begin() + 1); it < mainChain.end(); ++it)
	{
		std::size_t nbrToBeInsertedIndex = getPairedSmallIndex(*it, table, recursionDepth);
		int nbrToBeInserted = table[nbrToBeInsertedIndex][0];
		log(0, "nbrToBeInserted: ", nbrToBeInserted);
		log(0, "nbrToBeInsertedIndex: ", nbrToBeInsertedIndex);
		pendingNbrs.push_back({nbrToBeInserted, 0, nbrToBeInsertedIndex, 0});
	}
	if (odd.large)
		pendingNbrs.push_back(odd);
	return pendingNbrs;
}

std::vector<int> PmergeMe::generateJacobsthalNbrs(int maxVal)
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

void PmergeMe::insert(PairVec& mainChain, const PairVec& pendingNbrs, int j, std::size_t& nbrsInserted)
{
	// compare pairs based on pair.large; used in std::lower_bound()
	auto comp = [](const Pair& left, const Pair& right)
	{
		return left.large < right.large;
	};

	PairVec::iterator binarySearchEnd;
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
}

/**
 * perform binary insertion with custom iteration 
 * using the Jacobsthal-based groups in reverse order within each group
 * 
 * j:         0 1 2 3 4 5 6 7 8 9 ...
 * baseIndex: 0 0 2 2 4 4 4 4 4 4 ...
 */

void PmergeMe::binaryInsertion(const PairVec& pendingNbrs, PairVec& mainChain)
{
	// generate Jacobsthal numbers that don't exceed the array size
	std::vector<int> jacobsthalNbrs = generateJacobsthalNbrs(pendingNbrs.size());

	int baseIndex = 0;
	std::size_t nbrsInserted = 0;

	if (pendingNbrs.size() > 1)
	{
		// iterate through the Jacobsthal numbers to form groups
		for (int i = 0; i < static_cast<int>(jacobsthalNbrs.size()); ++i)
		{
			int groupSize = (i == 0) ? 2 : jacobsthalNbrs[i] - jacobsthalNbrs[i - 1];

			if (baseIndex + groupSize > static_cast<int>(pendingNbrs.size())) 
				break;

			// iterate in reverse over this group
			for (int j = baseIndex + groupSize - 1; j >= baseIndex; --j)
				insert(mainChain, pendingNbrs, j, nbrsInserted);

			baseIndex += groupSize;

			if (baseIndex >= static_cast<int>(pendingNbrs.size()))
				break;
		}
	}
	for (int j = static_cast<int>(pendingNbrs.size()) - 1; j >= baseIndex; --j)
		insert(mainChain, pendingNbrs, j, nbrsInserted);
}

/**
 * roman nbrs: depth of recursion (1st func call, 2nd func call, and so forth)
 * arabic nbrs: steps as explained in the function body
 * 
 * example: unsorted sequence => 6 7 8 5 3 1 2 4
 * 
 * == table ==
 * 6 0
 * 7 1 0
 * 5 2
 * 8 3 2 1 7
 * 1 4
 * 3 5 4
 * 2 6
 * 4 7 6 5
 * 
 * column 0 => 8 nbrs sorted within each pair (I)
 * column 1 => index of each nbr (I)
 * column 2 => for each paired large, the index of corresponding small nbr (I)
 * column 3 => for each paired large, the index of corresponding small nbr (II)
 * column 4 => for each paired large, the index of corresponding small nbr (III)
 * 
 * each nbr below refers to large in struct PmergeMe::pair for simplicity
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

PmergeMe::PairVec PmergeMe::mergeInsertionSort(const PairVec& vec, Int2DVec& table)
{
	int recursionDepth = _recursionCounter++;

	if (vec.size() <= 1)
		return vec;

	// steps 1 && 2: pair and sort within each pair
	PairVec pairs = pairAndSort(vec);
	Pair odd = {0, 0, 0, 0};
	if (vec.size() % 2 != 0)
		odd = {vec.back().large, vec.back().small, vec.back().largeIndex, vec.back().smallIndex};
	updateTable(table, pairs, recursionDepth);
	log(recursionDepth, "Steps 1 && 2:\n", pairs, table);

	// step 3: recursively sort the pairs according to larger elements
	PairVec mainChain = mergeInsertionSort(pairs, table);
	log(recursionDepth, "Step 3:\n", mainChain);

	// step 4: insert the smallest element into mainChain
	insertSmallestIntoMainChain(mainChain, table, recursionDepth);
	log(recursionDepth, "Step 4:\n", mainChain);

	// step 5: binary search insert remaining smaller elements into mainChain
	PairVec pendingNbrs = extractPendingNbrs(mainChain, odd, table, recursionDepth);
	if (!pendingNbrs.empty())
		binaryInsertion(pendingNbrs, mainChain);
	log(recursionDepth, "Step 5:\n", mainChain);

	return mainChain;
}

std::vector<int> PmergeMe::sortVec(const std::vector<int>& vec)
{
	PairVec nbrs;
	for (std::size_t i = 0; i < vec.size(); ++i)
	{
		Pair nbr = {vec[i], 0, 0, 0};
		nbrs.push_back(nbr);
	}
	Int2DVec table;
	PairVec sortedPairs = PmergeMe::mergeInsertionSort(nbrs, table);
	std::vector<int> sortedVec;
	for (const auto& p : sortedPairs)
		sortedVec.push_back(p.large);
	return sortedVec;
}

std::ostream& operator<<(std::ostream& stream, const PmergeMe::PairVec& vec)
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

std::ostream& operator<<(std::ostream& stream, const PmergeMe::Int2DVec& table)
{
	stream << "\n== table ==\n";
	for (auto& row : table) {
		for (auto col : row)
			stream << col << " ";
		stream << "\n";
	}
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const std::vector<int>& vec)
{
	for (int nbr : vec)
		std::cout << nbr << " ";
	std::cout << "\n";
	return stream;
}
