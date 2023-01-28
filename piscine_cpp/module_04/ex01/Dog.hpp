/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:01:19 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 13:32:57 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

struct Dog : public Animal {
	public:
		Dog();
		Dog(const Dog&);
		~Dog();

		Dog	&operator =(const Dog&);

		void	makeSound(void) const;

	private:
		Brain	*m_brain;
};
