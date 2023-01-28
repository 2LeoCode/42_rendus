/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 17:19:12 by lsuardi           #+#    #+#             */
/*   Updated: 2020/06/02 16:04:22 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static t_bool	adapt_padding(t_flags flags)
{
	return ((flags.precision > flags.padding_zero)
	&& (flags.precision > flags.padding_left)
	&& (flags.precision > flags.padding_right));
}

static void		fill_address(char *to_disp, char *nbr, t_flags flags)
{
	int		len;
	int		prec;

	len = ft_strlen(nbr);
	prec = flags.precision;
	if (flags.padding_zero > flags.precision)
		while (--flags.padding_left >= flags.padding_zero + 2)
			*(to_disp++) = ' ';
	else
		while (flags.padding_left--
	> prec + 2 + (!prec * len) - (!prec && (*nbr == '0')))
			*(to_disp++) = ' ';
	to_disp = ft_strcpy(to_disp, "0x") + 2;
	while (--flags.padding_zero >= flags.precision + 2)
		*(to_disp++) = '0';
	while (--flags.precision >= len)
		*(to_disp++) = '0';
	if (prec || (*nbr - '0'))
		while (*nbr)
			*(to_disp++) = *(nbr++);
	while (flags.padding_right--
	> prec + 2 + (!prec * len) - (!prec && (*nbr == '0')))
		*(to_disp++) = ' ';
	*to_disp = 0;
}

static int		ft_addlen(t_ullong n)
{
	return (n ? (1 + ft_addlen(n / 16)) : 0);
}

static void		get_address(t_ullong n, char *str, int size)
{
	if (!size)
		return ;
	str[size - 1] = (n % 16) < 10 ? ((n % 16) + 48) : ((n % 16) + 87);
	get_address(n / 16, str, size - 1);
}

int				print_p(t_ullong n, t_flags flags)
{
	char	*to_disp;
	char	*add;
	int		len;

	if (!(len = ft_addlen(n)))
		len++;
	if (!(add = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	add[len] = 0;
	get_address(n, add, len);
	if (flags.precision > 0 && (flags.padding_zero > flags.precision)
	&& (flags.padding_zero > flags.padding_left))
	{
		flags.padding_left = flags.padding_zero;
		flags.padding_zero = 0;
	}
	if (flags.precision && (flags.precision < (int)ft_strlen(add)))
		flags.precision = ft_strlen(add);
	if (!(len = get_len_i(flags, add) + 2 * adapt_padding(flags))
	|| !(to_disp = (char*)malloc(sizeof(char) * len)))
		return (free_failure(&add));
	fill_address(to_disp, add, flags);
	free(add);
	add = NULL;
	return (ft_print(&to_disp));
}
