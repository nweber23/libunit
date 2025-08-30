/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_diff_at_end_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:00:45 by nweber            #+#    #+#             */
/*   Updated: 2025/08/30 19:11:31 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int	ft_strcmp_diff_at_end_test(void)
{
	if (ft_strcmp("abcdefg", "abcdefh") < 0)
		return (0);
	else
		return (-1);
}
