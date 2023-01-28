/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 17:03:09 by lsuardi           #+#    #+#             */
/*   Updated: 2020/05/26 14:49:33 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		print_u(unsigned int n, t_flags flags)
{
	char	*to_display;
	char	*nbr;
	int		len;

	if (!(nbr = ft_uitoa(n)))
		return (0);
	flags = adapt_padding_before(flags);
	if (flags.precision && (flags.precision < (int)ft_strlen(nbr)))
		flags.precision = ft_strlen(nbr);
	if (!(len = get_len_i(flags, nbr))
	|| !(to_display = (char*)malloc(sizeof(char) * len)))
		return (free_failure(&nbr));
	fill_i(to_display, nbr, flags, ft_strlen(nbr));
	free(nbr);
	nbr = NULL;
	return (ft_print(&to_display));
}
