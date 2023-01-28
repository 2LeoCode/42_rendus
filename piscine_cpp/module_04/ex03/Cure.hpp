/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:26:23 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 22:53:05 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Materia.hpp"

struct Cure : public Materia {
	Cure();
	Cure(const Cure&);
	~Cure();

	Cure	&operator =(const Cure&);
};

