/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:41:34 by nweber            #+#    #+#             */
/*   Updated: 2025/08/30 09:57:10 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>

// Test result codes
# define OK			 0
# define KO			-1
# define SEGV		-2
# define BUSE		-3

typedef struct s_unit_test t_unit_test;

typedef struct s_unit_test
{
	char		name[256];
	int			(*f)(void);
	t_unit_test	*next;
}				t_unit_test;

void	load_test(t_unit_test **unit_test, char *test_name, int (*f)(void));
int		launch_tests(t_unit_test *unit_test);

#endif
