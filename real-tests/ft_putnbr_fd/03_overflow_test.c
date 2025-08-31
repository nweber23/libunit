/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_overflow_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 20:58:32 by nmihaile          #+#    #+#             */
/*   Updated: 2025/08/31 21:00:47 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../framework/libunit.h"
#include "../../libft/libft.h"

static void	caller(void)
{
	ft_putnbr_fd((int)2147483657, 1);
}

int	ft_putnbr_fd_overflow_test(void)
{
	if (compare_stdout(caller, "-2147483639") == 0)
		return (0);
	else
		return (-1);
}
