/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_42char_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:43:15 by nweber            #+#    #+#             */
/*   Updated: 2025/08/30 18:43:59 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int	ft_strlen_42chars_test(void)
{
	if (ft_strlen("abcdefghijklmnopqrstuvwxyz0123456789abcdef") == 42)
		return (0);
	else
		return (-1);
}
