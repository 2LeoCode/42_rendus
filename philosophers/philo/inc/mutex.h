/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:19:32 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/17 17:15:45 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEX_H
# define MUTEX_H

# include <pthread.h>
# include <stdbool.h>
# include "list.h"

typedef struct s_mutex {
	pthread_mutex_t	data;
	pthread_mutex_t	prot;
	bool			locked;
}	t_mutex;

t_list	**mutex_list(void);

t_mutex	*mutex_init(void);
int		mutex_lock(t_mutex *m);
int		mutex_trylock(t_mutex *m);
int		mutex_unlock(t_mutex *m);
void	mutex_clear(void);

#endif
