/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:41:37 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 16:33:02 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

void	*stack_pop(t_stack *st)
{
	t_stacknode	*ptr;
	void		*val;

	val = NULL;
	if (st->top)
	{
		ptr = st->top->next;
		val = st->top->data;
		free(st->top);
		st->top = ptr;
		--st->size;
	}
	return (val);
}
