/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 12:44:46 by nweber            #+#    #+#             */
/*   Updated: 2025/08/31 12:46:39 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	ft_pipe_error(void)
{
	int		pipe_fds[2];

	if (pipe(pipe_fds) == -1)
		return (-1);
	close(pipe_fds[0]);
	write(pipe_fds[1], "Hello 42", 9);
	close(pipe_fds[1]);
	return (0);
}
