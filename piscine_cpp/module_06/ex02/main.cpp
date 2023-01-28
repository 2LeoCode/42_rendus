/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:53:23 by crochu            #+#    #+#             */
/*   Updated: 2022/01/27 11:07:21 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "UniquePtr.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base *newA(void) { return new A; }
Base *newB(void) { return new B; }
Base *newC(void) { return new C; }

Base *generate(void) {
	return ((Base *(*[])()){ newA, newB, newC }[random() % 3]());
}

void identify(Base *ptr) {
	if (dynamic_cast< A* >(ptr)) std::cout << 'A' << std::endl;
	else if (dynamic_cast< B* >(ptr)) std::cout << 'B' << std::endl;
	else if (dynamic_cast< C* >(ptr)) std::cout << 'C' << std::endl;
}

void identify(Base &ref) {
	try {
		static_cast< void >(dynamic_cast< A& >(ref));
		std::cout << 'A' << std::endl;
	} catch (const std::exception &e) { static_cast< void >(e); }
	try {
		static_cast< void >(dynamic_cast< B& >(ref));
		std::cout << 'B' << std::endl;
	} catch (const std::exception &e) { static_cast< void >(e); }
	try {
		static_cast< void >(dynamic_cast< C& >(ref));
		std::cout << 'C' << std::endl;
	} catch (const std::exception &e) { static_cast< void >(e); }
}

int main(void) {
	srandom(time(NULL));
	UniquePtr< Base > p1, p2, p3;
	A	a;
	B	b;
	C	c;

	identify(&a), identify(&b), identify(&c);
	std::cout << std::endl;
	identify(a), identify(b), identify(c);
	std::cout << std::endl;
	try {
		p1 = generate(), p2 = generate(), p3 = generate();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	identify(&*p1), identify(&*p2), identify(&*p3);
	std::cout << std::endl;
	identify(*p1), identify(*p2), identify(*p3);
	return 0;
}
