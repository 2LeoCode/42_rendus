/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:00:31 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 16:38:04 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include <stddef.h>

typedef void	t_freef(void *);

void	*alloc(size_t size);
void	dealloc(void *ptr);
void	save(void *ptr, t_freef *free_fun);
void	clear_memory(void);

void	ft_swap(void *a, void *b, size_t size);
void	ft_abort(void);
void	invalid_argument(void);

#endif
