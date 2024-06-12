/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:13:36 by ixu               #+#    #+#             */
/*   Updated: 2024/06/12 10:54:23 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure&);
		~Cure() override;
		Cure&				operator=(const Cure&);
		std::string const&	getType() const;
		Cure*				clone() const override;
		void				use(ICharacter& target) override;
};

#endif
