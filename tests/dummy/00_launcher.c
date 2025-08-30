/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:58:34 by nweber            #+#    #+#             */
/*   Updated: 2025/08/30 17:08:53 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../framework/libunit.h"
#include "../dummy.h"

int	ft_dummy_launcher(void)
{
	t_list	*testlist;

	testlist = NULL;
	load_test(&testlist, "OK_Test", &ft_ok_test);
	load_test(&testlist, "KO_Test", &ft_ko_test);
	load_test(&testlist, "SEGV_Test", &ft_segv_test);
	load_test(&testlist, "BUSE_Test", &ft_bus_error_test);
	return (launch_tests("Dummy_Test", testlist));
}
