/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:38:17 by nweber            #+#    #+#             */
/*   Updated: 2025/08/31 18:50:54 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static char	*get_signal_str(int sig_num)
{
	if (sig_num == 4)
		return ("SIGILL");
	if (sig_num == 6)
		return ("SIGABRT");
	if (sig_num == 7 || sig_num == 10)
		return ("SIGBUS");
	if (sig_num == 8)
		return ("SIGFPE");
	if (sig_num == 11)
		return ("SIGSEGV");
	if (sig_num == 13)
		return ("SIGPIPE");
	return ("UNSUPPORTED SIGNAL");
}

static void	write_actual_description(int fd, t_unit_test *unit_test)
{
	if (unit_test->sig_num == 4)
		dprintf(fd, "\tACTUAL: Illegal instruction\n");
	else if (unit_test->sig_num == 6)
		dprintf(fd, "\tACTUAL: Signal from abort function\n");
	else if (unit_test->sig_num == 7 || unit_test->sig_num == 10)
		dprintf(fd, "\tACTUAL: Bus error\n");
	else if (unit_test->sig_num == 8)
		dprintf(fd, "\tACTUAL: Floating-point exception\n");
	else if (unit_test->sig_num == 11)
		dprintf(fd, "\tACTUAL: Invalid memory reference (segfault)\n");
	else if (unit_test->sig_num == 13)
		dprintf(fd, "\tACTUAL: Write in pipe with no reader\n");
}

static void	write_signal_exitcode(int fd, t_unit_test *unit_test)
{
	if (unit_test->sig_num > 0)
		dprintf(fd, "\tSIGNAL: %s [%d]\n", get_signal_str(unit_test->sig_num),
			unit_test->sig_num);
	else
		dprintf(fd, "\tSIGNAL: -\n");
	if (unit_test->exit_code > 0)
		dprintf(fd, "\tEXIT_CODE: [%d]\n", unit_test->exit_code);
	else
		dprintf(fd, "\tEXIT_CODE: -\n");
	write_actual_description(fd, unit_test);
}

static void	write_failure_details(int fd, t_unit_test *unit_test)
{
	write_signal_exitcode(fd, unit_test);
	if (unit_test->status == SEGV)
		dprintf(fd, "\t[INFO] Check null pointers, array \
bounds, freed memory.\n");
	else if (unit_test->status == BUSE)
		dprintf(fd, "\t[INFO] Check memory alignment, \
uninitialized pointers.\n");
	else if (unit_test->status == ABRT)
		dprintf(fd, "\t[INFO] Check assertions, malloc \
failures, abort() calls.\n");
	else if (unit_test->status == SFPE)
		dprintf(fd, "\t[INFO] Check division by zero, \
invalid float operations.\n");
	else if (unit_test->status == PIPE)
		dprintf(fd, "\t[INFO] Check file descriptors, pipe operations.\n");
	else if (unit_test->status == SILL)
		dprintf(fd, "\t[INFO] Check function pointers, corrupted code.\n");
	else if (unit_test->status == TIMEOUT)
		dprintf(fd, "\t[INFO] Check infinite loops, recursive functions.\n");
	else if (unit_test->status == KO)
		dprintf(fd, "\t[INFO] Check return values, test logic, edge cases.\n");
}

void	ftu_write_log(char *func_name, t_list *lst, int count, int passed)
{
	int				fd;
	char			file_name[256];
	t_list			*curr;
	t_unit_test		*unit_test;
	static char		*status_msg[9] = {"[OK]", "[KO]", "[SEGV]", "[BUSE]",
		"[ABRT]", "[SFPE]", "[PIPE]", "[SILL]", "[TIMEOUT]"};

	snprintf(file_name, sizeof(file_name), "%s.log", func_name);
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	dprintf(fd, "Function: %s\nPassed: %d/%d\n", func_name, passed, count);
	if (passed != count)
		dprintf(fd, "Failed: %d tests\n", count - passed);
	dprintf(fd, "\n");
	curr = lst;
	while (curr)
	{
		unit_test = (t_unit_test *)(curr->content);
		dprintf(fd, "%s: %s\n", unit_test->name, status_msg[unit_test->status]);
		if (unit_test->status != OK)
			write_failure_details(fd, unit_test);
		curr = curr->next;
	}
	close(fd);
}
