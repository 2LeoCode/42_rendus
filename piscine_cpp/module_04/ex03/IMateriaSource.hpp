/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:36:12 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 15:40:46 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

struct IMateriaSource {
	virtual	~IMateriaSource() { }
	virtual void		learnMateria(AMateria*) = 0;
	virtual AMateria*	createMateria(const std::string&) = 0;
};
