/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 09:24:23 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/11 20:18:48 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "../memory/memory.h"

void	string_realloc(t_string **s, size_t new_cap)
{
	t_string	*ptr;

	if (new_cap > (*s)->cap)
	{
		ptr = alloc(sizeof(*ptr) + sizeof(*ptr->c) * new_cap);
		ptr->cap = new_cap;
		ptr->size = (*s)->size;
		if ((*s)->cap)
			ft_memcpy(ptr->c, (*s)->c, (*s)->size + 1);
		else
			*ptr->c = 0;
		dealloc(*s);
		*s = ptr;
	}
}
