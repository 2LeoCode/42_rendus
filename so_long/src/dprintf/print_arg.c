/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:31:44 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 16:34:25 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dprintf_int.h"
#include <stddef.h>
#include <limits.h>

t_printfun	*print_arg(unsigned char c)
{
	static t_printfun	*print_fun[UCHAR_MAX + 1] = {
	[99] = print_char,
	[115] = print_str,
	[100] = print_int,
	[105] = print_int
	};

	return (print_fun[(int)c]);
}
