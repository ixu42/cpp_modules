/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:25:37 by ixu               #+#    #+#             */
/*   Updated: 2024/06/05 21:05:16 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class Fixed
{
	private:
		int					fixedPointValue;
		static const int	fractionalBits = 8;

	public:
		/* CONSTRUCTORS AND DESTRUCTOR */
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		~Fixed();

		/* MEMBER FUNCS TO OVERLOAD OPERATORS */
		Fixed&				operator=(const Fixed& other);
		// Overloading comparison operators
		bool				operator>(const Fixed& other);
		bool				operator<(const Fixed& other);
		bool				operator>=(const Fixed& other);
		bool				operator<=(const Fixed& other);
		bool				operator==(const Fixed& other);
		bool				operator!=(const Fixed& other);
		// Overloading arithmetic operators
		Fixed				operator+(const Fixed& other) const;
		Fixed				operator-(const Fixed& other) const;
		Fixed				operator*(const Fixed& other) const;
		Fixed				operator/(const Fixed& other) const;
		// Overloading increment/decrement operators
		Fixed& 				operator++();
		Fixed				operator++(int);
		Fixed& 				operator--();
		Fixed				operator--(int);

		/* OVERLOADED MEMBER FUNCS ON MAX, MIN */
		static Fixed&		min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);

		/* OTHER MEMBER FUNCS */
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
};

std::ostream&	operator<<(std::ostream& stream, const Fixed& num);

#endif
