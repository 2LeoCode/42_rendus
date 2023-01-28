/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:17:48 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/04 17:28:47 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

int	ft_memcmp(const void *m1, const void *m2, size_t n)
{
	const unsigned char	*s1 = m1;
	const unsigned char	*s2 = m2;

	while (*s1 == *s2 && n--)
	{
		++s1;
		++s2;
	}
	return ((n != SIZE_MAX) * (*s1 - *s2));
}
