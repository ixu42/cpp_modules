/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:22:32 by ixu               #+#    #+#             */
/*   Updated: 2024/08/28 22:02:49 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string stringArray[] = {"one", "two", "three", "four", "five"};

	size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);
	size_t doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);
	size_t stringArrayLength = sizeof(stringArray) / sizeof(stringArray[0]);

	iter(intArray, intArrayLength, printArray<int>);
	iter(doubleArray, doubleArrayLength, printArray<double>);
	iter(stringArray, stringArrayLength, printArray<std::string>);
}
