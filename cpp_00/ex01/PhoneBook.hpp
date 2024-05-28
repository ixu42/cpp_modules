/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:00:33 by ixu               #+#    #+#             */
/*   Updated: 2024/05/28 16:03:02 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact				contacts[8];
		int					contactCount;
		int					oldestContactIndex;
	public:
		PhoneBook();
		void				addContact();
		void				displayContacts();
		int					getContact(int index);
		int					getContactCount();
	private:
		static std::string	formatStr(const std::string &str);
};

#endif
