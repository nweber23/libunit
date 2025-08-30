/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 21:09:34 by nweber            #+#    #+#             */
/*   Updated: 2025/08/30 18:44:12 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_FUNCTIONS_H
# define TEST_FUNCTIONS_H

// test ft_isalpha
int	ft_isalpha_launcher(void);
int	ft_isalpha_basic_test(void);
int	ft_isalpha_digit_test(void);
int	ft_isalpha_whitespace_test(void);
int	ft_islpha_zero_test(void);
int	ft_isalpha_underscore_test(void);
int	ft_isalpha_punctuation_test(void);
int	ft_isalpha_extended_ascii_test(void);
int	ft_isalpha_negative_test(void);
int	ft_isalpha_int_min_test(void);
int	ft_isalpha_int_max_test(void);

// test ft_strlen
int	ft_strlen_launcher(void);
int	ft_strlen_basic_test(void);
int	ft_strlen_null_test(void);
int	ft_strlen_empty_test(void);
int	ft_strlen_whitespace_test(void);
int	ft_strlen_42chars_test(void);

#endif
