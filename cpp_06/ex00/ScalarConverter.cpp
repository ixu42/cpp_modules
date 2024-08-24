/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:19:07 by ixu               #+#    #+#             */
/*   Updated: 2024/08/24 15:45:56 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& param)
{
	Type type = getType(param);
	if (type == Type::Empty)
	{
		std::cout << "empty string passed as parameter";
		return ;
	}
	if (type == Type::Unknown)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	if (type == Type::Char)
		std::cout << "is char\n";
	if (type == Type::Int)
		std::cout << "is int\n";
	
}

Type ScalarConverter::getType(const std::string& param)
{
	if (param.empty())
		return Type::Empty;
	if (param.size() == 1 && std::isalpha(param[0]))
		return Type::Char;
	if (isInteger(param))
		return Type::Int;
	return Type::Unknown;
}

bool ScalarConverter::isInteger(const std::string& param)
{
	try
	{
		std::size_t pos;
		std::stoi(param, &pos);
		// std::cout << "pos:          " << pos << std::endl;
		// std::cout << "param.size(): " << param.size() << std::endl;
		return pos == param.size();
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "std::invalid_argument\n"; // remove later
		return false;
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "std::out_of_range\n"; // remove later
		return false;
	}
	catch (const std::exception& e)
	{
		std::cerr << "std::exception\n"; // remove later
		return false;
	}
}
