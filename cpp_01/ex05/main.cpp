/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:20:17 by ixu               #+#    #+#             */
/*   Updated: 2024/06/03 17:15:35 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		std::cout << "Invalid number of arguments\n";
		return (1);
	}
	Harl	harl;
	harl.complain("DEBUG");
	harl.complain("WARNING");
	harl.complain("INFO");
	harl.complain("ERROR");
	harl.complain("UNKNOWN");
	return (0);
}
