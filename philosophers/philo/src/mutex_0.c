/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:55:29 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/14 18:28:44 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mutex.h>
#include <stdbool.h>
#include <memory.h>

t_list	**mutex_list(void)
{
	static t_list	*mutex_list;

	return (&mutex_list);
}

void	mutex_clear(void)
{
	t_list	*ptr;

	ptr = *mutex_list();
	while (ptr)
	{
		*mutex_list() = ptr->next;
		pthread_mutex_destroy(ptr->data);
		ptr = *mutex_list();
	}
}

t_mutex	*mutex_init(void)
{
	t_mutex	*ptr;

	ptr = allocate(sizeof(t_mutex));
	if (!ptr || pthread_mutex_init(&ptr->data, NULL)
		|| pthread_mutex_init(&ptr->prot, NULL)
		|| list_push(mutex_list(), &ptr->data)
		|| list_push(mutex_list(), &ptr->prot))
		return (NULL);
	ptr->locked = false;
	return (ptr);
}
