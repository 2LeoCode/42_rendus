/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:46:24 by user42            #+#    #+#             */
/*   Updated: 2020/11/30 19:02:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TEST__
# define __TEST__

# include "../inc_bonus/libasm_bonus.h"
# include "../inc/libasm.h"
# include <time.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>

int		ft_fputc(int fd, unsigned char c);
int		ft_fputnbr(int fd, int n);
int		ft_fputzu(int fd, unsigned long n);
void	ft_list_clear(t_list **lst);
void	ft_list_disp(int fd, t_list *lst, char *lst_name);
t_list	*ft_list_new(void *data);
int		ft_fputs(int fd, char *s);
char	*get_next_str(int fd, int len);
int		ft_atoi_base_test(char *s, char *base);
void	ft_strings_disp(int fd, char **s, char *name);
char	*ft_strcdup(char *s, int c);
void	list_push_front(t_list **begin, void *data);
int		get_next_len(int fd);
int		ft_isdigit(char c);
int		ft_isspace(char c);
char	*get_file(char *path);
void	test_ft_strlen(void);
void	test_ft_strcpy(void);
void	test_ft_strcmp(void);
void	test_ft_write(void);
void	test_ft_read(void);
void	test_ft_strdup(void);
void	test_ft_atoi_base(void);
void	test_ft_list_push_front(void);
void	test_ft_list_size(void);
void	test_ft_list_sort(void);
void	test_ft_list_remove_if(void);
int		get_list_size(char *input);
char	*get_list_data(t_list *lst);
char	*get_strs_data(char **ss);
void	ft_sort_strs(char **ss, int	(*cmp)());
void	ft_strs_remove_if(char **ss, char *data_ref, int (*cmp)());

#endif
