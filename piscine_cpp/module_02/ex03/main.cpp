/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:59:58 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/20 17:50:32 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

#define PRINT_BSP(a, b, c, p); {\
	if (bsp(a, b, c, p))\
		std::cout << "true" << std::endl;\
	else std::cout << "false" << std::endl;\
}

bool	bsp(const Point a, const Point b, const Point c, const Point p);

Point	a(-6.5016, 4.0122),
		b(-3.041, 5.5852),
		c(-2.3392, 2.6328),
		d(-4.97458, 6.2052),	//Outside
		e(-3.15129, 4.36317),	//Inside
		f(-7.5, 1),				//Outside
		g(-2.84597, 2.68393),	//Outside
		h(-5.55791, 3.74356);	//Inside

int	main(void) {
	PRINT_BSP(a, b, c, d); // false
	PRINT_BSP(a, b, c, e); // true
	PRINT_BSP(a, b, c, f); // false
	PRINT_BSP(a, b, c, g); // false
	PRINT_BSP(a, b, c, h); // true
	PRINT_BSP(a, b, c, a); // true
	PRINT_BSP(a, b, c, b); // true
	PRINT_BSP(a, b, c, c); // true
	return 0;
}
