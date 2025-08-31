/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_abort_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:31:28 by nmihaile          #+#    #+#             */
/*   Updated: 2025/08/31 12:44:29 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dummy.h"

// Remove all CFLAGS so that this demonstration function compiles on linux.

int	ft_abort_test(void)
{
	if (ft_abort_error() == 0)
		return (0);
	else
		return (-1);
}
