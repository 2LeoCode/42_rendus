/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dprintf_int.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:12:27 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/04 13:49:31 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DPRINTF_INT_H
# define DPRINTF_INT_H

# include "dprintf.h"
# include <stdarg.h>

typedef struct s_buffer	t_buffer;
typedef int				t_printfun(int, va_list *);

struct s_buffer
{
	unsigned int	pos;
	char			data[DPRINTF_BUFFER_SIZE];
};

t_buffer	*dprintf_buffer(int fd);
void		buffer_add(int fd, char c);
t_printfun	*print_arg(unsigned char c);
int			print_char(int fd, va_list *ap);
int			print_str(int fd, va_list *ap);
int			print_int(int fd, va_list *ap);

#endif
