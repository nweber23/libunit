/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_case_sensitive_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:01:41 by nweber            #+#    #+#             */
/*   Updated: 2025/08/30 19:11:35 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int	ft_strcmp_case_sensitive_test(void)
{
	if (ft_strcmp("abc", "Abc") > 0)
		return (0);
	else
		return (-1);
}
