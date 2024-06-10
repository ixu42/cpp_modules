/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:49:37 by ixu               #+#    #+#             */
/*   Updated: 2024/06/10 15:28:49 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain*	brain;
	public:
		Dog();
		Dog(const Dog& other);
		~Dog() override;
		Dog&	operator=(const Dog& other);
		void	makeSound() const override;
};

#endif
