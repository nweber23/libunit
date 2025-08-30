/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:43:50 by nweber            #+#    #+#             */
/*   Updated: 2025/08/30 19:49:48 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../framework/libunit.h"
#include "../framework/colors.h"
#include "../libft/libft.h"
#include "test_functions.h"

int	main(void)
{
	ft_putstr_fd(LIGHTCYAN""BOLD"-----------«««<< LETS TEST >>»»»-----------\n\n"RESET, 1);
	ft_isalpha_launcher();
	ft_strlen_launcher();
	ft_strcmp_launcher();
	ftu_print_final_result();
	return (0);
}
