/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:55:22 by nmihaile          #+#    #+#             */
/*   Updated: 2025/08/31 11:54:44 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <fcntl.h>

static void	silent_fd(int fd_out)
{
	int	fd;

	fd = open("/dev/null", O_WRONLY);
	if (fd != -1)
	{
		dup2(fd, fd_out);
		close(fd);
	}
}

static int	wait_on_pid(int *status)
{
	wait(status);
	if (WIFSIGNALED(*status))
	{
		if (WTERMSIG(*status) == SIGSEGV)
			return (SEGV);
		if (WTERMSIG(*status) == SIGBUS)
			return (BUSE);
		if (WTERMSIG(*status) == SIGABRT)
			return (ABRT);
		if (WTERMSIG(*status) == SIGPIPE)
			return (PIPE);
	}
	else if (WIFEXITED(*status) && WEXITSTATUS(*status) == 0)
		return (OK);
	return (KO);
}

static int	exec_unit_test(t_unit_test *unit_test, t_list *lst)
{
	pid_t	pid;
	int		status;
	int		(*func)(void);

	pid = fork();
	if (pid == 0)
	{
		silent_fd(STDERR_FILENO);
		silent_fd(STDIN_FILENO);
		func = unit_test->f;
		ft_lstclear(&lst, free);
		if (func() == -1)
			exit(EXIT_FAILURE);
		exit(EXIT_SUCCESS);
	}
	return (wait_on_pid(&status));
}

int	launch_tests(char *func_name, t_list *lst)
{
	int			count;
	int			passed;
	t_list		*curr;
	t_unit_test	*unit_test;

	count = 0;
	passed = 0;
	curr = lst;
	while (curr)
	{
		unit_test = (t_unit_test *)(curr->content);
		++count;
		unit_test->status = exec_unit_test(unit_test, lst);
		if (unit_test->status == 0)
			++passed;
		ftu_print_result(func_name, unit_test);
		curr = curr->next;
	}
	ftu_count_routine_result(count, passed, true);
	ftu_print_routine_results(count, passed);
	ft_lstclear(&lst, free);
	return (0);
}
