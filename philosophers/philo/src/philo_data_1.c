/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:04:56 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/17 18:45:28 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_data.h>
#include <error_cases.h>
#include <utils.h>
#include <errno.h>
#include <mutex.h>
#include <list.h>

time_t	time_begin(void)
{
	return (philo_data()->time_begin);
}

long	needed_food(void)
{
	return (philo_data()->needed_food);
}

static int	init_global_mutex(t_philo_data *p_data)
{
	if (pthread_mutex_init(&p_data->rw_mut, NULL)
		|| pthread_mutex_init(&p_data->log_mut, NULL)
		|| pthread_mutex_init(&p_data->cnt_mut, NULL)
		|| pthread_mutex_init(&p_data->stat_mut, NULL)
		|| list_push(mutex_list(), &p_data->rw_mut)
		|| list_push(mutex_list(), &p_data->log_mut)
		|| list_push(mutex_list(), &p_data->cnt_mut)
		|| list_push(mutex_list(), &p_data->stat_mut))
		return (-1);
	return (0);
}

int	init_philo_data(int argc, char **argv)
{
	t_philo_data	*p_data;

	p_data = philo_data();
	if (argc != 5 && argc != 6)
		return (e_argument_count(*argv));
	errno = 0;
	p_data->philo_cnt = ft_strtol(argv[1], argv + 1, 0);
	p_data->time_die = ft_strtol(argv[2], argv + 2, 0);
	p_data->time_eat = ft_strtol(argv[3], argv + 3, 0);
	p_data->time_sleep = ft_strtol(argv[4], argv + 4, 0);
	p_data->needed_food = -1;
	if (argc == 6)
		p_data->needed_food = ft_strtol(argv[5], argv + 5, 0);
	if (errno || p_data->philo_cnt < 0 || p_data->time_die < 0
		|| p_data->time_eat < 0 || p_data->time_sleep < 0
		|| *argv[1] || *argv[2] || *argv[3] || *argv[4]
		|| (argc == 6 && (p_data->needed_food < 0 || *argv[5])))
		return (e_argument_non_numeric());
	if (init_global_mutex(p_data))
		return (e_fatal());
	philo_data()->status = 0;
	return (PHILO_SUCCESS);
}

int	init_timer(void)
{
	philo_data()->time_begin = get_time();
	if (philo_data()->time_begin == -1)
		return (PHILO_FAILURE);
	return (PHILO_SUCCESS);
}
