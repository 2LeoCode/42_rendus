/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:14:26 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 13:29:17 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Brain {
	public:
		Brain();
		~Brain();

		Brain(const Brain&);
		Brain	&operator=(const Brain&);

	private:
		std::string	m_ideas[100];
};
