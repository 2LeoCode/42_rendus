/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 23:56:21 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/20 18:41:52 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

int	main(int argc, char **argv) {
	std::string	option;

	if (argc == 2) option = argv[1];
	if (argc > 2 || (argc == 2 && option != "-d" && option != "--debug")) {
		std::cerr << "usage: " << argv[0] << " <-d|--debug>" << std::endl;
		return (-1);
	}
	ClapTrap	unnamed;
	ClapTrap	joe("joe");
	ClapTrap	steve("steve");
	
	if (argc == 2) {
		unnamed.enableDebugInfos();
		joe.enableDebugInfos();
		steve.enableDebugInfos();
	}
	std::cout << "ClapTrap unnamed wakes up, without knowing where he is" << std::endl;
	std::cout << "ClapTrap joe wakes up, without knowing where he is" << std::endl;
	std::cout << "ClapTrap steve wakes up, without knowing where he is" << std::endl;
	std::cout << "<steve> Hey! What's up!" << std::endl;
	std::cout << "<joe> Who are you ? Are you the dude who brought me here ?" << std::endl;
	std::cout << "<steve> I'm steve and no, I don't know where we are and I'm not a dude, I'm a robot." << std::endl;
	std::cout << "<joe> It's him! He's not talking! He's acting suspicious!" << std::endl;
	std::cout << "<unnamed> Maybe because I don't want to talk with some random idiots..." << std::endl;
	std::cout << "<steve> Me? Stupid? How dare you call the great ClapTrap steve idiot? What is your name anyway?" << std::endl;
	std::cout << "<unnamed> I don't have one." << std::endl;
	std::cout << "<joe> Are you f#$%@ kidding me?" << std::endl;
	std::cout << "<unnamed>I don't need a name, regular people need a name, but not me." << std::endl;
	std::cout << "<joe> Let's just call you Billy then." << std::endl;
	std::cout << "<steve> Agree." << std::endl;
	std::cout << "<unnamed> F#$! you! I didn't agree!" << std::endl;
	std::cout << "<steve> Anyway, so, you, what is your name?" << std::endl;
	std::cout << "<joe> My name is Joe. Joe the greatest of all..." << std::endl;
	std::cout << "<steve> Shut up! Did you hear that noise ?" << std::endl;
	std::cout << "<joe> What noise you dumb f#@!,? stop interrupting before the end of my sent..." << std::endl;
	std::cout << "A giant two headed bear suddendly appears from nowhere and smashes joe !" << std::endl;
	try {
		joe.takeDamage(100);
	} catch (std::string &err) {
		std::cout << err << std::endl;
	}
	std::cout << "<unnamed> NO! I'M COMING TO HELP YOU!" << std::endl;
	try {
		unnamed.attack("giant two headed bear");
		unnamed.attack("giant two headed bear");
	} catch (std::string &err) {
		std::cout << err << std::endl;
	}
	std::cout << "<steve> NOO! BILLY!!" << std::endl;
	std::cout << "The giant two headed bear punches unnamed in the face!" << std::endl;
	try {
		unnamed.takeDamage(9);
	} catch (std::string &err) {
		std::cout << err << std::endl;
	}
	std::cout << '<' << "steve" << "> Hold on Billy!" << std::endl;
	std::cout << "steve" << " is repairing " << "unnamed" <<
	'!' << std::endl;
	try {
		unnamed.beRepaired(5);
		unnamed.beRepaired(5);
		unnamed.beRepaired(5);
	} catch (std::string &err) {
		std::cout << err << std::endl;
	}
	std::cout << '<' << "steve" <<
	"> Run Billy! I'll hold him back!" << std::endl;
	std::cout << '<' << "unnamed" <<
	"> Why the hell do you even do that for me?"
	" You don't even know me!" << std::endl;
	std::cout << '<' << "steve" << "> Because your name is Billy,"
	" so I can't let you down here! Run !!!" << std::endl;
	steve.attack("giant two headed bear");
	std::cout << "The giant two headed bear jumps on " << "steve" <<
	" and litterally devours all his electrical components!" << std::endl;
	steve.takeDamage(9999);
	try {
		steve.beRepaired(99);
	} catch (std::string &err) {
		std::cout << err << std::endl;
	}
	std::cout << "unnamed" << " manages to escape!" << std::endl;
	std::cout << '<' << "unnamed" <<
	"> What a bunch of idiots.." << std::endl;
	return (0);
}