/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_equal_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:57:13 by nweber            #+#    #+#             */
/*   Updated: 2025/08/30 18:57:31 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int	ft_strcmp_equal_test(void)
{
	if (ft_strcmp("hello", "hello") == 0)
		return (0);
	else
		return (-1);
}
