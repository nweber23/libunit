/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:55:22 by nmihaile          #+#    #+#             */
/*   Updated: 2025/08/31 20:20:06 by nmihaile         ###   ########.fr       */
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

// static void	set_signal_and_exit_code(int signum, int exit_code,
// 				t_unit_test * unit_test)
// {
// 	unit_test
// }

static int	evaluate_child_exit_code(int *status, t_unit_test *unit_test)
{
	if (WIFSIGNALED(*status))
	{
		unit_test->sig_num = WTERMSIG(*status);
		if (WTERMSIG(*status) == SIGSEGV)
			return (SEGV);
		if (WTERMSIG(*status) == SIGBUS)
			return (BUSE);
		if (WTERMSIG(*status) == SIGABRT)
			return (ABRT);
		if (WTERMSIG(*status) == SIGFPE)
			return (SFPE);
		if (WTERMSIG(*status) == SIGPIPE)
			return (PIPE);
		if (WTERMSIG(*status) == SIGILL)
			return (SILL);
	}
	else if (WIFEXITED(*status))
	{
		unit_test->exit_code = WEXITSTATUS(*status);
		if (WEXITSTATUS(*status) == 124)
			return (TIMEOUT);
		if (WEXITSTATUS(*status) == 0)
			return (ftu_total_test_passed(true), OK);
	}
	return (KO);
}

static void	exec_child(t_unit_test *unit_test, t_list *lst)
{
	int	(*func)(void);

	signal(SIGALRM, ftu_timeout_handler);
	alarm(10);
	silent_fd(STDERR_FILENO);
	silent_fd(STDOUT_FILENO);
	func = unit_test->f;
	ft_lstclear(&lst, free);
	alarm(TIMEOUT_PERIOD);
	if (func() == -1)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

static int	exec_unit_test(t_unit_test *unit_test, t_list *lst)
{
	pid_t	pid;
	int		status;

	ftu_total_test_count(true);
	pid = fork();
	if (pid == 0)
		exec_child(unit_test, lst);
	wait(&status);
	return (evaluate_child_exit_code(&status, unit_test));
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
		if (unit_test->exit_code == 0)
			++passed;
		ftu_print_result(func_name, unit_test);
		curr = curr->next;
	}
	ftu_count_routine_result(count, passed, true);
	ftu_print_routine_results(count, passed);
	ftu_write_log(func_name, lst, count, passed);
	ft_lstclear(&lst, free);
	return (0);
}
