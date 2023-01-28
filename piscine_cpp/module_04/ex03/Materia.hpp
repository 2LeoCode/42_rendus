/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:43:19 by lsuardi           #+#    #+#             */
/*   Updated: 2022/01/23 23:20:35 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

#include <iostream>

class Materia : public AMateria {
	public:
		Materia();
		Materia(const Materia &other);
 		Materia(std::string name, std::string msg);
		virtual ~Materia();

		Materia &operator =(const Materia &other);

		AMateria	*clone(void) const;
		void		use(ICharacter &target);

	protected:
		std::string	m_msg;
};

std::istream	&operator >>(std::istream &in, Materia &m);
