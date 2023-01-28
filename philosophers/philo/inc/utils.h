/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:02:40 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/17 17:19:04 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <sys/time.h>
# include <stddef.h>

time_t	get_time(void);
long	ft_strtol(const char *nptr, char **endptr, int base);
int		ft_toupper(int c);
int		ft_isspace(int c);
int		ft_strncasecmp(const char *s1, const char *s2, size_t n);
char	*ft_ltoa(char *s_ptr, long n);
char	*ft_stpcpy(char *dst, const char *src);
size_t	ft_strlen(const char *s);
int		ft_islower(int c);

#endif
