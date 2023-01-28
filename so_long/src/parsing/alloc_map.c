/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:58:38 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 16:51:48 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/game.h"
#include "../memory/memory.h"
#include "../string/string.h"
#include "parsing_int.h"

static void	check_size(int *actual, int new)
{
	if (*actual == -1)
		*actual = new;
	else if (*actual != new)
		invalid_argument();
}

static void	check_begin_layer(bool nl, int *z, int *cur_y)
{
	if (nl)
	{
		++*z;
		*cur_y = 0;
	}
}

static bool	check_end_layer(const char **s, int *y, int cur_y)
{
	skip_space_til(s, '\n');
	expect('\n', *(*s)++);
	while (ft_isspace(**s))
	{
		if (*(*s)++ == '\n')
		{
			check_size(y, cur_y);
			return (true);
		}
	}
	return (false);
}

t_map	*alloc_map(const char *data)
{
	t_map		*m;
	t_vec3		size;
	int			i;
	bool		nl;

	size = (t_vec3){-1, -1, 1};
	i = 0;
	nl = false;
	skip_space(&data);
	while (*data)
	{
		check_begin_layer(nl, &size.z, &i);
		check_size(&size.x, skip_nospace(&data));
		++i;
		nl = check_end_layer(&data, &size.y, i);
		skip_space(&data);
	}
	check_size(&size.y, i);
	m = alloc(sizeof(*m) + size.z * sizeof(*m->data));
	ft_memset(m, 0, sizeof(*m));
	ft_memcpy(m, &size, sizeof(size));
	i = -1;
	while (++i < size.z)
		m->data[i] = alloc(sizeof(char *) * size.y);
	return (m);
}
