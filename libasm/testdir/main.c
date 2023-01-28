/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:18:16 by user42            #+#    #+#             */
/*   Updated: 2020/12/03 21:18:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void			test_all()
{
	test_ft_strlen();
	test_ft_strcpy();
	test_ft_strcmp();
	test_ft_write();
	test_ft_read();
	test_ft_strdup();
	test_ft_atoi_base();
	test_ft_list_push_front();
	test_ft_list_size();
	test_ft_list_sort();
	test_ft_list_remove_if();
}

unsigned int	check_args(int ac, char **av)
{
	unsigned int check = 0;

	while (ac--)
		if (!strcmp(av[ac], "ft_strlen"))
			check |= 1;
		else if (!strcmp(av[ac], "ft_strcpy"))
			check |= (1 << 1);
		else if (!strcmp(av[ac], "ft_strcmp"))
			check |= (1 << 2);
		else if (!strcmp(av[ac], "ft_write"))
			check |= (1 << 3);
		else if (!strcmp(av[ac], "ft_read"))
			check |= (1 << 4);
		else if (!strcmp(av[ac], "ft_strdup"))
			check |= (1 << 5);
		else if (!strcmp(av[ac], "ft_atoi_base"))
			check |= (1 << 6);
		else if (!strcmp(av[ac], "ft_list_push_front"))
			check |= (1 << 7);
		else if (!strcmp(av[ac], "ft_list_size"))
			check |= (1 << 8);
		else if (!strcmp(av[ac], "ft_list_sort"))
			check |= (1 << 9);
		else if (!strcmp(av[ac], "ft_list_remove_if"))
			check |= (1 << 10);
		else if (!strcmp(av[ac], "clean"))
			return (1 << 11);
	return (check);
}

int				main(int argc, char **argv)
{
	unsigned int check = check_args(argc - 1, argv + 1);

	if (argc == 1)
		test_all();
	else
	{
		if (!(check & ((1 << 12) - 1)))
		{
			printf("Wrong argument(s).\n\
			\rUsage: ./test <function_1> <function_2> <...>\n\
			\r(\'./test clean\' to remove output files)\n\
			\rAvailable functions:\n\
			\r\tft_strlen\n\
			\r\tft_strcpy\n\
			\r\tft_strcmp\n\
			\r\tft_write\n\
			\r\tft_read\n\
			\r\tft_strdup\n\
			\r\tft_atoi_base\n\
			\r\tft_list_push_front\n\
			\r\tft_list_size\n\
			\r\tft_list_sort\n\
			\r\tft_list_remove_if\n");
				return (-1);
		}
		if (check == (1 << 11))
		{
			remove("tests/ft_strlen_output.log");
			remove("tests/ft_strcpy_output.log");
			remove("tests/ft_strcmp_output.log");
			remove("tests/ft_write_output.log");
			remove("tests/ft_read_output.log");
			remove("tests/ft_strdup_output.log");
			remove("tests/ft_atoi_base_output.log");
			remove("tests/ft_list_push_front_output.log");
			remove("tests/ft_list_size_output.log");
			remove("tests/ft_list_sort_output.log");
			remove("tests/ft_list_remove_if_output.log");
			printf("Removed output file(s).\n");
			return (0);
		}
		if (check & 1)
			test_ft_strlen();
		if (check & (1 << 1))
			test_ft_strcpy();
		if (check & (1 << 2))
			test_ft_strcmp();
		if (check & (1 << 3))
			test_ft_write();
		if (check & (1 << 4))
			test_ft_read();
		if (check & (1 << 5))
			test_ft_strdup();
		if (check & (1 << 6))
			test_ft_atoi_base();
		if (check & (1 << 7))
			test_ft_list_push_front();
		if (check & (1 << 8))
			test_ft_list_size();
		if (check & (1 << 9))
			test_ft_list_sort();
		if (check & (1 << 10))
			test_ft_list_remove_if();
	}
	printf("Test(s) done, output file(s) successfully generated in ./tests folder.\n(Look for .log files)\n");
	return (0);
}
