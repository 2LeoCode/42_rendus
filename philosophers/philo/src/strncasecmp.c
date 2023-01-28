/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncasecmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:22:30 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/13 20:04:31 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

int	ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i]
		&& ft_toupper(s1[i]) == ft_toupper(s2[i]))
		++i;
	return ((i != n) * ((unsigned char)s1[i] - (unsigned char)s2[i]));
}
