/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:38:32 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/22 18:19:12 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal&);
		virtual ~WrongAnimal();

		WrongAnimal	&operator =(const WrongAnimal&);
		virtual void	makeSound(void) const;
		const std::string	&getType(void) const;

	protected:
		std::string	m_type;
};
