/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:12:04 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/17 18:42:52 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_data.h>
#include <philo_actions.h>
#include <error_cases.h>
#include <mutex.h>
#include <philo.h>
#include <unistd.h>
#include <memory.h>
#include <utils.h>
#include <stdlib.h>

void	*philo_routine(void *data)
{
	t_philo	*p;

	p = data;
	while (simulation_status() == 0)
		usleep(1);
	if (simulation_status() == -1)
		return (NULL);
	p->time_last_eat = time_begin();
	usleep(!(p->id % 2) * 100 * philo_count());
	while (philo_eat(p) && philo_sleep(p) && philo_think(p))
		continue ;
	if (p->left_hand)
		mutex_unlock(p->left);
	if (p->right_hand)
		mutex_unlock(p->right);
	kill_philo();
	return (NULL);
}

int	philo_init(t_mutex *left, t_mutex *right)
{
	static int	id = 0;
	t_philo		*p;

	p = allocate(sizeof(t_philo));
	if (!p)
	{
		abort_simulation();
		return (PHILO_FAILURE);
	}
	p->eat_cnt = 0;
	p->time_last_eat = 0;
	p->id = ++id;
	p->left = left;
	p->right = right;
	p->left_hand = false;
	p->right_hand = false;
	if (pthread_create(&p->thread_data, NULL, philo_routine, p)
		|| pthread_detach(p->thread_data))
	{
		abort_simulation();
		mutex_clear();
		memory_clear();
		return (e_fatal());
	}
	return (PHILO_SUCCESS);
}

bool	philo_log(t_philo *p, const char *info, bool recurse)
{
	time_t			timestamp;
	char			log[59];
	char			*ptr;

	if (!recurse && pthread_mutex_lock(&philo_data()->log_mut))
		return (false);
	timestamp = get_time() / 1000 - philo_data()->time_begin / 1000;
	ptr = log;
	ptr = ft_ltoa(ptr, timestamp);
	*ptr++ = ' ';
	ptr = ft_ltoa(ptr, (long)p->id);
	*ptr++ = ' ';
	ptr = ft_stpcpy(ptr, info);
	*ptr++ = '\n';
	if ((!recurse && !philo_flush(p))
		|| pthread_mutex_lock(&philo_data()->rw_mut))
	{
		pthread_mutex_unlock(&philo_data()->log_mut);
		return (false);
	}
	write(1, log, ptr - log);
	if (pthread_mutex_unlock(&philo_data()->rw_mut)
		|| (!recurse && pthread_mutex_unlock(&philo_data()->log_mut)))
		return (false);
	return (true);
}

bool	philo_flush(t_philo *p)
{
	if (needed_food() != -1 && p->eat_cnt == needed_food())
		return (false);
	if (simulation_status() <= 0)
		return (false);
	if ((get_time() - p->time_last_eat) > time_die() * 1000)
	{
		pthread_mutex_lock(&philo_data()->stat_mut);
		if (philo_data()->status == 1)
		{
			philo_data()->status = 0;
			philo_log(p, "died", true);
		}
		pthread_mutex_unlock(&philo_data()->stat_mut);
		return (false);
	}
	return (true);
}
