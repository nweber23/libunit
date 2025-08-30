/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:43:50 by nweber            #+#    #+#             */
/*   Updated: 2025/08/30 14:53:54 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../framework/libunit.h"
#include "../framework/colors.h"
#include "../libft/libft.h"
#include "test_functions.h"

int	main(void)
{
	ft_putstr_fd(LIGHTCYAN"Let the testing begin ...\n"RESET, 1);
	
	// launch ft_isalpha
	ft_isalpha_launcher();
	// launch ft_strlen
	ft_strlen_launcher();
	return (0);
}
