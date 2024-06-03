/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:06:29 by ixu               #+#    #+#             */
/*   Updated: 2024/06/03 14:56:03 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstddef>

FileReplacer::FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2)
	: filename(filename), s1(s1), s2(s2) {}

std::string	FileReplacer::readFile()
{
	std::ifstream	inFile(filename);
	if (!inFile)
	{
		std::cout << "Unable to open the file " << filename << std::endl;
		return ("");
	}
	std::stringstream	buffer;
	buffer << inFile.rdbuf();
	return (buffer.str());
}

void	FileReplacer::writeFile(const std::string& content)
{
	std::ofstream	outFile(filename + ".replace");
	if (!outFile)
	{
		std::cout << "Unable to create the file " << filename + ".replace" << std::endl;
		return ;
	}
	outFile << content;
}

void	FileReplacer::replace()
{
	std::string	content = readFile();
	if (content.empty())
	{
		std::cout << "Failed to read the file or file is empty" << std::endl;
		return ;
	}
	std::string	newContent;
	size_t		pos = 0;
	while (true)
	{
		size_t	foundPos = content.find(s1, pos);
		if (foundPos == std::string::npos)
			break ;
		newContent.append(content, pos, foundPos - pos);
		newContent += s2;
		pos = foundPos + s1.length();
	}
	newContent.append(content, pos, std::string::npos);
	writeFile(newContent);
}
