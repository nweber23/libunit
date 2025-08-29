/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:56:30 by nmihaile          #+#    #+#             */
/*   Updated: 2025/08/14 15:34:51 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		uc;
	const unsigned char	*p;

	uc = c;
	p = (const unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (*p != uc && n-- > 1)
		p++;
	if (*p == uc)
		return ((void *)p);
	return (NULL);
}
