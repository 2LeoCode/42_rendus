/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:59:56 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/20 20:54:20 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap &other);
		virtual ~DiamondTrap();

		DiamondTrap	&operator =(const DiamondTrap &other);
		DiamondTrap(std::string name);

		void	whoAmI(void) const;

	private:
		std::string	m_name;
};
