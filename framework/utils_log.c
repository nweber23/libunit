/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:38:17 by nweber            #+#    #+#             */
/*   Updated: 2025/08/31 17:46:57 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static void	write_failure_details(int fd, int status)
{
	dprintf(fd, "  Failure Details:\n");
	if (status == SEGV)
		dprintf(fd, "    -> Check null pointers, array bounds, freed memory\n");
	else if (status == BUSE)
		dprintf(fd, "    -> Check memory alignment, uninitialized pointers\n");
	else if (status == ABRT)
		dprintf(fd, "    -> Check assertions, malloc failures, abort() calls\n");
	else if (status == SFPE)
		dprintf(fd, "    -> Check division by zero, invalid float operations\n");
	else if (status == PIPE)
		dprintf(fd, "    -> Check file descriptors, pipe operations\n");
	else if (status == SILL)
		dprintf(fd, "    -> Check function pointers, corrupted code\n");
	else if (status == TIMEOUT)
		dprintf(fd, "    -> Check infinite loops, recursive functions\n");
	else if (status == KO)
		dprintf(fd, "    -> Check return values, test logic, edge cases\n");
	dprintf(fd, "------------------------------------------------------------------\n");
}

void	ftu_write_log(char *func_name, t_list *lst, int count, int passed)
{
	int				fd;
	char			file_name[256];
	t_list			*curr;
	t_unit_test		*unit_test;
	static char		*status_msg[9] = {"[OK]", "[KO]", "[SEGV]", "[BUSE]", "[ABRT]",
		"[SFPE]", "[PIPE]", "[SILL]", "[TIMEOUT]"};

	snprintf(file_name, sizeof(file_name), "%s.log", func_name);
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	dprintf(fd, "Function: %s\n", func_name);
	dprintf(fd, "Passed: %d/%d\n", passed, count);
	if (passed != count)
		dprintf(fd, "Failed: %d tests\n", count - passed);
	curr = lst;
	while (curr)
	{
		unit_test = (t_unit_test *)(curr->content);
		dprintf(fd, "%s: %s\n", unit_test->name, status_msg[unit_test->status]);
		if (unit_test->status != OK)
			write_failure_details(fd, unit_test->status);
		curr = curr->next;
	}
	close(fd);
}
