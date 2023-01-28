/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:27:57 by crochu            #+#    #+#             */
/*   Updated: 2022/01/26 11:14:38 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

int main(void) {
	Form generic, named("B-35"), a42("A-42", 100), a01("A-01", 50), a02("A-02", 1);
	Bureaucrat a("kevin", 150), b("joe", 100), c("john", 50), d("boss", 1);

	std::cout << generic << '\n' << named << '\n' << a42 << '\n' << a01 <<
		'\n' << std::endl;
	a.signForm(a42);
	a.signForm(a01);
	a.signForm(generic);
	a.signForm(named);
	b.signForm(a42);
	c.signForm(a01);
	c.signForm(a01);
	return 0;
}
