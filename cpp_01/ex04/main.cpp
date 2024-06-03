/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:47:42 by ixu               #+#    #+#             */
/*   Updated: 2024/06/03 15:48:09 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FileReplacer.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Invalid number of arguments\n";
		std::cout << "Usage: " << argv[0] << " <filename> <string_to_replace> <replacement_string>\n";
		return (1);
	}	
	else
	{
		std::string		filename = argv[1];
		std::string		s1 = argv[2];
		std::string		s2 = argv[3];
		FileReplacer	replacer(filename, s1, s2);
		if (replacer.replace())
			return (1);
	}
	return (0);
}
