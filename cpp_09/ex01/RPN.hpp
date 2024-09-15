/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:05:59 by ixu               #+#    #+#             */
/*   Updated: 2024/09/15 17:56:43 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <string>
#include <stdexcept>
#include <cctype>
#include <iostream>
#include <limits>

class RPN
{
	public:
		static void run(const std::string&);

	private:
		RPN() = default;
		RPN(const RPN&) = default;
		RPN& operator=(const RPN&) = default;
		~RPN() = default;

		static void processChar(char c, int& numbers, int& operators, bool& whitespMode);
		static double calculate(char token);

		static std::stack<double> _stack;
};
