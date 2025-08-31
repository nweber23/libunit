/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:38:17 by nweber            #+#    #+#             */
/*   Updated: 2025/08/31 14:41:19 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	ftu_write_log(char *func_name, t_list *lst, int count, int passed)
{
	int				fd;
	char			file_name[256];
	t_list			*curr;
	t_unit_test		*unit_test;
	static char		*status_msg[9] = {
		"[OK]", "[KO]", "[SEGV]", "[BUSE]", "[ABRT]",
		"[SFPE]", "[PIPE]", "[SILL]", "[TIMEOUT]"};

	snprintf(file_name, sizeof(file_name), "%s.log", func_name);
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	dprintf(fd, "Function: %s\n", func_name);
	dprintf(fd, "Passed: %d/%d\n\n", passed, count);
	curr = lst;
	while (curr)
	{
		unit_test = (t_unit_test *)(curr->content);
		dprintf(fd, "%s: %s\n", unit_test->name, status_msg[unit_test->status]);
		curr = curr->next;
	}
	close(fd);
}
