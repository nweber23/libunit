/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:01:08 by nmihaile          #+#    #+#             */
/*   Updated: 2025/08/30 14:07:38 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	ftu_print_error_fd(char *error_msg, char *test_name, int fd)
{
	//	TDOD add colors
	ft_putstr_fd("\033[91m", fd);
	ft_putstr_fd(error_msg, fd);
	ft_putstr_fd(test_name, fd);
	ft_putendl_fd("\033[0m", fd);
}

// [test_function]:[test_name]:[status]
void	ftu_print_result(char *func_name, t_unit_test *unit_test)
{
	static char	status_msg[4][32] = {"OK", "KO", "SIGV", "BUSE"};

	ft_putstr_fd(func_name, 1);
	ft_putstr_fd(": ", 1);
	ft_putstr_fd(unit_test->name, 1);
	ft_putstr_fd(": ", 1);
	ft_putendl_fd(status_msg[unit_test->status], 1);
}
