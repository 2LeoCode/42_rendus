/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Random.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:24:41 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/02/12 15:44:10 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define STATEBUF_SIZE 2048

struct Random {
	Random();
	~Random();

	int	operator ()(const int&, const int&);

	private:
		Random	&operator =(const Random&);
		Random(const Random&);

		bool	m_init(void);

		static char	m_statebuf[STATEBUF_SIZE];
};
