/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:19:07 by ixu               #+#    #+#             */
/*   Updated: 2024/08/26 15:43:13 by ixu              ###   ########.fr       */
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

bool ScalarConverter::charOverflowed(int c)
{
	if (c < static_cast<int>(std::numeric_limits<char>::min())
		|| c > static_cast<int>(std::numeric_limits<char>::max()))
		return true;
	return false;
}

bool ScalarConverter::isInteger(const std::string& param, int& overflowFlags)
{
	try
	{
		std::size_t pos;
		int i = std::stoi(param, &pos);
		bool isInt = pos == param.size();
		if (isInt)
		{
			if (charOverflowed(i))
				overflowFlags |= CharOverflow;
			return true;
		}
		return false;
	}
	catch (const std::invalid_argument& e)
	{
		return false;
	}
	catch (const std::out_of_range& e)
	{
		overflowFlags |= (IntOverflow | CharOverflow);
		return false;
	}
	catch (const std::exception& e)
	{
		std::cout << "ScalarConverter::isInteger() error: " << e.what() << std::endl;
		return false;
	}
}

bool ScalarConverter::isFloat(const std::string& param, int& overflowFlags)
{
	try
	{
		std::size_t pos;
		std::stof(param, &pos);
		return param.back() == 'f' && pos + 1 == param.size();
	}
	catch (const std::invalid_argument& e)
	{
		return false;
	}
	catch (const std::out_of_range& e)
	{
		overflowFlags |= FloatOverflow;
		return false;
	}
	catch (const std::exception& e)
	{
		std::cout << "ScalarConverter::isFloat() error: " << e.what() << std::endl;
		return false;
	}
}

bool ScalarConverter::isDouble(const std::string& param, int& overflowFlags)
{
	try
	{
		std::size_t pos;
		std::stod(param, &pos);
		return pos == param.size();
	}
	catch (const std::invalid_argument& e)
	{
		return false;
	}
	catch (const std::out_of_range& e)
	{
		overflowFlags |= DoubleOverflow;
		return false;
	}
	catch (const std::exception& e)
	{
		std::cout << "ScalarConverter::isDouble() error: " << e.what() << std::endl;
		return false;
	}
}

bool ScalarConverter::isSpecialFloat(const std::string& param)
{
	if (param == "inff" || param == "+inff" || param == "-inff"
		|| param == "nanf" || param == "+nanf" || param == "-nanf")
		return true;
	return false;
}

bool ScalarConverter::isSpecialDouble(const std::string& param)
{
	if (param == "inf" || param == "+inf" || param == "-inf"
		|| param == "nan" || param == "+nan" || param == "-nan")
		return true;
	return false;
}

Type ScalarConverter::getType(const std::string& param, int& overflowFlags)
{
	if (param.empty())
		return Type::Empty;
	if (param.size() == 1 && std::isalpha(param[0]))
		return Type::Char;
	if (isInteger(param, overflowFlags))
		return Type::Int;
	if (isSpecialFloat(param))
		return Type::SpecialFloat;
	if (isFloat(param, overflowFlags))
		return Type::Float;
	if (isSpecialDouble(param))
		return Type::SpecialDouble;
	if (isDouble(param, overflowFlags))
		return Type::Double;
	return Type::Unknown;
}

void ScalarConverter::cast(Type type, const std::string& param, char& c, int& i, float& f, double& d)
{
	switch (type)
	{
		case Type::Char:
			c = param[0];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break ;
		case Type::Int:
			i = std::stoi(param);
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break ;
		case Type::Float:
			f = std::stof(param);
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
			break ;
		case Type::SpecialFloat:
			f = std::stof(param);
			d = static_cast<double>(f);
			break ;
		case Type::Double:
			d = std::stod(param);
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
			break ;
		case Type::SpecialDouble:
			d = std::stod(param);
			f = static_cast<float>(d);
			break ;
		default:
			std::cout << "ScalarConverter::cast() error: unknown type" << std::endl;
	}
}

bool ScalarConverter::hasFlag(int flags, OverflowFlags flag)
{
	return (flags & flag) != 0;
}

void ScalarConverter::displayValues(Type type, int flags, char c, int i, float f, double d)
{
	if (type == Type::SpecialFloat || type == Type::SpecialDouble || hasFlag(flags, CharOverflow))
		std::cout << "char: impossible" << std::endl;
	else if (c >= 32 && c <= 126)
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (type == Type::SpecialFloat || type == Type::SpecialDouble || hasFlag(flags, IntOverflow))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	if (hasFlag(flags, FloatOverflow))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	if (hasFlag(flags, DoubleOverflow))
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string& param)
{
	int overflowFlags = 0;
	Type type = getType(param, overflowFlags);
	if (type == Type::Empty)
	{
		std::cout << "Conversion impossible: empty string passed as parameter" << std::endl;
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
	try
	{
		cast(type, param, c, i, f, d);
	}
	catch (const std::exception& e)
	{
		std::cout << "ScalarConverter::cast() error: " << e.what() << std::endl;
		return ;
	}
	displayValues(type, overflowFlags, c, i, f, d);
}
