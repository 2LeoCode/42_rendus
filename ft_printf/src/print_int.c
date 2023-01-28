/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 23:10:29 by lsuardi           #+#    #+#             */
/*   Updated: 2020/06/02 15:43:43 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static t_flags	adapt_padding(t_flags flags, char *nbr)
{
	t_flags		tmp;

	tmp = flags;
	if (*nbr == '-')
	{
		tmp.padding_left--;
		tmp.padding_right--;
		tmp.padding_zero--;
	}
	return (tmp);
}

void			fill_i(char *to_disp, char *nbr, t_flags flags, int len)
{
	int		prec;

	prec = flags.precision;
	if (flags.padding_zero > flags.precision)
		while (--flags.padding_left > flags.padding_zero)
			*(to_disp++) = ' ';
	else
		while (flags.padding_left--
		> (prec + (!prec * len) - (!prec && (*nbr == '0'))))
			*(to_disp++) = ' ';
	if (((*to_disp = *nbr) == '-') && nbr++)
		to_disp++;
	while (flags.precision && (flags.padding_zero-- > flags.precision))
		*(to_disp++) = '0';
	while (flags.precision-- > (len - (*nbr == '-')))
		*(to_disp++) = '0';
	if ((prec || (*nbr - '0')))
		while (*nbr)
			*(to_disp++) = *(nbr++);
	while (flags.padding_right--
	> prec + (!prec * len) - (!prec && (*nbr == '0')))
		*(to_disp++) = ' ';
	*to_disp = 0;
}

int				get_len_i(t_flags flags, char *nbr)
{
	int		len;

	len = ft_strlen(nbr);
	if ((flags.padding_left < len) && (flags.padding_zero < len)
	&& (flags.precision == len))
	{
		if ((flags.padding_right > len)
		&& (flags.padding_right > flags.precision))
			return (flags.padding_right + 1);
		return (flags.precision + 1);
	}
	if ((flags.padding_left >= len) && (flags.padding_left > flags.padding_zero)
	&& (flags.padding_left > flags.precision))
		return (flags.padding_left + 1);
	if ((flags.padding_right > len) && (flags.padding_right > flags.precision))
		return (flags.padding_right + 1);
	if (!flags.precision && (*nbr == '0'))
		return (1);
	if ((flags.padding_zero > len) && (flags.padding_zero > flags.precision))
		return (flags.padding_zero + 1);
	return ((flags.precision ? flags.precision : len) + 1);
}

int				free_failure(char **str)
{
	free(*str);
	*str = NULL;
	return (0);
}

int				print_i(int n, t_flags flags)
{
	char	*to_display;
	char	*nbr;
	int		len;

	if (!(nbr = ft_itoa(n)))
		return (0);
	flags = adapt_padding_before(flags);
	if (flags.precision && (flags.precision < (int)ft_strlen(nbr)))
		flags.precision = ft_strlen(nbr) - (*nbr == '-');
	if (!(len = get_len_i(flags, nbr))
	|| !(to_display = (char*)malloc(sizeof(char) * len)))
		return (free_failure(&nbr));
	len = ft_strlen(nbr) - (*nbr == '-');
	flags = adapt_padding(flags, nbr);
	fill_i(to_display, nbr, flags, len);
	free(nbr);
	nbr = NULL;
	return (ft_print(&to_display));
}
