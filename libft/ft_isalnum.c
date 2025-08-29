/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:23:50 by nmihaile          #+#    #+#             */
/*   Updated: 2025/08/14 12:24:55 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// branchless
// This is data-dependent:
// Random input -> branchless version wins.
// Mostly ASCII letters/digits -> branchy version might win.

int	ft_isalnum(int c)
{
	return (((unsigned int)(c - 'A') < 26) |
		((unsigned int)(c - 'a') < 26) |
		((unsigned int)(c - '0') <= 9));
}
