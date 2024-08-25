/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:19:07 by ixu               #+#    #+#             */
/*   Updated: 2024/08/25 22:32:53 by ixu              ###   ########.fr       */
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

bool ScalarConverter::isInteger(const std::string& param)
{
	try
	{
		std::size_t pos;
		std::stoi(param, &pos);
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

bool ScalarConverter::isFloat(const std::string& param)
{
	try
	{
		std::size_t pos;
		std::stof(param, &pos);
		return param.back() == 'f' && pos + 1 == param.size();
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

bool ScalarConverter::isDouble(const std::string& param)
{
	try
	{
		std::size_t pos;
		std::stod(param, &pos);
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

Type ScalarConverter::getType(const std::string& param)
{
	if (param.empty())
		return Type::Empty;
	if (param.size() == 1 && std::isalpha(param[0]))
		return Type::Char;
	if (isInteger(param))
		return Type::Int;
	if (isFloat(param))
		return Type::Float;
	if (isDouble(param))
		return Type::Double;
	return Type::Unknown;
}

void ScalarConverter::cast(Type type, const std::string& param, char& c, int& i, float& f, double& d)
{
	switch (type)
	{
		case Type::Char:
			std::cout << "case char\n"; // remove later
			c = param[0];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break ;
		case Type::Int:
			std::cout << "case int\n"; // remove later
			i = std::stoi(param); // protect?
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break ;
		case Type::Float:
			std::cout << "case float\n"; // remove later
			f = std::stof(param);
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
			break ;
		case Type::Double:
			std::cout << "case double\n"; // remove later
			d = std::stod(param);
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
			break ;
		default:
			std::cout << "ScalarConverter::cast() error: unknown type" << std::endl;
	}
}

void ScalarConverter::displayValues(char c, int i, float f, double d)
{
	if (c >= 32 && c <= 126)
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string& param)
{
	Type type = getType(param);
	if (type == Type::Empty)
	{
		std::cout << "empty string passed as parameter" << std::endl;
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
	char c = 0;
	int i = 0;
	float f = 0;
	double d = 0;
	cast(type, param, c, i, f, d);
	displayValues(c, i, f, d);
}
