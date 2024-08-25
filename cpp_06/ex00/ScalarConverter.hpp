/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:19:14 by ixu               #+#    #+#             */
/*   Updated: 2024/08/26 00:00:30 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <cctype> // std::isalpha
# include <ios> // std::fixed
# include <iomanip> // std::setprecision

enum class Type {Char, Int,	Float, SpecialFloat, Double, SpecialDouble, Empty, Unknown};

class ScalarConverter
{
	public:
		static void convert(const std::string& param);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		static Type getType(const std::string& param);
		static bool isInteger(const std::string& param);
		static bool isFloat(const std::string& param);
		static bool isDouble(const std::string& param);
		static bool isSpecialFloat(const std::string& param);
		static bool isSpecialDouble(const std::string& param);
		static void cast(Type type, const std::string& param, char& c, int& i, float& f, double& d);
		static void displayValues(Type type, char c, int i, float f, double d);
};

#endif