/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:49:35 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 00:31:49 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_string
{
	size_t	size;
	size_t	cap;
	char	c[];
}	t_string;

size_t		ft_strlen(const char *s);
void		*ft_memset(void *s, int c, size_t n);
int			ft_memcmp(const void *m1, const void *m2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strchr(const char *s, int c);
bool		ft_isspace(int c);

t_string	*string_alloc(size_t size);
void		string_realloc(t_string **s, size_t new_cap);
void		string_append(t_string **dst, const char *src);

size_t		skip_space(const char **s);
size_t		skip_nospace(const char **s);
size_t		skip_space_til(const char **s, int endc);

#endif
