/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_punctuation_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:54:40 by nweber            #+#    #+#             */
/*   Updated: 2025/08/30 14:54:55 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int	ft_isalpha_punctuation_test(void)
{
	if (ft_isalpha('*') != 1)
		return (0);
	else
		return (-1);
}
