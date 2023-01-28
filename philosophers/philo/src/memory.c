/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:22:00 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/14 16:48:33 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>
#include <mutex.h>
#include <stdlib.h>

static t_list	**memory(void)
{
	static t_list	*memory = NULL;

	return (&memory);
}

void	memory_clear(void)
{
	t_list	*ptr;

	while (*memory())
	{
		ptr = (*memory())->next;
		free((*memory())->data);
		free(*memory());
		*memory() = ptr;
	}
}

void	*allocate(size_t size)
{
	void	*ptr;
	t_list	*l_ptr;

	ptr = malloc(size);
	l_ptr = malloc(sizeof(t_list));
	if (!ptr || !l_ptr)
	{
		free(ptr);
		ptr = NULL;
		mutex_clear();
		memory_clear();
	}
	l_ptr->data = ptr;
	l_ptr->next = *memory();
	*memory() = l_ptr;
	return (ptr);
}

void	deallocate(void *addr)
{
	t_list	*ptr0;
	t_list	*ptr1;

	free(addr);
	ptr0 = *memory();
	ptr1 = NULL;
	while (ptr0 && ptr0->data != addr)
	{
		ptr1 = ptr0;
		ptr0 = ptr0->next;
	}
	if (ptr0)
	{
		if (ptr1)
			ptr1->next = ptr0->next;
		else
			*memory() = ptr0->next;
		free(ptr0);
	}
}
