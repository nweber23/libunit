/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_empty_non_empty_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:58:49 by nweber            #+#    #+#             */
/*   Updated: 2025/08/30 18:59:14 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int	ft_strcmp_empty_non_nonempty_test(void)
{
	if (ft_strcmp("", "x") < 0)
		return (0);
	else
		return (-1);
}
