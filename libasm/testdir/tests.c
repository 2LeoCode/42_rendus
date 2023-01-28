/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:37:03 by user42            #+#    #+#             */
/*   Updated: 2020/12/03 20:50:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void			test_ft_strlen(void)
{
	int				fdInput = open("tests/ft_strlen_input.txt", O_RDONLY);
	int				fdLenCheck = open("tests/ft_strlen_input.txt", O_RDONLY);
	int				fdOutput = open("tests/ft_strlen_output.log", O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
	size_t			testRet;
	size_t			realRet;
	char			*s;
	int				len;
	struct timespec	before;
	struct timespec after;
	unsigned long	time_real;
	unsigned long	time_test;
	time_t			time_begin = time(NULL);

	if ((fdInput < 0) || (fdLenCheck < 0) || (fdOutput < 0)
	|| (write(fdOutput, "[", 1) < 0)
	|| (write(fdOutput, ctime(&time_begin), 24) < 0)
	|| (ft_fputs(fdOutput, "]ft_strlen\n\n") < 0))
	{
		ft_fputs(2, "Error\n");
		return ;
	}
	while ((len = get_next_len(fdLenCheck)) >= 0)
	{
		if (!(s = get_next_str(fdInput, len)))
		{
			ft_fputs(2, "Error\n");
			ft_fputs(fdOutput, "-------------------------MEMORY ERROR-------------------------\n");
			return ;
		}
		if (!timespec_get(&before, TIME_UTC))
			return ;
		testRet = ft_strlen(s);
		if (!timespec_get(&after, TIME_UTC))
			return ;
		time_test = (after.tv_nsec - before.tv_nsec);
		if (!timespec_get(&before, TIME_UTC))
			return ;
		realRet = strlen(s);
		if (!timespec_get(&after, TIME_UTC))
			return ;
		time_real = (after.tv_nsec - before.tv_nsec);
		if ((write(fdOutput, "\"", 1) < 0)
		|| (ft_fputs(fdOutput, s) < 0)
		|| (ft_fputs(fdOutput, "\"\n") < 0))
		free(s);
		if (testRet == realRet)
		{
			if (ft_fputs(fdOutput, "\t[OK]") < 0)
				return ;
		}
		else if (ft_fputs(fdOutput, ">>>>[KO]<<<<") < 0)
			return ;
		if ((ft_fputs(fdOutput, "\n\nExpected:\t") < 0)
		|| (ft_fputzu(fdOutput, realRet) < 0)
		|| (ft_fputs(fdOutput, " (") < 0)
		|| (ft_fputzu(fdOutput, time_real) < 0)
		|| (ft_fputs(fdOutput, "ns)\nGot:\t\t") < 0)
		|| (ft_fputzu(fdOutput, testRet) < 0)
		|| (ft_fputs(fdOutput, " (") < 0)
		|| (ft_fputzu(fdOutput, time_test) < 0)
		|| (ft_fputs(fdOutput, "ns)\n\n\n") < 0))
			return ;
	}
	s = NULL;
	close(fdInput);
	close(fdLenCheck);
	close(fdOutput);
}

void			test_ft_strcpy(void)
{
	int				fdInput = open("tests/ft_strcpy_input.txt", O_RDONLY);
	int				fdLenCheck = open("tests/ft_strcpy_input.txt", O_RDONLY);
	int				fdOutput = open("tests/ft_strcpy_output.log", O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR);
	char			real[3000] = {0}, test[3000] = {0};
	char			*testRet;
	char			*realRet;
	char			*s;
	int				len;
	struct timespec	before;
	struct timespec after;
	unsigned long	time_real;
	unsigned long	time_test;
	time_t			time_begin = time(NULL);

	if ((fdInput < 0) || (fdLenCheck < 0) || (fdOutput < 0)
	|| (write(fdOutput, "[", 1) < 0)
	|| (write(fdOutput, ctime(&time_begin), 24) < 0)
	|| (ft_fputs(fdOutput, "]ft_strcpy\n\n") < 0))
	{
		ft_fputs(2, "Error\n");
		return ;
	}
	while ((len = get_next_len(fdLenCheck)) >= 0)
	{
		if (!(s = get_next_str(fdInput, len)))
		{
			ft_fputs(2, "Error\n");
			ft_fputs(fdOutput, "-------------------------MEMORY ERROR-------------------------\n");
			return ;
		}
		if ((write(fdOutput, "\"", 1) < 0)
		|| (ft_fputs(fdOutput, test) < 0)
		|| (ft_fputs(fdOutput, "\" <--- \"") < 0)
		|| (ft_fputs(fdOutput, s) < 0)
		|| (ft_fputs(fdOutput, "\"\n") < 0))
			return ;
		if (!timespec_get(&before, TIME_UTC))
			return ;
		testRet = ft_strcpy(test, s);
		if (!timespec_get(&after, TIME_UTC))
			return ;
		time_test = (after.tv_nsec - before.tv_nsec);
		if (!timespec_get(&before, TIME_UTC))
			return ;
		realRet = strcpy(real, s);
		if (!timespec_get(&after, TIME_UTC))
			return ;
		time_real = (after.tv_nsec - before.tv_nsec);
		strcpy(test, s);
		free(s);
		if (!strcmp(test, real) && !strcmp(testRet, realRet))
		{
			if (ft_fputs(fdOutput, "\t[OK]") < 0)
				return ;
		}
		else if (ft_fputs(fdOutput, ">>>>[KO]<<<<") < 0)
			return ;
		if ((ft_fputs(fdOutput, "\n\nExpected:\t\"") < 0)
		|| (ft_fputs(fdOutput, real) < 0)
		|| (ft_fputs(fdOutput, "\"\nRet:\t\t\"") < 0)
		|| (ft_fputs(fdOutput, realRet) < 0)
		|| (ft_fputs(fdOutput, "\"\n(") < 0)
		|| (ft_fputzu(fdOutput, time_real) < 0)
		|| (ft_fputs(fdOutput, "ns)\nGot:\t\t\"") < 0)
		|| (ft_fputs(fdOutput, test) < 0)
		|| (ft_fputs(fdOutput, "\"\nRet:\t\t\"") < 0)
		|| (ft_fputs(fdOutput, testRet) < 0)
		|| (ft_fputs(fdOutput, "\"\n(") < 0)
		|| (ft_fputzu(fdOutput, time_test) < 0)
		|| (ft_fputs(fdOutput, "ns)\n\n\n") < 0))
			return ;
	}
	close(fdInput);
	close(fdLenCheck);
	close(fdOutput);
}

void			test_ft_strcmp(void)
{
	int				fdInput = open("tests/ft_strcmp_input.txt", O_RDONLY);
	int				fdLenCheck = open("tests/ft_strcmp_input.txt", O_RDONLY);
	int				fdOutput = open("tests/ft_strcmp_output.log", O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR);
	int				testRet;
	int				realRet;
	char			*s1;
	char			*s2;
	int				len1;
	int				len2;
	char			c = 1;
	struct timespec	before;
	struct timespec after;
	unsigned long	time_real;
	unsigned long	time_test;
	time_t			time_begin = time(NULL);

	if ((fdInput < 0) || (fdLenCheck < 0) || (fdOutput < 0)
	|| (write(fdOutput, "[", 1) < 0)
	|| (write(fdOutput, ctime(&time_begin), 24) < 0)
	|| (ft_fputs(fdOutput, "]ft_strcmp\n\n") < 0))
	{
		ft_fputs(2, "Error\n");
		return ;
	}
	while (((len1 = get_next_len(fdLenCheck)) >= 0) && ((len2 = get_next_len(fdLenCheck)) >= 0))
	{
		if (!(s1 = get_next_str(fdInput, len1)) || !(s2 = get_next_str(fdInput, len2)))
		{
			if (s1)
				free(s1);
			s1 = NULL;
			ft_fputs(2, "Error\n");
			ft_fputs(fdOutput, "-------------------------MEMORY ERROR-------------------------\n");
			return ;
		}
		if ((write(fdOutput, "\"", 1) < 0)
		|| (ft_fputs(fdOutput, s1) < 0)
		|| (ft_fputs(fdOutput, "\" \"") < 0)
		|| (ft_fputs(fdOutput, s2) < 0)
		|| (ft_fputs(fdOutput, "\"\n") < 0))
			return ;
		if (!timespec_get(&before, TIME_UTC))
			return ;
		testRet = ft_strcmp(s1, s2);
		if (!timespec_get(&after, TIME_UTC))
			return ;
		time_test = (after.tv_nsec - before.tv_nsec);
		if (!timespec_get(&before, TIME_UTC))
			return ;
		realRet = strcmp(s1, s2);
		if (!timespec_get(&after, TIME_UTC))
			return ;
		time_real = (after.tv_nsec - before.tv_nsec);
		free(s1);
		free(s2);
		if (testRet == realRet)
		{
			if (ft_fputs(fdOutput, "\t[OK]") < 0)
				return ;
		}
		else if (ft_fputs(fdOutput, ">>>>[KO]<<<<") < 0)
			return ;
		if ((ft_fputs(fdOutput, "\n\nExpected:\t") < 0)
		|| (ft_fputnbr(fdOutput, realRet) < 0)
		|| (ft_fputs(fdOutput, " (") < 0)
		|| (ft_fputzu(fdOutput, time_real) < 0)
		|| (ft_fputs(fdOutput, "ns)\nGot:\t\t") < 0)
		|| (ft_fputnbr(fdOutput, testRet) < 0)
		|| (ft_fputs(fdOutput, " (") < 0)
		|| (ft_fputzu(fdOutput, time_test) < 0)
		|| (ft_fputs(fdOutput, "ns)\n\n\n") < 0))
			return ;
	}
	s1 = NULL;
	s2 = NULL;
	close(fdInput);
	close(fdLenCheck);
	close(fdOutput);
}

void			test_ft_write(void)
{
	int				fdInput = open("tests/ft_write_input.txt", O_RDONLY);
	int				fdLenCheck = open("tests/ft_write_input.txt", O_RDONLY);
	int				fdOutput = open("tests/ft_write_output.log", O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR);
	int				fdTest = open(".writetest", O_WRONLY | O_TRUNC);
	int				fdCheck = open(".writetest", O_RDONLY);
	int				testRet;
	int				realRet;
	int				testErrno;
	int				realErrno;
	char			*s;
	char			*check;
	int				len;
	char			c = 1;
	struct timespec	before;
	struct timespec after;
	unsigned long	time_real;
	unsigned long	time_test;
	time_t			time_begin = time(NULL);

	if ((fdInput < 0) || (fdLenCheck < 0) || (fdOutput < 0) || (fdCheck < 0) || (fdTest < 0)
	|| (write(fdOutput, "[", 1) < 0)
	|| (write(fdOutput, ctime(&time_begin), 24) < 0)
	|| (ft_fputs(fdOutput, "]ft_write\n\n") < 0)
	|| (ft_fputs(fdOutput, "Normal file\n\n") < 0))
	{
		ft_fputs(2, "Error\n");
		return ;
	}
	while ((len = get_next_len(fdLenCheck)) >= 0)
	{
		if (!(s = get_next_str(fdInput, len)))
		{
			ft_fputs(2, "Error\n");
			ft_fputs(fdOutput, "-------------------------MEMORY ERROR-------------------------\n");
			return ;
		}
		if (!timespec_get(&before, TIME_UTC))
			return ;
		if ((testRet = ft_write(fdTest, s, strlen(s))) < 0)
			testErrno = errno;
		else
			testErrno = 0;
		if (!timespec_get(&after, TIME_UTC))
			return ;
		time_test = (after.tv_nsec - before.tv_nsec);
		if (!timespec_get(&before, TIME_UTC))
			return ;
		if ((realRet = write(fdTest, s, strlen(s))) < 0)
			realErrno = errno;
		else
			realErrno = 0;
		if (!timespec_get(&after, TIME_UTC))
			return ;
		if (write(fdTest, "\n", 1) < 0)
			return ;
		time_real = (after.tv_nsec - before.tv_nsec);
		if (!(check = (char*)malloc(sizeof(char) * (len + 1))))
		{
			ft_fputs(2, "Error\n");
			ft_fputs(fdOutput, "-------------------------MEMORY ERROR-------------------------\n");
			return ;
		}
		if ((read(fdCheck, check, len) < 0)
		|| (lseek(fdCheck, len + 1, SEEK_CUR) < 0))
			return ;
		check[len] = 0;
		if ((write(fdOutput, "\"", 1) < 0)
		|| (ft_fputs(fdOutput, s) < 0)
		|| (ft_fputs(fdOutput, "\"\n") < 0))
			return ;
		if ((testRet == realRet) && (testErrno == realErrno) && !strcmp(s, check))
		{
			if (ft_fputs(fdOutput, "\t[OK]") < 0)
				return ;
		}
		else if (ft_fputs(fdOutput, ">>>>[KO]<<<<") < 0)
			return ;
		if ((ft_fputs(fdOutput, "\n\nExpected:\t\"") < 0)
		|| (ft_fputs(fdOutput, s) < 0)
		|| (ft_fputs(fdOutput, "\"\nRet:\t\t") < 0)
		|| (ft_fputnbr(fdOutput, realRet) < 0)
		|| (ft_fputs(fdOutput, "\nErrno:\t\t") < 0)
		|| (ft_fputs(fdOutput, strerror(realErrno)) < 0)
		|| (ft_fputs(fdOutput, "\n(") < 0)
		|| (ft_fputzu(fdOutput, time_real) < 0)
		|| (ft_fputs(fdOutput, "ns)\nGot:\t\t\"") < 0)
		|| (ft_fputs(fdOutput, check) < 0)
		|| (ft_fputs(fdOutput, "\"\nRet:\t\t") < 0)
		|| (ft_fputnbr(fdOutput, testRet) < 0)
		|| (ft_fputs(fdOutput, "\nErrno:\t\t") < 0)
		|| (ft_fputs(fdOutput, strerror(testErrno)) < 0)
		|| (ft_fputs(fdOutput, "\n(") < 0)
		|| (ft_fputzu(fdOutput, time_test) < 0)
		|| (ft_fputs(fdOutput, "ns)\n\n\n") < 0))
			return ;
		free(s);
		free(check);
	}
	s = NULL;
	check = NULL;
	if (!timespec_get(&before, TIME_UTC))
		return ;
	if ((testRet = ft_write(fdCheck, "abc", 3)) < 0)
		testErrno = errno;
	else
		testErrno = 0;
	if (!timespec_get(&after, TIME_UTC))
		return ;
	time_test = (after.tv_nsec - before.tv_nsec);
	if (!timespec_get(&before, TIME_UTC))
		return ;
	if ((realRet = write(fdCheck, "abc", 3)) < 0)
		realErrno = errno;
	else
		realErrno = 0;
	if (!timespec_get(&after, TIME_UTC))
		return ;
	time_real = (after.tv_nsec - before.tv_nsec);
	if ((ft_fputs(fdOutput, "No access\n\n") < 0))
		return ;
	if ((testRet == realRet) && (testErrno == realErrno))
	{
		if (ft_fputs(fdOutput, "\t[OK]") < 0)
			return ;
	}
	else if (ft_fputs(fdOutput, ">>>>[KO]<<<<") < 0)
		return ;
	if ((ft_fputs(fdOutput, "\n\nExpected ret:\t") < 0)
	|| (ft_fputnbr(fdOutput, realRet) < 0)
	|| (ft_fputs(fdOutput, "\nErrno:\t\t\t") < 0)
	|| (ft_fputs(fdOutput, strerror(realErrno)) < 0)
	|| (ft_fputs(fdOutput, "\n(") < 0)
	|| (ft_fputzu(fdOutput, time_real) < 0)
	|| (ft_fputs(fdOutput, "ns)\nGot ret:\t\t") < 0)
	|| (ft_fputnbr(fdOutput, testRet) < 0)
	|| (ft_fputs(fdOutput, "\nErrno:\t\t\t") < 0)
	|| (ft_fputs(fdOutput, strerror(testErrno)) < 0)
	|| (ft_fputs(fdOutput, "\n(") < 0)
	|| (ft_fputzu(fdOutput, time_test) < 0)
	|| (ft_fputs(fdOutput, "ns)\n\n\n") < 0))
		return ;
	close(fdInput);
	close(fdLenCheck);
	close(fdOutput);
	close(fdTest);
	close(fdCheck);
}

void			test_ft_read(void)
{
	char			*input = get_file("tests/ft_read_input.txt");
	int				fdOutput = open("tests/ft_read_output.log", O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR);
	int				fdReal = open(".readtest", O_RDONLY);
	int				fdTest = open(".readtest", O_RDONLY);
	char			c;
	struct timespec	before;
	struct timespec after;
	char			*real;
	char			*test;
	int				realRet;
	int				testRet;
	int				realErrno;
	int				testErrno;
	int				size;
	int				i = 0;
	int				testCount = 0;
	unsigned long	time_real;
	unsigned long	time_test;
	time_t			time_begin = time(NULL);

	if (!input || (fdReal < 0) || (fdTest < 0) || (fdOutput < 0)
	|| (write(fdOutput, "[", 1) < 0)
	|| (write(fdOutput, ctime(&time_begin), 24) < 0)
	|| (ft_fputs(fdOutput, "]ft_read\n\n") < 0)
	|| (ft_fputs(fdOutput, "Normal file\n\n") < 0))
	{
		ft_fputs(2, "Error\n");
		return ;
	}
	while ((size = atoi(&input[i])) > 0)
	{
		while (ft_isdigit(input[i]))
			i++;
		while (ft_isspace(input[i]))
			i++;
		if (!(real = (char*)malloc(sizeof(char) * (size + 1)))
		|| !(test = (char*)malloc(sizeof(char) * (size + 1))))
			return ;
		if (!timespec_get(&before, TIME_UTC))
			return ;
		if ((testRet = ft_read(fdTest, test, size)) < 0)
			testErrno = errno;
		else
			testErrno = 0;
		test[testRet] = 0;
		lseek(fdTest, 1, SEEK_CUR);
		if (!timespec_get(&after, TIME_UTC))
			return ;
		time_test = (after.tv_nsec - before.tv_nsec);
		if (!timespec_get(&before, TIME_UTC))
			return ;
		if ((realRet = read(fdReal, real, size)) < 0)
			realErrno = errno;
		else
			realErrno = 0;
		lseek(fdReal, 1, SEEK_CUR);
		real[realRet] = 0;
		if (!timespec_get(&after, TIME_UTC))
			return ;
		time_real = (after.tv_nsec - before.tv_nsec);
		if ((ft_fputs(fdOutput, "Test ") < 0)
		|| (ft_fputnbr(fdOutput, testCount) < 0)
		|| (ft_fputs(fdOutput, "\n\n") < 0))
			return ;
		if ((testRet == realRet) && (testErrno == realErrno) && !strcmp(real, test))
		{
			if (ft_fputs(fdOutput, "\t[OK]") < 0)
				return ;
		}
		else if (ft_fputs(fdOutput, ">>>>[KO]<<<<") < 0)
			return ;
		if ((ft_fputs(fdOutput, "\n\nExpected:\t\"") < 0)
		|| (ft_fputs(fdOutput, real) < 0)
		|| (ft_fputs(fdOutput, "\"\nRet:\t\t") < 0)
		|| (ft_fputnbr(fdOutput, realRet) < 0)
		|| (ft_fputs(fdOutput, "\nErrno:\t\t") < 0)
		|| (ft_fputs(fdOutput, strerror(realErrno)) < 0)
		|| (ft_fputs(fdOutput, "\n(") < 0)
		|| (ft_fputzu(fdOutput, time_real) < 0)
		|| (ft_fputs(fdOutput, "ns)\nGot:\t\t\"") < 0)
		|| (ft_fputs(fdOutput, test) < 0)
		|| (ft_fputs(fdOutput, "\"\nRet:\t\t") < 0)
		|| (ft_fputnbr(fdOutput, testRet) < 0)
		|| (ft_fputs(fdOutput, "\nErrno:\t\t") < 0)
		|| (ft_fputs(fdOutput, strerror(testErrno)) < 0)
		|| (ft_fputs(fdOutput, "\n(") < 0)
		|| (ft_fputzu(fdOutput, time_test) < 0)
		|| (ft_fputs(fdOutput, "ns)\n\n\n") < 0))
			return ;
		free(real);
		free(test);
		testCount++;
	}
	test = NULL;
	real = NULL;
	if (!timespec_get(&before, TIME_UTC))
		return ;
	if ((testRet = ft_read(-1, &c, 1)) < 0)
		testErrno = errno;
	else
		testErrno = 0;
	if (!timespec_get(&after, TIME_UTC))			
		return ;
	time_test = (after.tv_nsec - before.tv_nsec);
	if (!timespec_get(&before, TIME_UTC))
		return ;
	if ((realRet = read(-1, &c, 1)) < 0)
		realErrno = errno;
	else
		realErrno = 0;
	if (!timespec_get(&after, TIME_UTC))
		return ;
	time_real = (after.tv_nsec - before.tv_nsec);
	if ((ft_fputs(fdOutput, "Wrong file descriptor\n\n") < 0))
		return ;
	if ((testRet == realRet) && (testErrno == realErrno))
	{
		if (ft_fputs(fdOutput, "\t[OK]") < 0)
			return ;
	}
	else if (ft_fputs(fdOutput, ">>>>[KO]<<<<") < 0)
		return ;
	if ((ft_fputs(fdOutput, "\n\nExpected ret:\t") < 0)
	|| (ft_fputnbr(fdOutput, realRet) < 0)
	|| (ft_fputs(fdOutput, "\nErrno:\t\t\t") < 0)
	|| (ft_fputs(fdOutput, strerror(realErrno)) < 0)
	|| (ft_fputs(fdOutput, "\n(") < 0)
	|| (ft_fputzu(fdOutput, time_real) < 0)
	|| (ft_fputs(fdOutput, "ns)\nGot ret:\t\t") < 0)
	|| (ft_fputnbr(fdOutput, testRet) < 0)
	|| (ft_fputs(fdOutput, "\nErrno:\t\t\t") < 0)
	|| (ft_fputs(fdOutput, strerror(testErrno)) < 0)
	|| (ft_fputs(fdOutput, "\n(") < 0)
	|| (ft_fputzu(fdOutput, time_test) < 0)
	|| (ft_fputs(fdOutput, "ns)\n\n\n") < 0))			
		return ;
	close(fdTest);
	close(fdOutput);
	close(fdTest);
	close(fdReal);
	free(input);
}

void			test_ft_strdup(void)
{
	int				fdInput = open("tests/ft_strdup_input.txt", O_RDONLY);
	int				fdLenCheck = open("tests/ft_strdup_input.txt", O_RDONLY);
	int				fdOutput = open("tests/ft_strdup_output.log", O_CREAT | O_RDWR | O_APPEND, S_IWUSR | S_IRUSR);
	char			*test;
	char			*real;
	char			*s;
	int				len;
	struct timespec	before;
	struct timespec after;
	unsigned long	time_real;
	unsigned long	time_test;
	time_t			time_begin = time(NULL);

	if ((fdInput < 0) || (fdLenCheck < 0) || (fdOutput < 0)
	|| (write(fdOutput, "[", 1) < 0)
	|| (write(fdOutput, ctime(&time_begin), 24) < 0)
	|| (ft_fputs(fdOutput, "]ft_strdup\n\n") < 0))
	{
		ft_fputs(2, "Error\n");
		return ;
	}
	while ((len = get_next_len(fdLenCheck)) >= 0)
	{
		if (!(s = get_next_str(fdInput, len)))
		{
			ft_fputs(2, "Error\n");
			ft_fputs(fdOutput, "-------------------------MEMORY ERROR-------------------------\n");
			return ;
		}
		if (!timespec_get(&before, TIME_UTC))
			return ;
		test = ft_strdup(s);
		if (!timespec_get(&after, TIME_UTC))
			return ;
		time_test = (after.tv_nsec - before.tv_nsec);
		if (!timespec_get(&before, TIME_UTC))
			return ;
		real = strdup(s);
		if (!timespec_get(&after, TIME_UTC))
			return ;
		time_real = (after.tv_nsec - before.tv_nsec);
		if ((write(fdOutput, "\"", 1) < 0)
		|| (ft_fputs(fdOutput, s) < 0)
		|| (ft_fputs(fdOutput, "\"\n") < 0))
		free(s);
		if ((!test && !real) || (test && real && !strcmp(test, real)))
		{
			if (ft_fputs(fdOutput, "\t[OK]") < 0)
				return ;
		}
		else if (ft_fputs(fdOutput, ">>>>[KO]<<<<") < 0)
			return ;
		if ((ft_fputs(fdOutput, "\n\nExpected:\t\"") < 0)
		|| (ft_fputs(fdOutput, real) < 0)
		|| (ft_fputs(fdOutput, "\" (") < 0)
		|| (ft_fputzu(fdOutput, time_real) < 0)
		|| (ft_fputs(fdOutput, "ns)\nGot:\t\t\"") < 0)
		|| (ft_fputs(fdOutput, test) < 0)
		|| (ft_fputs(fdOutput, "\" (") < 0)
		|| (ft_fputzu(fdOutput, time_test) < 0)
		|| (ft_fputs(fdOutput, "ns)\n\n\n") < 0))
			return ;
		free(real);
		free(test);
	}
	s = NULL;
	close(fdInput);
	close(fdLenCheck);
	close(fdOutput);
	
}
			
void			test_ft_atoi_base(void)
{
	
	int				fdInput = open("tests/ft_atoi_base_input.txt", O_RDONLY);
	int				fdLenCheck = open("tests/ft_atoi_base_input.txt", O_RDONLY);
	int				fdOutput = open("tests/ft_atoi_base_output.log", O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR);
	int				testRet;
	int				realRet;
	char			*s1;
	char			*s2;
	int				len1;
	int				len2;
	char			c = 1;
	struct timespec	before;
	struct timespec after;
	unsigned long	time_real;
	unsigned long	time_test;
	time_t			time_begin = time(NULL);

	if ((fdInput < 0) || (fdLenCheck < 0) || (fdOutput < 0)
	|| (write(fdOutput, "[", 1) < 0)
	|| (write(fdOutput, ctime(&time_begin), 24) < 0)
	|| (ft_fputs(fdOutput, "]ft_atoi_base\n\n") < 0))
	{
		ft_fputs(2, "Error\n");
		return ;
	}
	while (((len1 = get_next_len(fdLenCheck)) >= 0) && ((len2 = get_next_len(fdLenCheck)) >= 0))
	{
		if (!(s1 = get_next_str(fdInput, len1)) || !(s2 = get_next_str(fdInput, len2)))
		{
			if (s1)
				free(s1);
			s1 = NULL;
			ft_fputs(2, "Error\n");
			ft_fputs(fdOutput, "-------------------------MEMORY ERROR-------------------------\n");
			return ;
		}
		if ((write(fdOutput, "\"", 1) < 0)
		|| (ft_fputs(fdOutput, s1) < 0)
		|| (ft_fputs(fdOutput, "\" \"") < 0)
		|| (ft_fputs(fdOutput, s2) < 0)
		|| (ft_fputs(fdOutput, "\"\n") < 0))
			return ;
		if (!timespec_get(&before, TIME_UTC))
			return ;
		testRet = ft_atoi_base(s1, s2);
		if (!timespec_get(&after, TIME_UTC))
			return ;
		time_test = (after.tv_nsec - before.tv_nsec);
		if (!timespec_get(&before, TIME_UTC))
			return ;
		realRet = ft_atoi_base_test(s1, s2);
		if (!timespec_get(&after, TIME_UTC))
			return ;
		time_real = (after.tv_nsec - before.tv_nsec);
		free(s1);
		free(s2);
		if (testRet == realRet)
		{
			if (ft_fputs(fdOutput, "\t[OK]") < 0)
				return ;
		}
		else if (ft_fputs(fdOutput, ">>>>[KO]<<<<") < 0)
			return ;
		if ((ft_fputs(fdOutput, "\n\nExpected:\t") < 0)
		|| (ft_fputnbr(fdOutput, realRet) < 0)
		|| (ft_fputs(fdOutput, " (") < 0)
		|| (ft_fputzu(fdOutput, time_real) < 0)
		|| (ft_fputs(fdOutput, "ns)\nGot:\t\t") < 0)
		|| (ft_fputnbr(fdOutput, testRet) < 0)
		|| (ft_fputs(fdOutput, " (") < 0)
		|| (ft_fputzu(fdOutput, time_test) < 0)
		|| (ft_fputs(fdOutput, "ns)\n\n\n") < 0))
			return ;
	}
	s1 = NULL;
	s2 = NULL;
	close(fdInput);
	close(fdLenCheck);
	close(fdOutput);
}

void			test_ft_list_push_front(void)
{
	char			*input = get_file("tests/ft_list_push_front_input.txt");
	int				fdOutput = open("tests/ft_list_push_front_output.log", O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR);
	int				i = 0;
	t_list			*test = NULL;
	int				lstI;
	int				size;
	int				len;
	char			*name;
	char			*testdata;
	char			*realdata;
	char			**real;
	int				testCount = 0;
	time_t			time_begin = time(NULL);

	if ((fdOutput < 0) || !input
	|| (write(fdOutput, "[", 1) < 0)
	|| (write(fdOutput, ctime(&time_begin), 24) < 0)
	|| (ft_fputs(fdOutput, "]ft_list_push_front\n\n") < 0))
	{
		ft_fputs(2, "Error\n");
		return ;
	}
	while (input[i])
	{
		while (input[i] && strncmp(&input[i], "name:", 5))
			i++;
		while (input[i] && (input[i++] - '\"'))
			continue ;
		if (!input[i])
			break ;
		if (!(name = ft_strcdup(&input[i], '\"')))
		{
			ft_fputs(2, "Error\n");
			return ;
		}
		while (strncmp(&input[i], "content:", 8))
			i++;
		if (!(size = get_list_size(&input[i])))
			return ;
		if (!(real = (char**)malloc(sizeof(char*) * (size + 1))))
		{
			ft_fputs(2, "Error\n");
			return ;
		}
		real[size] = NULL;
		lstI = 1;
		while (lstI <= size)
		{
			while (input[i++] - '\"')
				continue ;
			if (!(real[size - lstI] = ft_strcdup(&input[i], '\"')))
			{
				ft_fputs(2, "Error\n");
				return ;
			}
			while (input[i++] - '\"')
				continue ;
			if (!test)
			{
				if (!(test = ft_list_new(real[size - lstI])))
					return ;
			}
			else
				ft_list_push_front(&test, real[size - lstI]);
			lstI++;
		}
		if (!(testdata = get_list_data(test)))
			return ;
		if (!(realdata = get_strs_data(real)))
		{
			free(testdata);
			return ;
		}
		ft_fputs(fdOutput, "Test ");
		ft_fputnbr(fdOutput, testCount);
		ft_fputs(fdOutput, "\n\n");
		testCount++;
		if (strcmp(testdata, realdata))
			ft_fputs(fdOutput, ">>>>[KO]<<<<");
		else
			ft_fputs(fdOutput, "\t[OK]");
		free(testdata);
		free(realdata);
		ft_fputs(fdOutput, "\n\nExpected:\n");
		ft_strings_disp(fdOutput, real, name);
		ft_fputs(fdOutput, "Got:\n");
		ft_list_disp(fdOutput, test, name);
		ft_fputs(fdOutput, "\n\n");
		free(name);
		name = NULL;
		free(real);
		ft_list_clear(&test);
		real = NULL;
	}
	free(input);
}

void			test_ft_list_size(void)
{
	char			*input = get_file("tests/ft_list_size_input.txt");
	int				fdOutput = open("tests/ft_list_size_output.log", O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR);
	int				i = 0;
	int				j;
	t_list			*list = NULL;
	int				test;
	int				real;
	int				len;
	char			*name;
	char			*data;
	int				testCount = 0;
	time_t			time_begin = time(NULL);

	if ((fdOutput < 0) || !input
	|| (write(fdOutput, "[", 1) < 0)
	|| (write(fdOutput, ctime(&time_begin), 24) < 0)
	|| (ft_fputs(fdOutput, "]ft_list_size\n\n") < 0))
	{
		ft_fputs(2, "Error\n");
		return ;
	}
	while (input[i])
	{
		while (input[i] && strncmp(&input[i], "name:", 5))
			i++;
		while (input[i] && (input[i++] - '\"'))
			continue ;
		if (!input[i])
			break ;
		if (!(name = ft_strcdup(&input[i], '\"')))
		{
			ft_fputs(2, "Error\n");
			return ;
		}
		while (strncmp(&input[i], "content:", 8))
			i++;
		if (!(real = get_list_size(&input[i])))
			return ;
		j = 0;
		while (j < real)
		{
			while (input[i++] - '\"')
				continue ;
			if (!(data = ft_strcdup(&input[i], '\"')))
				return ;
			if (!list)
			{
				if (!(list = ft_list_new(data)))
					return ;
			}
			else
				list_push_front(&list, data);
			j++;
		}
		test = ft_list_size(list);
		ft_list_clear(&list);
		ft_fputs(fdOutput, "Test ");
		ft_fputnbr(fdOutput, testCount);
		ft_fputs(fdOutput, ": ");
		ft_fputs(fdOutput, name);
		ft_fputs(fdOutput, "\n\n");
		free(name);
		testCount++;
		if (real != test)
			ft_fputs(fdOutput, ">>>>[KO]<<<<");
		else
			ft_fputs(fdOutput, "\t[OK]");
		if ((ft_fputs(fdOutput, "\n\nExpected:\t") < 0)
		|| (ft_fputzu(fdOutput, real) < 0)
		|| (ft_fputs(fdOutput, "\nGot:\t\t") < 0)
		|| (ft_fputzu(fdOutput, test) < 0)
		|| (ft_fputs(fdOutput, "\n\n\n") < 0))
			return ;
	}
	free(input);
}

void			test_ft_list_sort(void)
{
	char			*input = get_file("tests/ft_list_sort_input.txt");
	int				fdOutput = open("tests/ft_list_sort_output.log", O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR);
	int				i = 0;
	int				j;
	t_list			*test = NULL;
	int				lstI;
	int				size;
	int				len;
	char			*name;
	char			*testdata;
	char			*realdata;
	char			**real;
	int				testCount = 0;
	time_t			time_begin = time(NULL);

	if ((fdOutput < 0) || !input
	|| (write(fdOutput, "[", 1) < 0)
	|| (write(fdOutput, ctime(&time_begin), 24) < 0)
	|| (ft_fputs(fdOutput, "]ft_list_sort\n\n") < 0))
	{
		ft_fputs(2, "Error\n");
		return ;
	}
	while (input[i])
	{
		while (input[i] && strncmp(&input[i], "name:", 5))
			i++;
		while (input[i] && (input[i++] - '\"'))
			continue ;
		if (!input[i])
			break ;
		if (!(name = ft_strcdup(&input[i], '\"')))
		{
			ft_fputs(2, "Error\n");
			return ;
		}
		while (strncmp(&input[i], "content:", 8))
			i++;
		if (!(size = get_list_size(&input[i])))
			return ;
		if (!(real = (char**)malloc(sizeof(char*) * (size + 1))))
		{
			ft_fputs(2, "Error\n");
			return ;
		}
		real[size] = NULL;
		lstI = 1;
		while (lstI <= size)
		{
			while (input[i++] - '\"')
				continue ;
			if (!(real[size - lstI] = ft_strcdup(&input[i], '\"')))
			{
				ft_fputs(2, "Error\n");
				return ;
			}
			while (input[i++] - '\"')
				continue ;
			if (!test)
			{
				if (!(test = ft_list_new(real[size - lstI])))
					return ;
			}
			else
				ft_list_push_front(&test, real[size - lstI]);
			lstI++;
		}
		ft_sort_strs(real, &strcmp);
		ft_list_sort(&test, &strcmp);
		if (!(testdata = get_list_data(test)))
			return ;
		if (!(realdata = get_strs_data(real)))
		{
			free(testdata);
			return ;
		}
		ft_fputs(fdOutput, "Test ");
		ft_fputnbr(fdOutput, testCount);
		ft_fputs(fdOutput, "\n\n");
		testCount++;
		if (strcmp(testdata, realdata))
			ft_fputs(fdOutput, ">>>>[KO]<<<<");
		else
			ft_fputs(fdOutput, "\t[OK]");
		free(testdata);
		free(realdata);
		ft_fputs(fdOutput, "\n\nExpected:\n");
		ft_strings_disp(fdOutput, real, name);
		ft_fputs(fdOutput, "Got:\n");
		ft_list_disp(fdOutput, test, name);
		free(name);
		name = NULL;
		ft_fputs(fdOutput, "\n\n");
		ft_list_clear(&test);
		free(real);
		real = NULL;
	}
	free(input);
}

void			test_ft_list_remove_if(void)
{
	char			*input = get_file("tests/ft_list_remove_if_input.txt");
	int				fdOutput = open("tests/ft_list_remove_if_output.log", O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR);
	int				i = 0;
	t_list			*test = NULL;
	int				j;
	int				lstI;
	int				size;
	char			*dup;
	int				len;
	char			*name;
	char			*testdata;
	char			*realdata;
	char			**real;
	char			**toRemove;
	int				testCount = 0;
	time_t			time_begin = time(NULL);

	if ((fdOutput < 0) || !input
	|| (write(fdOutput, "[", 1) < 0)
	|| (write(fdOutput, ctime(&time_begin), 24) < 0)
	|| (ft_fputs(fdOutput, "]ft_list_remove_if\n\n") < 0))
	{
		ft_fputs(2, "Error\n");
		return ;
	}
	while (input[i])
	{
		while (input[i] && strncmp(&input[i], "name:", 5))
			i++;
		while (input[i] && (input[i++] - '\"'))
			continue ;
		if (!input[i])
			break ;
		if (!(name = ft_strcdup(&input[i], '\"')))
		{
			ft_fputs(2, "Error\n");
			return ;
		}
		while (input[i] && strncmp(&input[i], "content:", 8))
			i++;
		if (!(size = get_list_size(&input[i])))
			return ;
		if (!(real = (char**)malloc(sizeof(char*) * (size + 1))))
		{
			ft_fputs(2, "Error\n");
			return ;
		}
		real[size] = NULL;
		lstI = 1;
		while (lstI <= size)
		{
			while (input[i++] - '\"')
				continue ;
			if (!(real[size - lstI] = ft_strcdup(&input[i], '\"')))
			{
				ft_fputs(2, "Error\n");
				return ;
			}
			while (input[i++] - '\"')
				continue ;
			if (!(dup = strdup(real[size - lstI])))
				return ;
			if (!test)
			{
				if (!(test = ft_list_new(dup)))
					return ;
			}
			else
				list_push_front(&test, dup);
			lstI++;
		}
		while (input[i] && strncmp(&input[i], "remove:", 7))
			i++;
		if (!input[i] || !(size = get_list_size(&input[i])))
			return ;
		if (!(toRemove = (char**)malloc(sizeof(char*) * (size + 1))))
		{
			ft_fputs(2, "Error\n");
			return ;
		}
		for (j = 0; j < size; j++)
		{
			while (input[i++] - '\"')
				continue ;
			if (!(toRemove[j] = ft_strcdup(&input[i], '\"')))
			{
				ft_fputs(2, "Error\n");
				return ;
			}
			while (input[i++] - '\"')
				continue ;
		}
		j = 0;
		while (j < size)
		{
			ft_strs_remove_if(real, toRemove[j], &strcmp);
			ft_list_remove_if(&test, toRemove[j], &strcmp, &free);
			free(toRemove[j]);
			toRemove[j] = NULL;
			j++;
		}
		free(toRemove);
		toRemove = NULL;
		if (!(testdata = get_list_data(test)))
			return ;
		if (!(realdata = get_strs_data(real)))
		{
			free(testdata);
			return ;
		}
		ft_fputs(fdOutput, "Test ");
		ft_fputnbr(fdOutput, testCount);
		ft_fputs(fdOutput, "\n\n");
		testCount++;
		if (strcmp(testdata, realdata))
			ft_fputs(fdOutput, ">>>>[KO]<<<<");
		else
			ft_fputs(fdOutput, "\t[OK]");
		free(testdata);
		free(realdata);
		ft_fputs(fdOutput, "\n\nExpected:\n");
		ft_strings_disp(fdOutput, real, name);
		ft_fputs(fdOutput, "Got:\n");
		ft_list_disp(fdOutput, test, name);
		free(name);
		name = NULL;
		ft_fputs(fdOutput, "\n\n");
		ft_list_clear(&test);
		free(real);
		real = NULL;
	}
	free(input);
}
