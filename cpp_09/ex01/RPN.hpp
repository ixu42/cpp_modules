/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:05:59 by ixu               #+#    #+#             */
/*   Updated: 2024/09/07 11:12:52 by ixu              ###   ########.fr       */
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
		RPN();
		RPN(const RPN&);
		RPN& operator=(const RPN&);
		~RPN();

		static void processChar(char c, int& numbers, int& operators, bool& whitespMode);
		static int calculate(char token);

		static std::stack<int> _stack;
};
