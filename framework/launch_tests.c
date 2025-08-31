/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:55:22 by nmihaile          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/08/31 12:15:30 by nmihaile         ###   ########.fr       */
=======
/*   Updated: 2025/08/31 13:20:52 by nweber           ###   ########.fr       */
>>>>>>> 2efd4bd936bd0bbcd4c785abbc28818ea60c05f4
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
		if (WTERMSIG(*status) == SIGFPE)
			return (SFPE);
		if (WTERMSIG(*status) == SIGPIPE)
			return (PIPE);
	}
	else if (WIFEXITED(*status))
	{
		if (WEXITSTATUS(*status) == 124)
			return (TIMEOUT);
		if (WEXITSTATUS(*status) == 0)
			return (OK);
	}
	return (KO);
}

static void	exec_child(t_unit_test *unit_test, t_list *lst)
{
	int	(*func)(void);

	signal(SIGALRM, timeout_handler);
	alarm(10);
	silent_fd(STDERR_FILENO);
	silent_fd(STDIN_FILENO);
	func = unit_test->f;
	ft_lstclear(&lst, free);
	if (func() == -1)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

static int	exec_unit_test(t_unit_test *unit_test, t_list *lst)
{
	pid_t	pid;
	int		status;
	int		timeout_count;
	int		wait_result;

	timeout_count = 0;
	pid = fork();
	if (pid == 0)
		exec_child(unit_test, lst);
	while (timeout_count < TIMEOUT_PERIOD * 10)
	{
		wait_result = waitpid(pid, &status, WNOHANG);
		if (wait_result > 0)
			break ;
		else if (wait_result == -1)
			break ;
		usleep(100000);
		timeout_count++;
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
