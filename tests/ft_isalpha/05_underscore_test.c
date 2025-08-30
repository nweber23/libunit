/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_underscore_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:40:46 by nweber            #+#    #+#             */
/*   Updated: 2025/08/30 14:41:02 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int	ft_isalpha_underscore_test(void)
{
	if (ft_isalpha('_') != 1)
		return (0);
	else
		return (-1);
}
