/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:10:08 by lsuardi           #+#    #+#             */
/*   Updated: 2020/05/28 15:24:03 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_list	*ft_lstinit(void)
{
	t_list *tmp;

	if (!(tmp = malloc(sizeof(t_list))))
		return (NULL);
	tmp->type = 0;
	tmp->flags = NULL;
	tmp->next = NULL;
	return (tmp);
}

t_list	*ft_lstlast(t_list *lst)
{
	return ((!lst || !lst->next) ? lst : ft_lstlast(lst->next));
}

void	ft_lstadd_back(t_list **lst)
{
	if (*lst)
		ft_lstlast(*lst)->next = ft_lstinit();
}

void	ft_lstclear(t_list **lst)
{
	t_list	*head;

	if (!*lst)
		return ;
	head = (*lst)->next;
	free((*lst)->flags);
	free(*lst);
	*lst = NULL;
	ft_lstclear(&head);
}
