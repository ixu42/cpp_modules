/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:49:30 by ixu               #+#    #+#             */
/*   Updated: 2024/06/11 13:18:49 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain*	brain;
	public:
		Cat();
		Cat(const Cat& other);
		~Cat() override;
		Cat&	operator=(const Cat& other);
		void	makeSound() const override;
		Brain*	getBrain();
};

#endif
