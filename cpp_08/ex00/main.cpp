/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:01:09 by ixu               #+#    #+#             */
/*   Updated: 2024/09/02 12:11:40 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <exception>

static void printString(const std::string& message)
{
	std::cout << "\033[0;36m" << "[ " << message << " ]" << "\033[0m" << std::endl;
}

int main()
{
	try
	{
		printString("std::vector");
		std::vector<int> vec = {1, 2, 3, 4, 5};
		auto vecIterator = easyfind(vec, 1);
		std::cout << "Value found: " << *vecIterator << std::endl;

		printString("std::list");
		std::list<int> lst = {1, 2, 3, 4, 5};
		auto lstIterator = easyfind(lst, 2);
		std::cout << "Value found: " << *lstIterator << std::endl;

		printString("std::array");
		std::array<int, 5> arr = {1, 2, 3, 4, 5};
		auto arrIterator = easyfind(arr, 3);
		std::cout << "Value found: " << *arrIterator << std::endl;

		printString("std::deque");
		std::deque<int> deq = {1, 2, 3, 4, 5};
		auto deqIterator = easyfind(deq, 4);
		std::cout << "Value found: " << *deqIterator << std::endl;

		printString("std::forward_list");
		std::forward_list<int> fwd_lst = {1, 2, 3, 4, 5};
		auto fwdLstIterator = easyfind(fwd_lst, 5);
		std::cout << "Value found: " << *fwdLstIterator << std::endl;
	
		printString("value not in the container");
		vecIterator = easyfind(vec, 6);
		std::cout << "Value found: " << *vecIterator << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}
