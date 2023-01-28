/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 22:33:22 by lsuardi           #+#    #+#             */
/*   Updated: 2020/06/02 15:37:45 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int			get_padding_left(va_list ap, char *flags)
{
	int		padding_left;

	padding_left = 0;
	while (*flags && (ft_isdigit(*flags) || *flags == '*'))
	{
		if (ft_isdigit(*flags))
			padding_left = ft_atoi(flags);
		while (ft_isdigit(*flags))
			flags++;
		if (*flags == '*')
		{
			padding_left = va_arg(ap, int);
			flags++;
		}
	}
	return (ft_strchr(flags, '-') ? 0 : padding_left);
}

int			get_zeros(va_list ap, char **flags)
{
	int		padding_zero;

	padding_zero = 0;
	if (**flags != '0')
		return (0);
	while (**flags && (ft_isdigit(**flags) || **flags == '*'))
	{
		if (ft_isdigit(**flags))
			padding_zero = ft_atoi(*flags);
		while (ft_isdigit(**flags))
			(*flags)++;
		if (**flags == '*')
		{
			padding_zero = va_arg(ap, int);
			(*flags)++;
		}
	}
	return (ft_strchr(*flags, '-') ? 0 : padding_zero);
}

t_flags		init_flag_struct(va_list ap, char *flags)
{
	t_flags		new;

	new.padding_right = 0;
	new.precision = -1;
	new.padding_zero = 0;
	new.padding_left = 0;
	if (flags)
	{
		if ((new.padding_zero = get_zeros(ap, &flags)) < 0)
		{
			new.padding_right = -new.padding_zero;
			new.padding_zero = 0;
		}
		new.padding_left = get_padding_left(ap, flags);
	}
	return (new);
}
