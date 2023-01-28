/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 18:42:38 by lsuardi           #+#    #+#             */
/*   Updated: 2020/06/02 15:31:47 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int		flag_len(const char *str)
{
	if (!str || !*str || ft_isalpha(*str) || *str == '%')
		return (0);
	return (1 + flag_len(str + 1));
}

static char		*get_flags(const char *str)
{
	int		len;

	len = flag_len(str);
	return (ft_strndup(str, len));
}

int				parse_fmt(const char *fmt, t_list **lst)
{
	int		count;
	t_list	*current;

	current = ft_lstlast(*lst);
	if (!*fmt)
		return (0);
	if (*fmt == '%')
	{
		if (ft_strchr("-+.*0123456789", *(++fmt)))
		{
			if (!(current->flags = get_flags(fmt)))
				return (-1);
		}
		else
			current->flags = NULL;
		count = flag_len(fmt);
		fmt += count;
		current->type = *fmt;
		if (ft_strchr(fmt, '%'))
			ft_lstadd_back(lst);
	}
	return (*fmt ? parse_fmt(fmt + 1, lst) : 0);
}

static int		print_type(va_list ap, t_list *param)
{
	t_flags	flags;

	flags = parse_flags(ap, param->flags);
	if (param->type == 'c')
		return (print_c(va_arg(ap, int), flags, param->flags));
	if (param->type == 's')
		return (print_s(va_arg(ap, char*), flags, param->flags));
	if (param->type == 'p')
		return (print_p(va_arg(ap, t_ullong), flags));
	if (param->type == 'i' || param->type == 'd')
		return (print_i(va_arg(ap, int), flags));
	if (param->type == 'u')
		return (print_u(va_arg(ap, unsigned int), flags));
	if (param->type == 'x')
		return (print_x(va_arg(ap, unsigned int), flags, false));
	if (param->type == 'X')
		return (print_x(va_arg(ap, unsigned int), flags, true));
	if (param->type == '%')
		return (print_c('%', flags, param->flags));
	if (param->type == 0)
		return (0);
	return (print_def(param));
}

int				print_fmt(const char *fmt, va_list ap, t_list *param)
{
	int		count;

	count = 0;
	while (*fmt && *fmt != '%')
	{
		count += write(1, fmt, 1);
		fmt++;
	}
	if (!*fmt)
		return (count);
	count += print_type(ap, param);
	if (param->flags)
		fmt += ft_strlen(param->flags);
	if (*(++fmt))
		return (count + print_fmt(fmt + 1, ap, param->next));
	return (count);
}
