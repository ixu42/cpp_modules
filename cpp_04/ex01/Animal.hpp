/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:44:51 by ixu               #+#    #+#             */
/*   Updated: 2024/06/10 11:54:50 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
	protected:
		std::string		type;
	public:
		Animal();
		Animal(const Animal& other);
		virtual ~Animal();
		Animal&			operator=(const Animal& other);
		std::string		getType() const;
		virtual void	makeSound() const;
};

#endif
