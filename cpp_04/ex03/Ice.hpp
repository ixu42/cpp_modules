/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:13:40 by ixu               #+#    #+#             */
/*   Updated: 2024/06/12 10:54:16 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice&);
		~Ice() override;
		Ice&				operator=(const Ice&);
		std::string const&	getType() const;
		Ice*				clone() const override;
		void				use(ICharacter& target) override;
};

#endif
