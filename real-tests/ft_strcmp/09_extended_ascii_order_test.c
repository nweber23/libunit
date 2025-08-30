/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_extended_ascii_order_test.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:02:35 by nweber            #+#    #+#             */
/*   Updated: 2025/08/30 19:03:12 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int	ft_strcmp_extended_ascii_order_test(void)
{
	if (ft_strcmp("\x7F", "\x80") < 0)
		return (0);
	else
		return (-1);
}
