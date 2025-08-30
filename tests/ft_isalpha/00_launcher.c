/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:45:12 by nweber            #+#    #+#             */
/*   Updated: 2025/08/30 14:11:58 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../framework/libunit.h"
#include "../../libft/libft.h"
#include "../test_functions.h"

// This right here, is our test routine
int	ft_isalpha_launcher(void)
{
	t_list	*testlist;

	testlist = NULL;
	load_test(&testlist, "Basic_Test", &ft_isalpha_basic_test);
	load_test(&testlist, "Failed_Test", &ft_isalpha_failed_test);
	return (launch_tests("ft_isalpha", testlist));
}
