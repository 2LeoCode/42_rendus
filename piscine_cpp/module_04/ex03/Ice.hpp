/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:20:02 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 23:20:00 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Materia.hpp"

struct Ice : public Materia {
	Ice();
	Ice(const Ice &other);
	~Ice();

	Ice	&operator =(const Ice &other);
};
