/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_extended_ascii_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:55:13 by nweber            #+#    #+#             */
/*   Updated: 2025/08/30 14:55:33 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int	ft_isalpha_extended_ascii_test(void)
{
	if (ft_isalpha(0xE9) != 1)
		return (0);
	else
		return (-1);
}
