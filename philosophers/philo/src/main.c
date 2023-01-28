/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:04:03 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/17 17:36:33 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_data.h>
#include <philo.h>
#include <memory.h>
#include <unistd.h>
#include <mutex.h>

static int	build_philos(int philo_cnt)
{
	t_mutex	**forks;
	int		i;

	forks = allocate(philo_count() * sizeof(*forks));
	if (!forks)
		return (PHILO_FAILURE);
	i = -1;
	while (++i < philo_cnt)
	{
		forks[i] = mutex_init();
		if (!forks[i])
			return (PHILO_FAILURE);
	}
	while (i--)
		if (philo_init(forks[i], forks[(i + 1) % philo_data()->philo_cnt]))
			return (PHILO_FAILURE);
	return (PHILO_SUCCESS);
}

int	main(int argc, char **argv)
{
	if (init_philo_data(argc, argv) == PHILO_FAILURE
		|| build_philos(philo_data()->philo_cnt) == PHILO_FAILURE
		|| init_timer() == PHILO_FAILURE)
		return (-1);
	start_simulation();
	while (philo_count())
		usleep(0xDEAD);
	mutex_clear();
	memory_clear();
	return (0);
}
