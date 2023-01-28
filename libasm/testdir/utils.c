/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:31:30 by user42            #+#    #+#             */
/*   Updated: 2020/12/03 20:48:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"


char	*get_list_data(t_list *lst)
{
	char	*s;
	int		len = 0;
	t_list	*tmp = lst;

	while (tmp)
	{
		len += strlen((char*)tmp->data);
		tmp = tmp->next;
	}
	if (!(s = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s[len] = 0;
	*s = 0;
	while (lst)
	{
		strcat(s, (char*)lst->data);
		lst = lst->next;
	}
	return (s);
}

void	list_push_front(t_list **begin, void *data)
{
	t_list	*new;

	if (!(new = malloc(sizeof(t_list))))
		return ;
	new->data = data;
	new->next = *begin;
	*begin = new;
}

char	*get_strs_data(char **ss)
{
	char	*s;
	int		len = 0;
	char	**tmp;

	tmp = ss;
	while (*tmp)
	{
		len += strlen(*tmp);
		tmp++;
	}
	if (!(s = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s[len] = 0;
	*s = 0;
	while (*ss)
	{
		strcat(s, *ss);
		ss++;
	}
	return (s);
}

int		get_list_size(char *input)
{
	int		size = 0;

	while (*input && (*input - '\n'))
	{
		if (*(input++) == '\"')
		{
			size++;
			while (*(input++) - '\"')
				if (!*(input - 1) || (*(input - 1) == '\n'))
					return (0);
		}
	}
	return (size);
}

char	*ft_strchr(char *haystack, int needle)
{
	while (*haystack)
		if (*(haystack++) == needle)
			return (haystack - 1);
	return (NULL);
}

int		get_next_len(int fd)
{
	char	c;
	int		cnt = 0;
	int		ret;

	while ((ret = read(fd, &c, 1)) > 0)
		if (c == '\"')
		{
			while ((ret = read(fd, &c, 1)) > 0)
			{
				if (c == '\"')
					return (cnt);
				cnt++;
			}
			return (-1);
		}
	return (-1);
}

char	*get_next_str(int fd, int len)
{
	char	c;
	int		ret;
	char	*s;

	if (!(s = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while ((ret = read(fd, &c, 1)) > 0)
		if (c == '\"')
		{
			if ((ret = read(fd, s, len + 1)) < 0)
			{
				free(s);
				return (NULL);
			}
			s[len] = 0;
			return (s);
		}
	return (NULL);
}

int		ft_fputs(int fd, char *s)
{
	return (s ? write(fd, s, strlen(s)) : write(fd, "(null)", 6));
}

t_list	*ft_list_new(void *data)
{
	t_list *newlist = malloc(sizeof(t_list));

	if (!newlist)
		return (NULL);
	newlist->data = data;
	newlist->next = NULL;
	return (newlist);
}

void	ft_strings_disp(int fd, char **s, char *name)
{
	ft_fputs(fd, name);
	ft_fputc(fd, '\n');
	while (*s)
	{
		ft_fputs(fd, "\t\'");
		ft_fputs(fd, (char*)*s);
		ft_fputs(fd, "\'\n"),
		s++;
	}
}

void	ft_list_disp(int fd, t_list *lst, char *lst_name)
{
	ft_fputs(fd, lst_name);
	ft_fputc(fd, '\n');
	while (lst)
	{
		ft_fputs(fd, "\t\'");
		ft_fputs(fd, (char*)lst->data);
		ft_fputs(fd, "\'\n"),
		lst = lst->next;
	}
}

void	ft_list_clear(t_list **lst)
{
	if (!lst || !*lst)
		return ;
	t_list *head = (*lst)->next;
	while (*lst)
	{
		free(*lst);
		*lst = head;
		if (head)
			head = head->next;
	}
}

int		ft_fputc(int fd, unsigned char c)
{
	return (write(fd, &c, 1));
}

int			ft_fputnbr(int fd, int n)
{
	long		nb = (long)n;
	static int	count = 1;

	if (nb < 0)
	{
		count++;
		if (ft_fputc(fd, '-') < 0)
			return (-1);
		nb = -nb;
	}
	if (nb < 10)
	{
		if (ft_fputc(fd, nb + 48) < 0)
			return (-1);
		return (count);
	}
	else
	{
		count++;
		if ((ft_fputnbr(fd, (int)(nb / 10)) < 0) || (ft_fputnbr(fd, (int)(nb % 10)) < 0))
			return (-1);
	}
	return (0);
}

char	*ft_strcdup(char *s, int c)
{
	char	*dup;
	int		len = 0;

	while (s[len] && (s[len] - c))
		len++;
	if (!(dup = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dup[len] = 0;
	return (strncpy(dup, s, len));
}

int		ft_fputzu(int fd, unsigned long n)
{
	static int	count = 1;

	if (n < 10)
	{
		if (ft_fputc(fd, n + 48) < 0)
			return (-1);
		return (count);
	}
	else 
	{
		count++;
		if ((ft_fputzu(fd, n / 10) < 0) || (ft_fputzu(fd, n % 10) < 0))
			return (-1);
	}
	return (0);
}

int		ft_isdigit(char c)
{
	return ((c >= '0') && (c <= '9'));
}

int		ft_isspace(char c)
{
	return (((c >= '\t') && (c <= '\r')) || (c == ' '));
}

char	*get_file(char *path)
{
	int		fdLen = open(path, O_RDONLY);
	int		fdRd = open(path, O_RDONLY);
	char	*s;
	int		len = 0;
	char	c;
	int		ret;

	if ((fdLen < 0) || (fdRd < 0))
		return (NULL);
	while ((ret = read(fdLen, &c, 1)) > 0)
		len++;
	if ((ret < 0) || !(s = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	read(fdRd, s, len);
	s[len] = 0;
	return (s);
}

int		checkBase(char *base)
{
	int i = -1;

	while (base[++i])
		if (ft_strchr(&base[i + 1], base[i]) || ft_isspace(base[i])
		|| (base[i] == '+') || (base[i] == '-'))
			return (0);
	return (i);
}

int		ft_atoi_base_test(char *s, char *base)
{
	int		i = 0, size;
	void	*indexptr;
	long	nb = 0, neg = 1;

	if (!(size = checkBase(base)))
		return (0);
	while (ft_isspace(s[i]))
		i++;
	while ((s[i] == '+') || (s[i] == '-'))
		neg = (s[i++] == '-') ? -neg : neg;
	while (s[i])
	{
		if (!(indexptr = ft_strchr(base, s[i])))
			break ;
		nb = nb * size + (int)((char*)indexptr - base);
		i++;
	}
	return ((int)(neg * nb));
}

void	ft_sort_strs(char **ss, int	(*cmp)())
{
	char	**to_comp;
	char	*tmp;

	while (*ss)
	{
		to_comp = ss;
		while (*(++to_comp))
		{
			if ((*cmp)(*ss, *to_comp) > 0)
			{
				tmp = *to_comp;
				*to_comp = *ss;
				*ss = tmp;
			}
		}
		ss++;
	}
}

void	ft_strs_remove_if(char **ss, char *data_ref, int (*cmp)())
{
	int		i;

	while (*ss)
	{
		if (!(*cmp)(data_ref, *ss))
		{
			free(*ss);
			i = 0;
			while (ss[++i])
				ss[i - 1] = ss[i];
			ss[i - 1] = NULL;
		}
		else
			ss++;
	}
}
