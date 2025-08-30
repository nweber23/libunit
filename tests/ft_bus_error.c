/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bus_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:39:31 by nweber            #+#    #+#             */
/*   Updated: 2025/08/30 18:21:24 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#if defined(__i386__)
# undef FLAG
# define FLAG 0
#elif defined(__x86_64__)
# undef FLAG
# define FLAG 1
#endif

#ifdef __LINUX__
# define WE_ARE_ON_LINUX 1
#else
# define WE_ARE_ON_LINUX 0
#endif

static int	ft_bus_error_linux(void)
{
	char	arr[4];
	int		*ptr;

	if (FLAG == 1)
		__asm__("pushf\norl $0x40000,(%rsp)\npopf");
	else
		__asm__("pushf\norl $0x40000,(%esp)\npopf");
	ptr = (int *)(arr + 1);
	*ptr = 42;
	return (0);
}

static int	ft_bus_error_mac(void)
{
	static char	*str = "Hallo";

	str[0] = 'A';
	return (0);
}

int	ft_bus_error(void)
{
	if (WE_ARE_ON_LINUX)
		return (ft_bus_error_linux());
	else
		return (ft_bus_error_mac());
}
