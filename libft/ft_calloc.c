/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:08:30 by nmihaile          #+#    #+#             */
/*   Updated: 2025/08/18 14:26:37 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*buf;

	if (count && size > SIZE_MAX / count)
		return (NULL);
	buf = (char *)malloc(count * size * sizeof(char));
	if (buf == NULL)
		return (NULL);
	ft_memset((void *)buf, 0, count * size);
	return ((void *)buf);
}
