/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_pipe_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 11:21:48 by nmihaile          #+#    #+#             */
/*   Updated: 2025/08/31 11:38:46 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dummy.h"

int	ft_pipe_test(void)
{
	int		pipe_fds[2];

	if (pipe(pipe_fds) == -1)
		return (-1);
	close(pipe_fds[0]);
	write(pipe_fds[1], "Hello 42", 9);
	close(pipe_fds[1]);
	return (0);
}
