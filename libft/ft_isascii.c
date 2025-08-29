/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:07:19 by nmihaile          #+#    #+#             */
/*   Updated: 2025/08/14 12:24:58 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// branchless
// negative values will get hugh through the cast to unsigned

int	ft_isascii(int c)
{
	return ((unsigned int)(c) <= 127);
}
