/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_abort_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:31:28 by nmihaile          #+#    #+#             */
/*   Updated: 2025/08/31 11:46:39 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dummy.h"

// Remove all CFLAGS so that this demonstration function compiles on linux.

int	ft_abort_test(void)
{
	char	*p;

	p = malloc(1);
	if (!p)
		return (-1);
	free(p);
	free(p);
	return (0);
}
