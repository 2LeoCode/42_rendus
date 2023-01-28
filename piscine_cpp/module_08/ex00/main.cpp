/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 02:33:13 by crochu            #+#    #+#             */
/*   Updated: 2022/02/12 20:41:55 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <vector>
#include <iostream>
#include <typeinfo>
#include <stdexcept>
#include <vector>
#include <list>

template <
	class Container
> void	test_easyfind(Container &cont, int value) {
	int		found;

	std::cout << "Container type: " << typeid(Container).name() << '\n';
	std::cout << "Value: " << value << '\n';
	try {
		found = easyfind(cont, value);
		std::cout << "Found: " << found;
	} catch (const std::out_of_range &e) {
		std::cout << "std::out_of_range: " << e.what();
	}
	std::cout << '\n' << std::endl;
}

int main(void) {
	std::vector< int >	v(10, 5);
	std::list< int >	l(10, 5);

	v[0] = 1;
	v[5] = 0;
	*++(++(++l.begin())) = 42;
	*l.rbegin() = 0;

//	v = { 1, 5, 5, 5, 5, 0, 5, 5, 5, 5 }
//	l = { 5, 5, 5, 42, 5, 5, 5, 5, 5, 0 }

	test_easyfind(v, 0);
	test_easyfind(v, 1);
	test_easyfind(v, 10);
	test_easyfind(v, 42);

	test_easyfind(l, 0);
	test_easyfind(l, 1);
	test_easyfind(l, 10);
	test_easyfind(l, 42);
	return 0;
}
