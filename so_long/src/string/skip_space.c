/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 00:27:15 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 00:28:59 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "string.h"

size_t	skip_space(const char **s)
{
	size_t	cnt;

	cnt = 0;
	while (ft_isspace(**s))
	{
		++*s;
		++cnt;
	}
	return (cnt);
}
