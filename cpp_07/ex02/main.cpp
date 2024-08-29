/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:19:37 by ixu               #+#    #+#             */
/*   Updated: 2024/08/29 16:18:45 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <string>
#include <iostream>
#include <exception>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

static void printString(std::string message)
{
	std::cout << "\n" << GREEN << "[ " << message << " ]" << RESET << std::endl;
}

static void printintArray(const Array<int>& intArray)
{
	if (intArray.size() == 0)
	{
		std::cout << "(null)" << std::endl;
		return ;
	}
	std::cout << "{ ";
		for (unsigned int i = 0; i < intArray.size(); ++i)
			std::cout << intArray[i] << " ";
	std::cout << "}" << std::endl;
}

static void printstrArray(const Array<std::string>& strArray)
{
	if (strArray.size() == 0)
	{
		std::cout << "(null)" << std::endl;
		return ;
	}
	std::cout << "{ ";
		for (unsigned int i = 0; i < strArray.size(); ++i)
			std::cout << strArray[i] << " ";
	std::cout << "}" << std::endl;
}

int main()
{
	printString("Test 1: default constructor");
	Array<int> arr1;
	std::cout << "Array 1 size: " << arr1.size() << std::endl;
	printintArray(arr1);

	printString("Test 2: constructor with size");
	Array<int> arr2(5);
	std::cout << "Array 2 size: " << arr2.size() << std::endl;
	printintArray(arr2);

	printString("Test 3: copy constructor");
	Array<int> arr3(arr2);
	std::cout << "Array 3 size: " << arr3.size() << std::endl;
	printintArray(arr3);

	printString("Test 4: copy assignment operator");
	arr1 = arr2;
	std::cout << "Array 1 size after copying: " << arr1.size() << std::endl;
	printintArray(arr1);

	printString("Test 5: subscript operator []");
	for (unsigned int i = 0; i < arr2.size(); ++i)
		arr2[i] = i + 1;
	printintArray(arr2);

	try
	{
		arr2[-1];
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	printString("Test 6: const array of integers");
	const Array<int> arr4(5);
	printintArray(arr4);
	/* uncomment the following line to test if modifying const obj is possible
	(should get a compile-time error) */
	// arr4[1] = 1;

	printString("Test 7: an array of strings");
	Array<std::string> arr5(2);
	std::cout << "Array 4 size: " << arr5.size() << std::endl;
	printstrArray(arr5);
	arr5[0] = "hello";
	arr5[1] = "world";
	printstrArray(arr5);
	
}
