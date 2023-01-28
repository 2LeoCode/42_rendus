/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:38:32 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/22 18:12:25 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Animal {
	public:
		Animal();
		Animal(const Animal&);
		virtual ~Animal();

		Animal	&operator =(const Animal&);

		virtual void		makeSound(void) const;
		const std::string	&getType(void) const;

	protected:
		std::string	m_type;
};
