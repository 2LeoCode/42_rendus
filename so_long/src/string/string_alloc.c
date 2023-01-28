/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 09:22:26 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/11 20:18:54 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../memory/memory.h"
#include "string.h"

t_string	*string_alloc(size_t size)
{
	t_string	*s;

	s = alloc(sizeof(*s) + sizeof(*s->c) * size);
	s->cap = size;
	s->size = 0;
	if (size)
		*s->c = 0;
	return (s);
}
