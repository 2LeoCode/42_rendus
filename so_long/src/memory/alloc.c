/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:41:13 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 16:44:22 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_int.h"

#include <stdlib.h>

void	*alloc(size_t size)
{
	void	*ptr;

	save(ptr = malloc(size), free);
	return (ptr);
}
