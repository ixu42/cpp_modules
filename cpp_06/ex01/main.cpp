/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:54:20 by ixu               #+#    #+#             */
/*   Updated: 2024/08/26 11:55:03 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data random = Data();
	Data* original = &random;

	uintptr_t raw = Serializer::serialize(original);
	Data* deserializedPtr = Serializer::deserialize(raw);

	if (deserializedPtr == original)
		std::cout << "return value of deserialize() is equal to the original pointer" << std::endl;
	else
		std::cout << "return value of deserialize() is NOT equal to the original pointer" << std::endl;
}
