/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:25:23 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/17 17:34:37 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <philo_data.h>
#include <stdbool.h>
#include <utils.h>
#include <unistd.h>

static bool	philo_take_fork(t_philo *p, t_mutex *fork, bool *hand)
{
	int	lock_ret;

	lock_ret = mutex_trylock(fork);
	while (lock_ret)
	{
		lock_ret = mutex_trylock(fork);
		usleep(1);
		if (!philo_flush(p))
			return (false);
	}
	*hand = true;
	if (lock_ret == -1)
	{
		abort_simulation();
		return (false);
	}
	if (!philo_log(p, "has taken a fork", false))
		return (false);
	return (true);
}

bool	philo_eat(t_philo *p)
{
	time_t	end_eat;

	if (!philo_take_fork(p, p->left, &p->left_hand)
		|| !philo_take_fork(p, p->right, &p->right_hand))
		return (false);
	p->time_last_eat = get_time();
	if (!philo_log(p, "is eating", false))
		return (false);
	++p->eat_cnt;
	end_eat = p->time_last_eat + time_eat() * 1000;
	while (get_time() < end_eat)
	{
		usleep(1);
		if (!philo_flush(p))
			return (false);
	}
	if (mutex_unlock(p->left) == -1 || mutex_unlock(p->right) == -1)
		return (false);
	p->left_hand = false;
	p->right_hand = false;
	return (true);
}

bool	philo_think(t_philo *p)
{
	if (!philo_log(p, "is thinking", false))
		return (false);
	return (true);
}

bool	philo_sleep(t_philo *p)
{
	const time_t	end_sleep = get_time() + time_sleep() * 1000;

	if (!philo_log(p, "is sleeping", false))
		return (false);
	while (get_time() < end_sleep)
	{
		usleep(1);
		if (!philo_flush(p))
			return (false);
	}
	return (true);
}
