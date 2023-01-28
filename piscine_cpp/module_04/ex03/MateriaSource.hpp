/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:37:21 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/25 15:03:50 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

#include "IMateriaSource.hpp"
#include "List.hpp"

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource();
		MateriaSource(const MateriaSource&);
		~MateriaSource();

		MateriaSource	&operator =(const MateriaSource&);

		void		learnMateria(AMateria*);
		void		unlearnMateria(int);
		AMateria	*createMateria(const std::string&);

		struct EInventoryFull : public std::exception {
			const char	*what(void) const throw ();
		};

	private:
		AMateria			*m_inventory[4];
		bool				m_occupied[4];
		List< AMateria* >	m_addr;
};
