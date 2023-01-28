/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:43:45 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/15 20:04:58 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_data.h>
#include <utils.h>
#include <unistd.h>

int	e_argument_count(const char *exec_name)
{
	write(2, "usage: ", 7);
	write(2, exec_name, ft_strlen(exec_name));
	write(2,
		" <number_of_philosophers> <time_to_die>"
		" <time_to_eat> <time_to_sleep> "
		"[number_of_times_each_philosopher_must_eat]\n", 114);
	return (PHILO_FAILURE);
}

int	e_argument_non_numeric(void)
{
	write(2, "error: positive numeric arguments required\n", 43);
	return (PHILO_FAILURE);
}

int	e_fatal(void)
{
	return (write(2, "error: fatal\n", 13), PHILO_FAILURE);
}
