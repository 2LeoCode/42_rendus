/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 01:21:49 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/18 17:56:44 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cctype>

namespace ft {
	template <
		class InputIt,
		class OutputIt,
		class UnaryOperation
	> OutputIt	transform(InputIt first, InputIt last, OutputIt d_first, UnaryOperation f) {
		while (first != last)
			*d_first++ = f(*first++);
		return last;
	}
	char	to_upper(const char &c) { return std::toupper(c); }
}

int	main(int argc, char **argv) {
	std::string	msg;

	if (argc == 1)
		msg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		for (int i = 1; i < argc - 1; ++i)
			msg += argv[i], msg += ' ';
		msg += argv[argc - 1];
		ft::transform(msg.begin(), msg.end(), msg.begin(), ft::to_upper);
	}
	std::cout << msg << std::endl;
	return 0;
}
