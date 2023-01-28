/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 03:05:34 by crochu            #+#    #+#             */
/*   Updated: 2022/02/12 20:15:33 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "Random.hpp"
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

void	test_span(const Span &sp) {
	static unsigned i;

	std::cout << "---Span " << ++i << "---\n" << sp << '\n'
		<< "Shortest span: " << sp.shortestSpan() << '\n'
		<< "Longest span: " << sp.longestSpan() << '\n' << std::endl;
}

int main(void) {
	Random	rng;
	try {
		Span	sp = Span(5), sp2(10000), sp3(15);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		for (int i = 0; i < 10000; ++i)
			sp2.addNumber(rng(1, 1000000));
		sp3.addNumbers(sp2.begin(), sp2.begin() + 15);
		test_span(sp); // test 1
		test_span(sp2); // test 2
		test_span(Span(sp2)); // test 3
		test_span(Span(sp2.begin(), sp2.end())); // test 4
		test_span(sp3);// test 5
	} catch (const std::exception &e) {
		std::cerr << "Abnormal termination\nwhat: " << e.what() << std::endl;
	}
	return 0;
}
