/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:18:39 by user42            #+#    #+#             */
/*   Updated: 2020/11/11 14:46:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBASM_BONUS_H
# define _LIBASM_BONUS_H

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

void				ft_list_push_front(t_list **begin_list, void *data);
int					ft_list_size(t_list *begin_list);
void				ft_list_sort(t_list **begin_list, int (*cmp)());
void				ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void*));
int					ft_atoi_base(char *str, char *base);
#endif