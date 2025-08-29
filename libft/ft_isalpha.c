/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:07:50 by nmihaile          #+#    #+#             */
/*   Updated: 2025/08/14 17:48:06 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// branchless
int	ft_isalpha(int c)
{
	return (((unsigned int)(c - 'A') < 26) | ((unsigned int)(c - 'a') < 26));
}
