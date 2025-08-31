/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:55:18 by nmihaile          #+#    #+#             */
/*   Updated: 2025/08/31 20:57:39 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../framework/libunit.h"
#include "../../libft/libft.h"

static void	caller(void)
{
	ft_putnbr_fd(42, 1);
}

int	ft_putnbr_fd_basic_test(void)
{
	if (compare_stdout(caller, "42") == 0)
		return (0);
	else
		return (-1);
}
