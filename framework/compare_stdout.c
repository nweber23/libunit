/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_stdout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 19:04:25 by nmihaile          #+#    #+#             */
/*   Updated: 2025/08/31 21:27:34 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static int	redirect_stdout(const char *filename, int *saved_stdout)
{
	int	fd;

	*saved_stdout = dup(STDOUT_FILENO);
	if (*saved_stdout == -1)
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
	{
		close(*saved_stdout);
		return (-1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		close(fd);
		close(*saved_stdout);
		return (-1);
	}
	return (fd);
}

static int	read_file(const char *filename, char *buff, size_t buff_size)
{
	int		fd;
	ssize_t	bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	memset(buff, 0, buff_size);
	bytes_read = read(fd, buff, buff_size - 1);
	close(fd);
	remove(filename);
	if (bytes_read < 0)
		return (-1);
	return (0);
}

static int	restore_stdout(int saved_stdout, int fd)
{
	int	error;

	error = 0;
	if (dup2(saved_stdout, STDOUT_FILENO) == -1)
		error = -1;
	close(saved_stdout);
	close(fd);
	return (error);
}

int	compare_stdout(void (*f)(void), char *expected)
{
	int		saved_stdout;
	int		fd;
	char	buff[4096];

	fd = redirect_stdout(".cmpstdout.tmp", &saved_stdout);
	if (fd == -1)
	{
		remove(".cmpstdout.tmp");
		return (-1);
	}
	f();
	fflush(stdout);
	if (restore_stdout(saved_stdout, fd) == -1)
	{
		remove(".cmpstdout.tmp");
		return (-1);
	}
	if (read_file(".cmpstdout.tmp", buff, 4096) == -1)
		return (-1);
	return (strcmp(buff, expected));
}
