/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 21:59:03 by lsuardi           #+#    #+#             */
/*   Updated: 2020/05/22 19:21:12 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		fill_c(char *to_disp, char c, t_flags flags)
{
	while (--flags.padding_left > 0)
		*(to_disp++) = ' ';
	while (--flags.padding_zero > 0)
		*(to_disp++) = '0';
	*(to_disp++) = c;
	while (--flags.padding_right > 0)
		*(to_disp++) = ' ';
	*to_disp = 0;
}

static int		display_c(char **str, char c, t_flags flags)
{
	int		len;

	len = ft_strlen(*str);
	if (!c)
		len = (flags.padding_right ? flags.padding_right : (len + 1));
	write(1, *str, len);
	free(*str);
	*str = NULL;
	return (len);
}

int				print_c(char c, t_flags flags, char *all_flags)
{
	char	*to_display;
	int		len;

	len = flags.padding_zero + flags.padding_left + flags.padding_right;
	len += (len ? 1 : 2);
	if (flags.precision < 0)
		flags.precision = 1;
	if (!(to_display = (char*)malloc(sizeof(char) * len)))
		return (0);
	if (all_flags && *all_flags == '0')
	{
		if (flags.padding_left > flags.padding_zero)
			flags.padding_zero = flags.padding_left;
		flags.padding_left = 0;
	}
	fill_c(to_display, c, flags);
	return (display_c(&to_display, c, flags));
}
