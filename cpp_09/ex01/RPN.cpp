/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:05:57 by ixu               #+#    #+#             */
/*   Updated: 2024/09/15 17:56:38 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<double> RPN::_stack;

// valid chars: "0123456789+-*/"

bool isValid(char c)
{
	if (std::isdigit(c) || c == '+' || c == '-'
		|| c == '*' || c == '/')
		return true;
	return false;
}

double RPN::calculate(char token)
{
	double right = _stack.top();
	_stack.pop();
	double left = _stack.top();
	_stack.pop();

	/* uncommet the following line to display each calculation */
	// std::cout << left << " " << token  << " " << right << '\n';

	double res = 0;
	if (token == '+')
		res = left + right;
	else if (token == '-')
		res = left - right;
	else if (token == '*')
		res = left * right;
	else
	{
		if (right == 0)
			throw std::runtime_error("Error: division by zero");
		res = left / right;
	}
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
			_stack.push(static_cast<double>(static_cast<int>(c) - 48));
			numbers++;
		}
		else
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error: not sufficient numbers for the calculation");
			double res = calculate(c);
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
