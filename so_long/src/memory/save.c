/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:44:13 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 16:49:57 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_int.h"
#include "../stack/stack.h"

void	save(void *ptr, t_freef *free_fun)
{
	if (!ptr)
		ft_abort();
	if (stack_push(allocated_memory(), ptr)
		|| stack_push(allocated_memory() + 1, free_fun))
		clear_memory();
}
