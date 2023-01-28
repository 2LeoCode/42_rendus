/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_space_til.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 00:29:26 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 00:31:02 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "string.h"

size_t	skip_space_til(const char **s, int endc)
{
	size_t	cnt;

	cnt = 0;
	while (**s != endc && ft_isspace(**s))
	{
		++*s;
		++cnt;
	}
	return (cnt);
}
