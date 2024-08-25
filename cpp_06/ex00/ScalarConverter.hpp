/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:19:14 by ixu               #+#    #+#             */
/*   Updated: 2024/08/25 21:47:18 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <cctype>

enum class Type {Char, Int,	Float, Double, Empty, Unknown};

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
		static void cast(Type type, const std::string& param, char& c, int& i, float& f, double& d);
		static void displayValues(char c, int i, float f, double d);
};

#endif