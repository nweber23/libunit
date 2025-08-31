/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:01:08 by nmihaile          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/08/31 12:16:32 by nmihaile         ###   ########.fr       */
=======
/*   Updated: 2025/08/31 13:31:18 by nweber           ###   ########.fr       */
>>>>>>> 2efd4bd936bd0bbcd4c785abbc28818ea60c05f4
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	ftu_print_error_fd(char *error_msg, char *test_name, int fd)
{
	ft_putstr_fd("\033[91m", fd);
	ft_putstr_fd(error_msg, fd);
	ft_putstr_fd(test_name, fd);
	ft_putendl_fd("\033[0m", fd);
}

void	ftu_print_result(char *func_name, t_unit_test *unit_test)
{
	static char	status_msg[7][32] = {LIGHTGREEN"[OK]"DEFAULT, \
		LIGHTRED"[KO]"DEFAULT, \
		LIGHTYELLOW"[SEGV]"DEFAULT, \
		LIGHTYELLOW"[BUSE]"DEFAULT, \
		LIGHTYELLOW"[ABRT]"DEFAULT, \
<<<<<<< HEAD
		LIGHTYELLOW"[FPE]"DEFAULT, \
		LIGHTYELLOW"[PIPE]"DEFAULT};
=======
		LIGHTYELLOW"[PIPE]"DEFAULT, \
		LIGHTYELLOW"[TIMEOUT]"DEFAULT};
>>>>>>> 2efd4bd936bd0bbcd4c785abbc28818ea60c05f4

	ft_putstr_fd(func_name, 1);
	ft_putstr_fd(": ", 1);
	ft_putstr_fd(unit_test->name, 1);
	ft_putstr_fd(": ", 1);
	ft_putendl_fd(status_msg[unit_test->status], 1);
}

void	ftu_print_routine_results(int count, int passed)
{
	if (passed == count)
		ft_putstr_fd(LIGHTGREEN, 1);
	else
		ft_putstr_fd(LIGHTRED, 1);
	ft_putnbr_fd(passed, 1);
	ft_putstr_fd("/", 1);
	ft_putnbr_fd(count, 1);
	ft_putendl_fd(" tests passed", 1);
	ft_putendl_fd(DEFAULT, 1);
}

void	ftu_print_final_result(void)
{
	if (ftu_count_routine_result(0, 0, false))
	{
		ft_putstr_fd(GREEN, 1);
		ft_putstr_fd(GREEN"===============================================", 1);
		ft_putendl_fd(DEFAULT, 1);
		ft_putendl_fd("  🎉🥳"LIGHTGREEN BOLD"All tests passed!" REGULAR \
			GREEN " Congratulations! 🥳🎉  ", 1);
		ft_putstr_fd(GREEN"===============================================", 1);
		ft_putendl_fd(DEFAULT, 1);
		return ;
	}
}
