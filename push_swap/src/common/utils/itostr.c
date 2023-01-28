/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itostr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:42:08 by lsuardi           #+#    #+#             */
/*   Updated: 2021/10/09 23:26:12 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	ft_itostr(int n, char str[12])
{
	int	i;

	i = number_size(n);
	str[i] = 0;
	if (n < 0)
		*str = '-';
	else if (n == 0)
		*str = '0';
	while (n)
	{
		str[--i] = ft_abs(n % 10) + '0';
		n /= 10;
	}
}
