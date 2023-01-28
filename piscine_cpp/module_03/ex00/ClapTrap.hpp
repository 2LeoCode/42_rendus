/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:30:11 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/20 20:45:27 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ClapTrap {
	public:
		typedef	std::string	&exception_type;

		ClapTrap();
		virtual ~ClapTrap();

		ClapTrap(const ClapTrap &other);
		ClapTrap(std::string name);

		ClapTrap	&operator =(const ClapTrap &other);

		void	attack(std::string const &target);
		void	takeDamage(unsigned amount);
		void	beRepaired(unsigned amount);

		void	enableDebugInfos(void);
		void	debugInfo(void) const;

	protected:
		std::string	m_name;
		int			m_hp;
		int			m_ep;
		int			m_dmg;
		bool		m_debugInfo;
};
