/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocated_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:06:18 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 16:49:17 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "../stack/stack.h"
#include "../mlx_rework/mlx_rework.h"

#include <stdlib.h>

t_stack	*allocated_memory(void)
{
	static t_stack	memory_stack[2] = {0};

	return (memory_stack);
}
