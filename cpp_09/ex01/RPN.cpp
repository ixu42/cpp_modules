/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:05:57 by ixu               #+#    #+#             */
/*   Updated: 2024/09/08 12:28:17 by ixu              ###   ########.fr       */
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

int RPN::add(int left, int right)
{
	int maxInt = std::numeric_limits<int>::max();
	int minInt = std::numeric_limits<int>::min();

	if (right > 0 && left > maxInt - right)
		throw std::runtime_error("Error: overflow occurred");
	if (right < 0 && left < minInt - right)
		throw std::runtime_error("Error: underflow occurred");
	return (left + right);
}

int RPN::subtract(int left, int right)
{
	int maxInt = std::numeric_limits<int>::max();
	int minInt = std::numeric_limits<int>::min();

	if (right > 0 && left < minInt + right)
		throw std::runtime_error("Error: underflow occurred");
	if (right < 0 && left > maxInt + right)
		throw std::runtime_error("Error: overflow occurred");
	return (left - right);
}

int RPN::multiply(int left, int right)
{
	int maxInt = std::numeric_limits<int>::max();
	int minInt = std::numeric_limits<int>::min();

	if (((left > 0 && right > 0) || (left < 0 && right < 0))
		&& left > maxInt / right)
		throw std::runtime_error("Error: overflow occurred");
	if (((left > 0 && right < 0) && right < minInt / left)
		|| ((left < 0 && right > 0) && left < minInt / right))	
		throw std::runtime_error("Error: underflow occurred");
	return (left * right);
}

int RPN::divide(int left, int right)
{
	int minInt = std::numeric_limits<int>::min();

	if (right == 0)
		throw std::runtime_error("Error: division by zero");
	if (left == minInt && right == -1)
		throw std::runtime_error("Error: overflow occurred");
	return (left / right);
}

int RPN::calculate(char token)
{
	int right = _stack.top();
	_stack.pop();
	int left = _stack.top();
	_stack.pop();

	/* uncommet the following line to display each calculation */
	// std::cout << left << " " << token  << " " << right << '\n';

	int res = 0;
	if (token == '+')
		res = add(left, right);
	else if (token == '-')
		res = subtract(left, right);
	else if (token == '*')
		res = multiply(left, right);
	else
		res = divide(left, right);
	return res;
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
	std::cout << _stack.top() << '\n';
}
