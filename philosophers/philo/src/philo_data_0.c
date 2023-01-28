/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:54:11 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/17 18:45:40 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_data.h>

t_philo_data	*philo_data(void)
{
	static t_philo_data	data;

	return (&data);
}

time_t	time_die(void)
{
	return (philo_data()->time_die);
}

time_t	time_eat(void)
{
	return (philo_data()->time_eat);
}

time_t	time_sleep(void)
{
	return (philo_data()->time_sleep);
}

long	philo_count(void)
{
	long	count;

	pthread_mutex_lock(&philo_data()->cnt_mut);
	count = philo_data()->philo_cnt;
	pthread_mutex_unlock(&philo_data()->cnt_mut);
	return (count);
}
