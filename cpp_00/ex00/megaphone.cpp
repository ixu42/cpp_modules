/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:24:29 by ixu               #+#    #+#             */
/*   Updated: 2024/05/30 20:14:59 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

static std::string	str_upper(char *arg)
{
	std::string	arg_cpy(arg);
	for (char &c : arg_cpy)
		c = std::toupper(static_cast<unsigned char>(c));
	return (arg_cpy);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string arg_cpy = str_upper(argv[i]);
			std::cout << arg_cpy;
		}
		std::cout << std::endl;
	}
	return (0);
}
