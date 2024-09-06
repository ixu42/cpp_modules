/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:05:59 by ixu               #+#    #+#             */
/*   Updated: 2024/09/06 15:21:39 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <string>
#include <stdexcept>
#include <cctype>
#include <iostream>

class RPN
{
	public:
		static void run(const std::string&);

	private:
		RPN();
		RPN(const RPN&);
		RPN& operator=(const RPN&);
		~RPN();

		static int calculate(char token);

		static std::stack<int> _stack;
};
