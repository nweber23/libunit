/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_max_int_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 20:54:51 by nmihaile          #+#    #+#             */
/*   Updated: 2025/08/31 20:57:34 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../framework/libunit.h"
#include "../../libft/libft.h"

static void	caller(void)
{
	ft_putnbr_fd(2147483647, 1);
}

int	ft_putnbr_fd_max_int_test(void)
{
	if (compare_stdout(caller, "2147483647") == 0)
		return (0);
	else
		return (-1);
}
