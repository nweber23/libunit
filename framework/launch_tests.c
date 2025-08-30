/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:55:22 by nmihaile          #+#    #+#             */
/*   Updated: 2025/08/30 15:34:15 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static int	exec_unit_test(t_unit_test *unit_test)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (unit_test->f() == -1)
			exit(EXIT_FAILURE);
		exit(EXIT_SUCCESS);
	}
	wait(&status);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGSEGV)
			return (SEGV);
		if (WTERMSIG(status) == SIGBUS)
			return (BUSE);
	}
	else if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
		return (OK);
	return (KO);
}

int	launch_tests(char *func_name, t_list *lst)
{
	static int	count;
	static int	passed;
	t_list		*curr;
	t_unit_test	*unit_test;

	curr = lst;
	while (curr)
	{
		unit_test = (t_unit_test *)(curr->content);
		++count;
		unit_test->status = exec_unit_test(unit_test);
		if (unit_test->status == 0)
			++passed;
		ftu_print_result(func_name, unit_test);
		curr = curr->next;
	}
	ft_putnbr_fd(passed, 1);
	ft_putstr_fd("/", 1);
	ft_putnbr_fd(count, 1);
	ft_putendl_fd(" tests checked", 1);
	ft_putendl_fd("", 1);
	return (0);
}
