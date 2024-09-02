/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:01:14 by ixu               #+#    #+#             */
/*   Updated: 2024/09/02 12:11:51 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <stdexcept>
#include <string>

template<typename T>
typename T::iterator easyfind(T& container, int value)
{
	auto it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw std::runtime_error("value " + std::to_string(value) + " not found");

	return it;
}
