/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:58:49 by nweber            #+#    #+#             */
/*   Updated: 2025/08/30 17:26:20 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../framework/libunit.h"
#include "dummy.h"

int	main(void)
{
	ft_putstr_fd(LIGHTCYAN""BOLD"DUMMY TESTING\n\n"RESET, 1);
	ft_dummy_launcher();
	ftu_print_final_result();
	return (0);
}
