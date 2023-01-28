/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:28:22 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/05 15:29:03 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}