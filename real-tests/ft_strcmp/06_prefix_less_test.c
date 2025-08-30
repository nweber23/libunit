/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_prefix_less_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:00:22 by nweber            #+#    #+#             */
/*   Updated: 2025/08/30 19:00:35 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int	ft_strcmp_prefix_less_test(void)
{
	if (ft_strcmp("abc", "abcd") < 0)
		return (0);
	else
		return (-1);
}
