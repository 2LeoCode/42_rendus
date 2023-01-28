/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:01:07 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/22 18:22:48 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

struct WrongCat : public WrongAnimal {
	WrongCat();
	WrongCat(const WrongCat&);

	~WrongCat();

	WrongCat	&operator =(const WrongCat&);
};
