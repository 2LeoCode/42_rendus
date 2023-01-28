/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_nospace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 00:23:23 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 00:27:01 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "string.h"

size_t	skip_nospace(const char **s)
{
	size_t	cnt;

	cnt = 0;
	while (**s && !ft_isspace(**s))
	{
		++*s;
		++cnt;
	}
	return (cnt);
}
