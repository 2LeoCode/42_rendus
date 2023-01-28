/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_int.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:05:19 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/03/13 16:51:29 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_INT_H
# define PARSING_INT_H

# include "parsing.h"

# define PLAYER_MASK 1
# define EXIT_MASK 2
# define ITEM_MASK 4

t_map	*alloc_map(const char *data);
void	validate_map(t_map *map);

void	expect(char expected, char got);
void	expect_horizontal_walls(t_map *map, int x, int z);
void	expect_vertical_walls(t_map *map, int y, int z);

#endif
