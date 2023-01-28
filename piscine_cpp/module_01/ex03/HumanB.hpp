/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:43:27 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/19 15:13:05 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

#include <string>

class HumanB {
	public:

	HumanB(std::string name);
	~HumanB();

	void	setWeapon(Weapon &weapon);
	void	attack(void) const;

	private:

	std::string	_name;
	Weapon		*_weapon;
};

/*
** In this case, HumanB can have no weapon, so we will use a pointer to store
** the weapon, then we can set it to NULL to represent 'no weapon', and we
** still will be able to access it outside the class as it's a pointer.
*/
