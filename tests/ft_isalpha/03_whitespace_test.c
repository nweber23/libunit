/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_whitespace_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:20:44 by nweber            #+#    #+#             */
/*   Updated: 2025/08/30 14:23:58 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int	ft_isalpha_whitespace_test(void)
{
	if (ft_isalpha('\t') != 1)
		return (0);
	else
		return (-1);
}
