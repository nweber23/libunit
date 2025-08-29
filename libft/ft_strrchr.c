/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:16:47 by nmihaile          #+#    #+#             */
/*   Updated: 2025/08/14 15:16:34 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	uc;
	size_t			o;

	uc = (unsigned char)c;
	o = ft_strlen(s);
	while (o > 0 && (unsigned char)s[o] != uc)
		o--;
	if ((unsigned char)s[o] == uc)
		return ((char *)(s + o));
	return (NULL);
}
