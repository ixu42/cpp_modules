/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:02:07 by ixu               #+#    #+#             */
/*   Updated: 2024/05/28 17:19:17 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	public:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;
	private:
		enum field
		{
			FirstName, LastName, NickName, PhoneNumber, DarkestSecret
		};
	public:
		Contact();
		void		displayContactInfo();
		void		promptField(int field);
		void		fillField(int field, std::string &data);
};

#endif
