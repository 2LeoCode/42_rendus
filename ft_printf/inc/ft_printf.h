/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 15:27:06 by lsuardi           #+#    #+#             */
/*   Updated: 2020/06/02 15:32:03 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef unsigned long long	t_ullong;
typedef enum	e_bool
{
	false,
	true
}				t_bool;
typedef struct	s_list
{
	char			type;
	char			*flags;
	struct s_list	*next;
}				t_list;
typedef struct	s_flags
{
	int		padding_left;
	int		padding_right;
	int		padding_zero;
	int		precision;
}				t_flags;

/*
** main functions
*/
int				ft_printf(const char *format, ...);
int				parse_fmt(const char *fmt, t_list **lst);
int				print_fmt(const char *fmt, va_list ap, t_list *param);

/*
** flag parsing
*/
t_flags			parse_flags(va_list ap, char *flags);
t_flags			init_flag_struct(va_list ap, char *flags);
int				get_zeros(va_list ap, char **flags);
int				get_padding_left(va_list ap, char *flags);

/*
** printing
*/
int				get_len_i(t_flags flags, char *nbr);
void			fill_i(char *to_disp, char *nbr, t_flags flags, int len);
int				free_failure(char **str);
int				print_c(char c, t_flags flags, char *all_flags);
int				print_s(char *str, t_flags flags, char *all_flags);
int				print_i(int n, t_flags flags);
int				print_u(unsigned int n, t_flags flags);
int				print_x(unsigned int n, t_flags flags, t_bool caps);
int				print_p(t_ullong n, t_flags flags);
int				print_def(t_list *param);
t_flags			adapt_padding_before(t_flags flags);

/*
** list functions
*/
t_list			*ft_lstinit(void);
void			ft_lstadd_back(t_list **lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstclear(t_list **lst);

/*
** utils
*/
long			ft_abs(long n);
char			*ft_strchr(const char *str, int c);
t_bool			ft_strfind(const char *str, const char *charset);
int				ft_putstr(const char *str);
size_t			ft_strlen(const char *str);
char			*ft_strndup(const char *str, int n);
int				ft_atoi(const char *str);
t_bool			ft_isalpha(int c);
t_bool			ft_isdigit(int c);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *str);
char			*ft_itoa(int n);
char			*ft_uitoa(unsigned int n);
int				ft_print(char **str);
void			ft_strcapitalize(char *str);
#endif
