/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 23:59:01 by lsuardi           #+#    #+#             */
/*   Updated: 2020/06/02 15:36:48 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int		get_precision(va_list ap, char **flags)
{
	int		precision;

	if (**flags == '*')
	{
		precision = va_arg(ap, int);
		(*flags)++;
		return (precision);
	}
	if (ft_isdigit(**flags))
	{
		precision = ft_atoi(*flags);
		while (ft_isdigit(**flags))
			(*flags)++;
		return (precision);
	}
	return (0);
}

static int		get_padding_right(va_list ap, char *flags)
{
	int		padding_right;

	padding_right = 0;
	while (*flags && (ft_isdigit(*flags) || *flags == '*'))
	{
		if (ft_isdigit(*flags))
			padding_right = ft_atoi(flags);
		while (ft_isdigit(*flags))
			flags++;
		if (*flags == '*')
		{
			padding_right = ft_abs(va_arg(ap, int));
			flags++;
		}
	}
	return (padding_right);
}

static t_flags	parse_flags_bis(va_list ap, char *flags)
{
	t_flags		tmp;
	char		*temp;

	tmp = init_flag_struct(ap, flags);
	temp = flags;
	while (*flags && ft_strfind(flags, ".-"))
	{
		if (ft_strchr(flags, '.')
		&& (!ft_strchr(flags, '-')
		|| (ft_strchr(flags, '.') < ft_strchr(flags, '-'))))
		{
			flags = ft_strchr(flags, '.') + 1;
			tmp.precision = get_precision(ap, &flags);
			if (*flags && (ft_strchr(temp, '-') < flags))
				tmp.padding_right = get_padding_right(ap, flags);
			else if (*flags)
				tmp.padding_left = get_padding_left(ap, flags);
			continue ;
		}
		if (ft_strchr(flags, '-') && *(flags = ft_strchr(flags, '-') + 1))
			tmp.padding_right = get_padding_right(ap, flags);
	}
	return (tmp);
}

t_flags			parse_flags(va_list ap, char *flags)
{
	t_flags tmp;

	if (!flags)
		return (init_flag_struct(ap, flags));
	tmp = parse_flags_bis(ap, flags);
	if (tmp.padding_left < 0)
	{
		tmp.padding_right = -tmp.padding_left;
		tmp.padding_left = 0;
	}
	return (tmp);
}
