/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_min_int_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:01:20 by nmihaile          #+#    #+#             */
/*   Updated: 2025/08/31 21:03:09 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../framework/libunit.h"
#include "../../libft/libft.h"

static void	caller(void)
{
	ft_putnbr_fd(-2147483648, 1);
}

int	ft_putnbr_fd_min_int_test(void)
{
	if (compare_stdout(caller, "-2147483648") == 0)
		return (0);
	else
		return (-1);
}
