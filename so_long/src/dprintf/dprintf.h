/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dprintf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:08:39 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/04 17:31:10 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DPRINTF_H
# define DPRINTF_H

# define DPRINTF_FD_LIMIT 1024
# define DPRINTF_BUFFER_SIZE 2048

int	ft_dprintf(int fd, const char *fmt, ...);
int	ft_dflush(int fd);

#endif
