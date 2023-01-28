/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:49:50 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/17 18:43:01 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mutex.h>

int	mutex_trylock(t_mutex *m)
{
	if (pthread_mutex_lock(&m->prot))
		return (-1);
	if (!m->locked)
	{
		m->locked = true;
		if (pthread_mutex_lock(&m->data)
			|| pthread_mutex_unlock(&m->prot))
			return (-1);
		return (0);
	}
	if (pthread_mutex_unlock(&m->prot))
		return (-1);
	return (1);
}

int	mutex_unlock(t_mutex *m)
{
	if (pthread_mutex_lock(&m->prot))
		return (-1);
	if (m->locked)
	{
		m->locked = false;
		if (pthread_mutex_unlock(&m->data)
			|| pthread_mutex_unlock(&m->prot))
			return (-1);
		return (0);
	}
	return (!pthread_mutex_unlock(&m->prot));
}
