/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:14:06 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/17 16:42:37 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_data.h>

void	kill_philo(void)
{
	pthread_mutex_lock(&philo_data()->cnt_mut);
	--philo_data()->philo_cnt;
	pthread_mutex_unlock(&philo_data()->cnt_mut);
}

void	start_simulation(void)
{
	pthread_mutex_lock(&philo_data()->stat_mut);
	philo_data()->status = 1;
	pthread_mutex_unlock(&philo_data()->stat_mut);
}

void	stop_simulation(void)
{
	pthread_mutex_lock(&philo_data()->stat_mut);
	philo_data()->status = 0;
	pthread_mutex_unlock(&philo_data()->stat_mut);
}

void	abort_simulation(void)
{
	pthread_mutex_lock(&philo_data()->stat_mut);
	philo_data()->status = -1;
	pthread_mutex_unlock(&philo_data()->stat_mut);
}

int	simulation_status(void)
{
	int	status;

	pthread_mutex_lock(&philo_data()->stat_mut);
	status = philo_data()->status;
	pthread_mutex_unlock(&philo_data()->stat_mut);
	return (status);
}
