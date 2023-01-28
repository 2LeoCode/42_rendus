/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:51:39 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/20 20:59:25 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {
	public:

	FragTrap();
	FragTrap(const FragTrap &other);
	virtual ~FragTrap();

	FragTrap	&operator =(const FragTrap &other);
	FragTrap(std::string name);

	void	highFiveGuys(void) const;
};
