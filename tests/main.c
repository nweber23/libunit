/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:43:50 by nweber            #+#    #+#             */
/*   Updated: 2025/08/30 16:21:55 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../framework/libunit.h"
#include "../framework/colors.h"
#include "../libft/libft.h"
#include "test_functions.h"

int	main(void)
{
	ft_putstr_fd(LIGHTCYAN""BOLD"Let the testing begin ...\n\n"RESET, 1);
	ft_isalpha_launcher();
	ft_strlen_launcher();
	ftu_print_final_result();
	return (0);
}
