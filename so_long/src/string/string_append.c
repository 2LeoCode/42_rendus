/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 09:32:56 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/11 20:39:59 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void	string_append(t_string **dst, const char *src)
{
	const size_t	srclen = ft_strlen(src);
	size_t			new_cap;

	new_cap = (*dst)->cap;
	while ((*dst)->size + srclen > new_cap)
		new_cap *= 2;
	string_realloc(dst, new_cap);
	ft_memcpy((*dst)->c + (*dst)->size, src, sizeof(char) * (srclen + 1));
	(*dst)->size += srclen;
}
