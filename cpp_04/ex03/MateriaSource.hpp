/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:48:02 by ixu               #+#    #+#             */
/*   Updated: 2024/06/12 11:10:57 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*		_inventory[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		~MateriaSource() override;
		MateriaSource&	operator=(const MateriaSource& other);
		void			learnMateria(AMateria*) override;
		AMateria*		createMateria(std::string const & type) override;
};

#endif
