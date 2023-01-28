/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:21:59 by crochu            #+#    #+#             */
/*   Updated: 2022/01/27 11:41:15 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fun.hpp"
#include <iostream>

int main(void) {
	int ai = 42, bi = 15;
	float af = .42f, bf = .15f;

	std::cout << "max((int)42, (int)15) = " << ::max(ai, bi) << std::endl;
	std::cout << "min((int)42, (int)15) = " << ::min(ai, bi) << std::endl;

	std::cout << "max((float).42f, (float).15f) = " << ::max(af, bf) << std::endl;
	std::cout << "min((float).42f, (float).15f) = " << ::min(af, bf) << std::endl;

	std::cout << "ai = " << ai << ", bi = " << bi << std::endl;
	std::cout << "swap(ai, bi)" << std::endl, ::swap(ai, bi);
	std::cout << "ai = " << ai << ", bi = " << bi << std::endl;

	std::cout << "af = " << af << ", bf = " << bf << std::endl;
	std::cout << "swap(af, bf)" << std::endl, ::swap(af, bf);
	std::cout << "af = " << af << ", bf = " << bf << std::endl;
	return 0;
}
