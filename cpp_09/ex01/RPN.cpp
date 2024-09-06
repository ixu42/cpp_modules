/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:05:57 by ixu               #+#    #+#             */
/*   Updated: 2024/09/06 15:21:37 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<int> RPN::_stack;

RPN::RPN() {}

RPN::RPN(const RPN&) {}

RPN& RPN::operator=(const RPN&)
{
	return *this;
}

RPN::~RPN() {}

bool isValid(char c)
{
	if (std::isdigit(c) || c == '+' || c == '-'
		|| c == '*' || c == '/')
		return true;
	return false;
}

int RPN::calculate(char token)
{
	int right = _stack.top();
	_stack.pop();
	int left = _stack.top();
	_stack.pop();

	// std::cout << "left=" << left << ", right=" << right << std::endl;

	if (token == '+')
		return (left + right);
	if (token == '-')
		return (left - right);
	if (token == '*')
		return (left * right);
	if (right == 0)
		throw std::runtime_error("Error: division by zero");
	return (left / right);
}

void RPN::run(const std::string& input)
{
	if (input.empty())
		throw std::runtime_error("Error: empty string");
	bool skip_sp = false;
	for (char c : input)
	{
		bool isValidChar = isValid(c);
		if ((!skip_sp && !isValidChar) || (skip_sp && c != ' '))
			throw std::runtime_error("Error");
		if (skip_sp && c == ' ')
		{
			skip_sp = false;
			continue ;
		}
		if (!skip_sp && isValidChar)
		{
			if (std::isdigit(c))
				_stack.push(static_cast<int>(c) - 48);
			else
			{
				if (_stack.size() < 2)
					throw std::runtime_error("Error: less than two numbers in stack");
				int res = calculate(c); // overflow?
				_stack.push(res);
				// std::cout << "c: " << c << std::endl;
				// std::cout << "res: " << res << std::endl;
			}
			skip_sp = true;
		}
	}
	std::cout << _stack.top();
}
