/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:24:29 by ixu               #+#    #+#             */
/*   Updated: 2024/05/27 13:09:18 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	str_upper(char *arg)
{
	for (int i = 0; arg[i] != '\0'; i++)
	{
		if (arg[i] >= 'a' && arg[i] <= 'z')
			arg[i] -= 32;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			str_upper(argv[i]);
			std::cout << argv[i];
		}
		std::cout << std::endl;
	}
	return (0);
}
