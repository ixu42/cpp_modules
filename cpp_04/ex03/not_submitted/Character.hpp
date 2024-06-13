/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:33:36 by ixu               #+#    #+#             */
/*   Updated: 2024/06/13 10:22:55 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string			_name;
		AMateria*			_inventory[4];
	public:
		Character();
		Character(const std::string& name);
		Character(const Character& other);
		~Character() override;
		Character&			operator=(const Character& other);
		std::string const &	getName() const override;
		void				equip(AMateria* m) override;
		void				unequip(int idx) override;
		void				use(int idx, ICharacter& target) override;
		AMateria*			getInventory(int idx);
};

#endif
