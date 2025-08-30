/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:57:33 by nweber            #+#    #+#             */
/*   Updated: 2025/08/30 17:47:20 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_H
# define DUMMY_H

# include "../libft/libft.h"

// Helper
int	ft_bus_error_linux(void);
int	ft_bus_error_mac(void);

int	ft_dummy_launcher(void);
int	ft_ok_test(void);
int	ft_ko_test(void);
int	ft_segv_test(void);
int	ft_bus_error_test(void);

#endif