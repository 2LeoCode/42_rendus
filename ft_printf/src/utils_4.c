/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 18:38:46 by lsuardi           #+#    #+#             */
/*   Updated: 2020/05/28 15:26:44 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_putstr(const char *str)
{
	if (!str)
		return (ft_putstr("(null)"));
	if (!*str)
		return (0);
	write(1, str, 1);
	return (1 + ft_putstr(str + 1));
}

char	*ft_strcpy(char *dst, const char *src)
{
	*dst = *src;
	if (!*src)
		return (dst);
	return (ft_strcpy(dst + 1, src + 1) - 1);
}

char	*ft_strdup(const char *str)
{
	char	*new;

	new = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	return (ft_strcpy(new, str));
}

int		ft_print(char **str)
{
	int	len;

	len = ft_putstr(*str);
	free(*str);
	str = NULL;
	return (len);
}

void	ft_strcapitalize(char *str)
{
	if (!*str)
		return ;
	if (*str >= 'a' && *str <= 'z')
		*str -= 32;
	ft_strcapitalize(str + 1);
}
