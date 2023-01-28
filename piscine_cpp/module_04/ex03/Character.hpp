/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:30:37 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/25 14:40:53 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>

#include "ICharacter.hpp"
#include "List.hpp"

class Character : public ICharacter {
	public:
		Character();
		~Character();

		Character(const Character &other);
		Character(std::string name);

		Character	&operator=(const Character &other);

		virtual std::string const	&getName(void) const;
		virtual void				equip(AMateria *m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter &target);
		void						deleteInventory(void);

		struct EInventoryFull : public std::exception {
			const char	*what(void) const throw ();
		};

	private:
		std::string			m_name;
		AMateria			*m_inventory[4];
		bool				m_occupied[4];
		List< AMateria* >	m_addr;
};
