/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 00:19:15 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/19 17:08:15 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <cstring>

static std::string	getFileString(const char *filename) {
	std::ifstream		in(filename);

	if (!in) throw (std::runtime_error("Could not open input file"));
	std::ostringstream	inStream;

	inStream << in.rdbuf();
	in.close();
	return (inStream.str());
}

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <string> <string>";
		std::cerr << std::endl;
		return (-1);
	}
	std::string		inputStr;
	size_t			haystackLen(std::strlen(argv[2]));
	size_t			pos(0);

	try {
		inputStr = getFileString(argv[1]);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (-1);
	}
	while ((pos = inputStr.find(argv[2])) != std::string::npos) {
		inputStr.erase(pos, haystackLen);
		inputStr.insert(pos, argv[3]);
	}
	std::ofstream	out((std::string(argv[1]) + ".replace").c_str(), std::ios::trunc);

	out << inputStr;
	out.close();
	return (0);
}
