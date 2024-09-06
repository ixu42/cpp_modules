/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:05:59 by ixu               #+#    #+#             */
/*   Updated: 2024/09/06 12:42:53 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <string>
#include <stdexcept>

class RPN
{
	public:
		static void run(const std::string&);

	private:
		RPN();
		RPN(const RPN&);
		RPN& operator=(const RPN&);
		~RPN();

		static std::stack<int> _stack;
};
