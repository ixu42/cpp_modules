/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:22:32 by ixu               #+#    #+#             */
/*   Updated: 2024/08/28 23:54:11 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>
#include <memory>

void printString(const std::string& message)
{
	std::cout << "\033[0;32m" << "[ " << message << " ]" << "\033[0m" << std::endl;
}

int main()
{
	printString("An array of chars");
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	size_t charArrayLength = sizeof(charArray) / sizeof(charArray[0]);
	iter(charArray, charArrayLength, printElem<char>);

	printString("An array of integers");
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);
	iter(intArray, intArrayLength, printElem<int>);
	
	printString("An array of floats");
	float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	size_t floatArrayLength = sizeof(floatArray) / sizeof(floatArray[0]);
	iter(floatArray, floatArrayLength, printElem<float>);
	
	printString("An array of doubles");
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);
	iter(doubleArray, doubleArrayLength, printElem<double>);
	
	printString("An array of strings");
	std::string stringArray[] = {"one", "two", "three", "four", "five"};
	size_t stringArrayLength = sizeof(stringArray) / sizeof(stringArray[0]);
	iter(stringArray, stringArrayLength, printElem<std::string>);

	printString("An array of int pointers");
	std::unique_ptr<int>intPtrArray[] = {
		std::make_unique<int>(1),
		std::make_unique<int>(2),
		std::make_unique<int>(3),
		std::make_unique<int>(4),
		std::make_unique<int>(5),
		nullptr
	};
	size_t intPtrArrayLength = sizeof(intPtrArray) / sizeof(intPtrArray[0]);
	iter(intPtrArray, intPtrArrayLength, printPtrValue<std::unique_ptr<int>>);

	printString("An array of string pointers");
	std::unique_ptr<std::string>strPtrArray[] = {
		std::make_unique<std::string>("hello"),
		std::make_unique<std::string>("world"),
		nullptr
	};
	size_t strPtrArrayLength = sizeof(strPtrArray) / sizeof(strPtrArray[0]);
	iter(strPtrArray, strPtrArrayLength, printPtrValue<std::unique_ptr<std::string>>);
}
