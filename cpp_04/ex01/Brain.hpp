/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:55:06 by ixu               #+#    #+#             */
/*   Updated: 2024/06/10 17:04:41 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain();
		Brain(const Brain& other);
		~Brain();
		Brain&	operator=(const Brain& other);
};

#endif
