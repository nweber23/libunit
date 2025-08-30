/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_whitespace_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:41:21 by nweber            #+#    #+#             */
/*   Updated: 2025/08/30 18:41:44 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int	ft_strlen_whitespace_test(void)
{
	if (ft_strlen(" \t\n") == 3)
		return (0);
	else
		return (-1);
}
