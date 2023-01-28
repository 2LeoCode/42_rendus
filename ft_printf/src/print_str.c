/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 21:47:19 by lsuardi           #+#    #+#             */
/*   Updated: 2020/05/30 18:51:24 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		fill_s(char *to_disp, char *str, t_flags flags)
{
	int		prec;

	prec = flags.precision;
	while (--flags.padding_zero >= prec)
		*(to_disp++) = '0';
	while (--flags.padding_left >= prec)
		*(to_disp++) = ' ';
	while (--flags.precision >= 0)
		*(to_disp++) = *(str++);
	while (--flags.padding_right >= prec)
		*(to_disp++) = ' ';
	*to_disp = 0;
}

static int		get_len_s(t_flags flags)
{
	if (flags.padding_zero)
	{
		if (flags.padding_zero > flags.precision)
			return (flags.padding_zero + 1);
		return (flags.precision + 1);
	}
	if (flags.padding_left)
	{
		if (flags.padding_left > flags.precision)
			return (flags.padding_left + 1);
		return (flags.precision + 1);
	}
	if (flags.padding_right)
	{
		if (flags.padding_right > flags.precision)
			return (flags.padding_right + 1);
	}
	return (flags.precision + 1);
}

int				print_s(char *str, t_flags flags, char *all_flags)
{
	char	*to_display;
	int		len;

	if (!str)
		return (print_s("(null)", flags, all_flags));
	if (all_flags && (*all_flags == '0'))
	{
		if (flags.padding_left > flags.padding_zero)
			flags.padding_zero = flags.padding_left;
		flags.padding_left = 0;
	}
	if ((flags.precision < 0) || (flags.precision > (int)ft_strlen(str)))
		flags.precision = ft_strlen(str);
	len = get_len_s(flags);
	if (!(to_display = (char*)malloc(sizeof(char) * len)))
		return (0);
	fill_s(to_display, str, flags);
	return (ft_print(&to_display));
}
