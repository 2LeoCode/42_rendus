/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:29:33 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/05 19:03:11 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_stacknode	t_stacknode;
struct s_stacknode
{
	void		*data;
	t_stacknode	*next;
};

typedef struct s_stack
{
	t_stacknode	*top;
	size_t		size;	
}	t_stack;

int		stack_push(t_stack *st, void *value);
void	*stack_pop(t_stack *st);
void	*stack_extract(t_stack *st, void *value);
size_t	stack_size(const t_stack *st);
bool	stack_empty(const t_stack *st);

#endif
