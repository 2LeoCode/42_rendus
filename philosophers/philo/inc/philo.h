/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:03:21 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/17 17:34:48 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct s_mutex	t_mutex;

typedef struct s_philo {
	unsigned int	id;
	pthread_t		thread_data;

	time_t			time_last_eat;
	long			eat_cnt;

	t_mutex			*left;
	t_mutex			*right;
	bool			left_hand;
	bool			right_hand;
}	t_philo;

int		philo_init(t_mutex *left, t_mutex *right);
void	*philo_routine(void *data);
bool	philo_flush(t_philo *p);
bool	philo_log(t_philo *p, const char *msg, bool recurse);

#endif
