/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:54:34 by nmihaile          #+#    #+#             */
/*   Updated: 2025/08/31 21:28:27 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../framework/libunit.h"
#include "../../libft/libft.h"
#include "../test_functions.h"

// This right here, is our test routine
int	ft_putnbr_fd_launcher(void)
{
	t_list	*testlist;

	testlist = NULL;
	load_test(&testlist, "Basic_Test", &ft_putnbr_fd_basic_test);
	load_test(&testlist, "Max_Int_Test", &ft_putnbr_fd_max_int_test);
	load_test(&testlist, "Overflow_Test", &ft_putnbr_fd_overflow_test);
	load_test(&testlist, "Min_Int_Test", &ft_putnbr_fd_min_int_test);
	return (launch_tests("ft_putnbr_fd", testlist));
}
