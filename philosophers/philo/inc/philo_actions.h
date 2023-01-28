/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:01:26 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/13 20:05:02 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ACTIONS_H
# define PHILO_ACTIONS_H

# include <philo.h>
# include <stdbool.h>

bool	philo_eat(t_philo *p);
bool	philo_think(t_philo *p);
bool	philo_sleep(t_philo *p);

#endif
