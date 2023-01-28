/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cases.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:06:41 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/13 19:31:48 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_CASES_H
# define ERROR_CASES_H

int	e_argument_count(const char *exec_name);
int	e_argument_non_numeric(void);
int	e_fatal(void);

#endif
