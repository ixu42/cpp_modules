/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:55:26 by ixu               #+#    #+#             */
/*   Updated: 2024/09/03 12:10:31 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

static void printString(const std::string& message)
{
	std::cout << "\033[0;36m" << "[ " << message << " ]" << "\033[0m" << std::endl;
}

static void testsOnMutantStack()
{
	MutantStack<int> mstack;
	std::cout << "empty: " << mstack.empty() << std::endl;
	mstack.push(5);
	std::cout << "empty: " << mstack.empty() << std::endl;
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(42);
	mstack.pop();
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

static void testsOnListForComparison()
{
	std::list<int> lst;
	std::cout << "empty: " << lst.empty() << std::endl;
	lst.push_back(5);
	std::cout << "empty: " << lst.empty() << std::endl;
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(42);
	lst.pop_back();
	lst.push_back(0);
	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(lst);
}

int main()
{
	printString("MutantStack");
	testsOnMutantStack();

	printString("std::list");
	testsOnListForComparison();

	printString("Additional tests");
	// use std::vector as the underlying container
	using iterableStack = MutantStack<int, std::vector<int>>;
	std::vector<int> vec({6, 7, 8, 9, 10});
	iterableStack mstack(vec);
	iterableStack::reverse_iterator it_reversed = mstack.rbegin();
	iterableStack::reverse_iterator ite_reversed = mstack.rend();
	while (it_reversed != ite_reversed)
	{
		std::cout << *it_reversed << std::endl;
		++it_reversed;
	}
	while (!mstack.empty()) {
		std::cout << mstack.top() << " ";
		mstack.pop();
	}
	std::cout << std::endl;
}
