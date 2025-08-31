/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:57:33 by nweber            #+#    #+#             */
/*   Updated: 2025/08/31 13:58:42 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_H
# define DUMMY_H

# include "../libft/libft.h"

// Helper
int	ft_bus_error(void);
int	ft_abort_error(void);
int	ft_fpe_error(void);
int	ft_pipe_error(void);
int	ft_sigill_error(void);
int	ft_timeout_error(void);

int	ft_dummy_launcher(void);
int	ft_ok_test(void);
int	ft_ko_test(void);
int	ft_segv_test(void);
int	ft_bus_error_test(void);
int	ft_abort_test(void);
int	ft_sigfpe_test(void);
int	ft_pipe_test(void);
int	ft_sigill_test(void);
int	ft_timeout_test(void);

#endif