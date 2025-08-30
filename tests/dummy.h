/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:57:33 by nweber            #+#    #+#             */
/*   Updated: 2025/08/30 19:56:48 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_H
# define DUMMY_H

# include "../libft/libft.h"

// Helper
int	ft_bus_error(void);

int	ft_dummy_launcher(void);
int	ft_ok_test(void);
int	ft_ko_test(void);
int	ft_segv_test(void);
int	ft_bus_error_test(void);
int	ft_abort_test(void);

#endif