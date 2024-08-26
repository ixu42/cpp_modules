/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:45:06 by ixu               #+#    #+#             */
/*   Updated: 2024/08/26 11:43:03 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class Data
{
	public:
		Data();
		Data(const Data&);
		Data& operator=(const Data&);
		~Data();

		std::string getName();
		int			getId();

	private:
		std::string	_name;
		int			_id;
};

std::ostream& operator<<(std::ostream& stream, Data& data);

#endif