/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:19:14 by ixu               #+#    #+#             */
/*   Updated: 2024/08/26 01:48:27 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <cctype> // std::isalpha
# include <limits> // std::numeric_limits<char>::min, std::numeric_limits<char>::max
# include <ios> // std::fixed
# include <iomanip> // std::setprecision

enum class Type {Char, Int,	Float, SpecialFloat, Double, SpecialDouble, Empty, Unknown};

enum OverflowFlags
{
	CharOverflow = 1,
	IntOverflow = 2,
	FloatOverflow = 4,
	DoubleOverflow = 8
};

class ScalarConverter
{
	public:
		static void	convert(const std::string& param);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		static		Type getType(const std::string& param, int& overflowFlags);
		static bool	charOverflowed(int c);
		static bool	isInteger(const std::string& param, int& overflowFlags);
		static bool	isFloat(const std::string& param, int& overflowFlags);
		static bool	isDouble(const std::string& param, int& overflowFlags);
		static bool	isSpecialFloat(const std::string& param);
		static bool	isSpecialDouble(const std::string& param);
		static void	cast(Type type, const std::string& param, char& c, int& i, float& f, double& d);
		static bool	hasFlag(int flags, OverflowFlags flag);
		static void	displayValues(Type type, int flags, char c, int i, float f, double d);
};

#endif