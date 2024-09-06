/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:05:57 by ixu               #+#    #+#             */
/*   Updated: 2024/09/06 23:16:17 by ixu              ###   ########.fr       */
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
	{
		if (left > std::numeric_limits<int>::max() - right)
			throw std::runtime_error("Error: overflow occurred");
		return (left + right);
	}
	if (token == '-')
	{
		if (left < std::numeric_limits<int>::min() + right)
			throw std::runtime_error("Error: underflow occurred");
		return (left - right);
	}
	if (token == '*')
	{
		if (right != 0 && left > std::numeric_limits<int>::max() / right)
			throw std::runtime_error("Error: overflow occurred");
		return (left * right);
	}
	if (right == 0)
		throw std::runtime_error("Error: division by zero");
	return (left / right);
}

void RPN::run(const std::string& input)
{
	if (input.empty())
		throw std::runtime_error("Error");
	int numbers = 0;
	int operators = 0;
	bool validCharhandled = false;
	for (char c : input)
	{
		if (std::isspace(c))
		{
			if (validCharhandled)
				validCharhandled = false;
			continue ;
		}
		if (isValid(c))
		{
			if (std::isdigit(c))
			{
				_stack.push(static_cast<int>(c) - 48);
				numbers++;
			}
			else
			{
				if (_stack.size() < 2)
					throw std::runtime_error("Error");
				int res = calculate(c);
				_stack.push(res);
				operators++;
			}
			validCharhandled = true;
		}
	}
	if (operators != numbers - 1 || operators == 0)
		throw std::runtime_error("Error");
	std::cout << _stack.top();
}
