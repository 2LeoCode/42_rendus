/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:33:12 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/14 18:13:18 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory.h>
#include <list.h>

int	list_push(t_list **lst, void *value)
{
	t_list	*ptr;

	ptr = allocate(sizeof(t_list));
	if (!ptr)
		return (-1);
	ptr->data = value;
	ptr->next = *lst;
	*lst = ptr;
	return (0);
}
