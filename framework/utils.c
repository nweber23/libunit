/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:01:08 by nmihaile          #+#    #+#             */
/*   Updated: 2025/08/30 12:12:33 by nmihaile         ###   ########.fr       */
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
