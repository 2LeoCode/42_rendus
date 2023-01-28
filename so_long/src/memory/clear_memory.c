/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:49:21 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 16:49:52 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack/stack.h"
#include "memory_int.h"

void	clear_memory(void)
{
	while (!stack_empty(allocated_memory()))
	{
		((t_freef *)stack_pop(allocated_memory() + 1))
		(stack_pop(allocated_memory()));
	}
}
