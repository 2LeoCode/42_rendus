/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:27:33 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/17 16:40:32 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_DATA_H
# define PHILO_DATA_H

# include <sys/time.h>
# include <mutex.h>

# define PHILO_SUCCESS 0
# define PHILO_FAILURE 1

typedef struct s_mutex	t_mutex;

typedef struct s_philo_data {
	long			philo_cnt;

	time_t			time_die;
	time_t			time_eat;
	time_t			time_sleep;

	time_t			time_begin;
	long			needed_food;

	int				status;

	pthread_mutex_t	rw_mut;
	pthread_mutex_t	log_mut;
	pthread_mutex_t	cnt_mut;
	pthread_mutex_t	stat_mut;
}	t_philo_data;

t_philo_data	*philo_data(void);

long			philo_count(void);
time_t			time_die(void);
time_t			time_eat(void);
time_t			time_sleep(void);
time_t			time_begin(void);
long			needed_food(void);
void			kill_philo(void);

void			start_simulation(void);
void			stop_simulation(void);
void			abort_simulation(void);
int				simulation_status(void);

int				init_philo_data(int argc, char **argv);

int				init_timer(void);

#endif
