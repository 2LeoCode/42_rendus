/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:38:46 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/05 19:36:59 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

int	stack_push(t_stack *st, void *value)
{
	t_stacknode	*new_node;

	new_node = malloc(sizeof(t_stacknode));
	if (!new_node)
		return (-1);
	new_node->data = value;
	new_node->next = st->top;
	st->top = new_node;
	++st->size;
	return (0);
}
