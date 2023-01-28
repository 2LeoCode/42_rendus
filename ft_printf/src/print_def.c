/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_def.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 18:45:43 by lsuardi           #+#    #+#             */
/*   Updated: 2020/05/28 15:27:02 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_flags		adapt_padding_before(t_flags flags)
{
	t_flags		tmp;

	tmp = flags;
	if (tmp.precision > -1 && tmp.padding_zero)
	{
		tmp.padding_left = tmp.padding_zero;
		tmp.padding_zero = 0;
	}
	if (tmp.precision > 0 && (tmp.padding_zero > tmp.precision)
	&& (tmp.padding_zero > tmp.padding_left))
	{
		tmp.padding_left = tmp.padding_zero;
		tmp.padding_zero = 0;
	}
	return (tmp);
}

int			print_def(t_list *param)
{
	int		ret;

	ret = 0;
	ret += write(1, "%", 1);
	ret += ft_putstr(param->flags);
	ret += write(1, &param->type, 1);
	return (ret);
}
