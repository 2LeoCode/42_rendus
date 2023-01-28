/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:01:07 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 13:19:18 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

struct Cat : public Animal {
	public:
		Cat();
		Cat(const Cat&);
		~Cat();

		Cat	&operator =(const Cat&);

		void	makeSound(void) const;

	private:
		Brain	*m_brain;
};
