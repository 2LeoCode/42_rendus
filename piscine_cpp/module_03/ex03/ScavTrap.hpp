/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 01:24:40 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/20 21:02:41 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
	public:

	ScavTrap();
	ScavTrap(const ScavTrap &other);
	virtual ~ScavTrap();

	ScavTrap	&operator =(const ScavTrap &other);
	ScavTrap(std::string name);

	void	attack(std::string target);
	void	guardGate(void);
};
