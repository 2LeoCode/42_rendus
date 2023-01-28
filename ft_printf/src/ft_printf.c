/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 21:05:37 by lsuardi           #+#    #+#             */
/*   Updated: 2020/05/26 14:44:27 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_printf(const char *format, ...)
{
	va_list		vars;
	t_list		*param;
	int			len;

	if (!format)
	{
		ft_putstr(NULL);
		return (0);
	}
	if (!(param = ft_lstinit()))
		return (-1);
	if (parse_fmt(format, &param) < 0)
		return (0);
	va_start(vars, format);
	len = print_fmt(format, vars, param);
	ft_lstclear(&param);
	va_end(vars);
	return (len);
}
