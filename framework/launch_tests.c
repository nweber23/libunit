/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:55:22 by nmihaile          #+#    #+#             */
/*   Updated: 2025/08/30 14:02:33 by nweber           ###   ########.fr       */
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
		if (unit_test->f())
			exit(EXIT_FAILURE);
		exit(EXIT_SUCCESS);
	}
	wait(&status);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
		return (OK);
	else if (WIFEXITED(status))
		return (KO);
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGSEGV)
			return (SEGV);
		else if (WTERMSIG(status) == SIGBUS)
			return (BUSE);
	}
	return (KO);
}

int	launch_tests(char *func_name, t_list *lst)
{
	t_list		*curr;
	t_unit_test	*unit_test;

	curr = lst;
	while (curr)
	{
		unit_test = (t_unit_test *)(curr->content);
		unit_test->status = exec_unit_test(unit_test);
		ftu_print_result(func_name, unit_test);
		curr = curr->next;
	}
	return (0);
}
