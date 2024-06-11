/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:39:19 by ixu               #+#    #+#             */
/*   Updated: 2024/06/10 11:55:15 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
	protected:
		std::string		type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		~WrongAnimal();
		WrongAnimal&	operator=(const WrongAnimal& other);
		std::string		getType() const;
		void			makeSound() const;
};

#endif
