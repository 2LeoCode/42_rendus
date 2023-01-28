/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:45:04 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 17:05:14 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack/stack.h"
#include "memory_int.h"

#include <stdlib.h>

static void	remove_element(t_stacknode *p1, t_stacknode *p2,
	t_stacknode *c1, t_stacknode *c2)
{
	if (p1)
	{
		p1->next = c1->next;
		p2->next = c2->next;
	}
	else
	{
		allocated_memory()->top = c1->next;
		allocated_memory()[1].top = c2->next;
	}
	if (c2->data)
		((t_freef *)c2->data)(c1->data);
	free(c1);
	free(c2);
	--allocated_memory()->size;
	--allocated_memory()[1].size;
}

void	dealloc(void *ptr)
{
	t_stacknode	*mem;
	t_stacknode	*ffun;
	t_stacknode	*prev1;
	t_stacknode	*prev2;

	mem = allocated_memory()->top;
	ffun = allocated_memory()[1].top;
	prev1 = NULL;
	prev2 = NULL;
	while (mem)
	{
		if (mem->data == ptr)
		{
			remove_element(prev1, prev2, mem, ffun);
			return ;
		}
		prev1 = mem;
		prev2 = ffun;
		mem = mem->next;
		ffun = ffun->next;
	}
}
