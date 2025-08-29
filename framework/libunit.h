/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:41:34 by nweber            #+#    #+#             */
/*   Updated: 2025/08/29 20:37:54 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct t_test_suite;
typedef struct s_test_suite
{
	char			*name;
	int				(*f)(int c);
	int				expected;
	int				result;
	t_test_suite	*next;
}					t_test_suite;

void	load_test(t_test_suite *test_suite, char *test_name, int (*f)(int c));
void	launch_tests(t_test_suite *test_suite);

#endif
