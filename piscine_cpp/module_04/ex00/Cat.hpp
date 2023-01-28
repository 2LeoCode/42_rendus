/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:01:07 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/22 18:12:31 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

struct Cat : public Animal {
	Cat();
	Cat(const Cat&);
	~Cat();

	Cat	&operator =(const Cat&);

	void	makeSound(void) const;
};
