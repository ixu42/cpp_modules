/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:05:57 by ixu               #+#    #+#             */
/*   Updated: 2024/09/07 11:34:20 by ixu              ###   ########.fr       */
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

// valid chars: "0123456789+-*/"

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

	/* uncommet the following line to display each calculation */
	// std::cout << left << token << right << std::endl;

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

void RPN::processChar(char c, int& numbers, int& operators, bool& whitespMode)
{
	if (std::isspace(c))
	{
		if (whitespMode)
			whitespMode = false;
		return ;
	}
	if (isValid(c))
	{
		if (whitespMode)
			throw std::runtime_error("Error: valid chars should be separated by whitespace(s)");
		if (std::isdigit(c))
		{
			_stack.push(static_cast<int>(c) - 48);
			numbers++;
		}
		else
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error: not sufficient numbers for the calculation");
			int res = calculate(c);
			_stack.push(res);
			operators++;
		}
		whitespMode = true;
	}
	else
		throw std::runtime_error("Error: unexpected char encountered");
}

void RPN::run(const std::string& input)
{
	if (input.empty())
		throw std::runtime_error("Error: empty string");

	int numbers = 0, operators = 0;
	// a flag to inform whether program is in a mode where only whitespaces are expected
	bool whitespaceMode = false;

	for (char c : input)
		processChar(c, numbers, operators, whitespaceMode);

	if (operators != numbers - 1)
		throw std::runtime_error("Error: number of operator should be number of digits minus one");
	if (numbers == 1)
		throw std::runtime_error("Error: only one number provided");
	std::cout << _stack.top() << std::endl;
}
