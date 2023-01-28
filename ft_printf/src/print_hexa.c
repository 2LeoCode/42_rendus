/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 15:54:39 by lsuardi           #+#    #+#             */
/*   Updated: 2020/06/02 15:44:35 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int		ft_hexlen(unsigned int n)
{
	return (n ? (1 + ft_hexlen(n / 16)) : 0);
}

static void		get_x(unsigned int n, char *str, int size)
{
	if (!size)
		return ;
	str[size - 1] = (n % 16) < 10 ? ((n % 16) + 48) : ((n % 16) + 87);
	get_x(n / 16, str, size - 1);
}

int				print_x(unsigned int n, t_flags flags, t_bool caps)
{
	char	*str;
	char	*to_display;
	int		len;

	if (!(len = ft_hexlen(n)))
		len++;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	str[len] = 0;
	get_x(n, str, len);
	flags = adapt_padding_before(flags);
	if (flags.precision && (flags.precision < (int)ft_strlen(str)))
		flags.precision = ft_strlen(str);
	if (!(len = get_len_i(flags, str))
	|| !(to_display = (char*)malloc(sizeof(char) * len)))
		return (free_failure(&str));
	if (caps)
		ft_strcapitalize(str);
	fill_i(to_display, str, flags, ft_strlen(str));
	free(str);
	str = NULL;
	return (ft_print(&to_display));
}
