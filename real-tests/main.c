/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:43:50 by nweber            #+#    #+#             */
/*   Updated: 2025/08/31 12:02:32 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../framework/libunit.h"
#include "test_functions.h"

int	main(void)
{
	static char	header[] = \
		LIGHTCYAN""BOLD"-----------«««<< LETS TEST >>»»»-----------\n\n"RESET;

	ft_putstr_fd(header, 1);
	ft_isalpha_launcher();
	ft_strlen_launcher();
	ft_strcmp_launcher();
	ftu_print_final_result();
	return (0);
}
