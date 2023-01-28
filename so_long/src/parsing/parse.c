/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 09:00:28 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 16:13:58 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../string/string.h"
#include "../memory/memory.h"
#include "parsing_int.h"

#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#include <unistd.h>

static t_string	*get_file_data(const char *filename)
{
	const int	fd = open(filename, O_RDONLY);
	t_string	*data;
	char		buf[SL_BUFFER_SIZE + 1];
	int			ret;

	if (fd == -1)
		ft_abort();
	ret = read(fd, buf, SL_BUFFER_SIZE);
	data = string_alloc(SL_BUFFER_SIZE + 1);
	while (ret)
	{
		if (ret == -1)
			ft_abort();
		buf[ret] = 0;
		string_append(&data, buf);
		ret = read(fd, buf, SL_BUFFER_SIZE);
	}
	return (data);
}

char	*next_token(char **s)
{
	char	*ptr;
	size_t	len;
	char	*begin;

	while (ft_isspace(**s))
		++*s;
	begin = *s;
	while (!ft_isspace(**s))
		++*s;
	len = *s - begin;
	ptr = alloc(sizeof(char) * (len + 1));
	ft_memcpy(ptr, begin, len);
	ptr[len] = 0;
	return (ptr);
}

t_map	*sl_parse(const char *filename)
{
	int			i;
	int			j;
	t_string	*file_str;
	char		*ptr;
	t_map		*map;

	file_str = get_file_data(filename);
	map = alloc_map(file_str->c);
	ptr = file_str->c;
	i = -1;
	while (++i < map->z)
	{
		j = -1;
		while (++j < map->y)
			map->data[i][j] = next_token(&ptr);
	}
	dealloc(file_str);
	validate_map(map);
	return (map);
}
