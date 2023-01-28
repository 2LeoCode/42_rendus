/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:31:26 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/24 17:40:20 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

#include <string>

class ICharacter;

class AMateria {
	public:
		AMateria();
		virtual ~AMateria();

		AMateria(const AMateria&);
		AMateria(const std::string&);

		AMateria	&operator=(const AMateria &);

		const std::string	&getType(void) const;
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter&) = 0;

	protected:
		std::string	m_type;
};
