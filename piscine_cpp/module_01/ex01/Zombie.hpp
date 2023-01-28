/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:29:56 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/19 13:44:57 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie {
	public:

	Zombie();
	Zombie(std::string &name);
	~Zombie();

	Zombie	operator=(const Zombie &src);
	
	void	announce(void);
	void	setName(std::string name);

	private:

	std::string	_name;
};
