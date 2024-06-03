/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:06:26 by ixu               #+#    #+#             */
/*   Updated: 2024/06/03 15:46:57 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACER_HPP
# define FILEREPLACER_HPP

# include <string>

class FileReplacer
{
	private:
		std::string	filename;
		std::string	s1;
		std::string	s2;
	public:
		FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2);
		int			replace();
	private:
		std::string	readFile();
		int			writeFile(const std::string& content);
};

#endif
