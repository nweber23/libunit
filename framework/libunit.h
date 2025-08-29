/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:41:34 by nweber            #+#    #+#             */
/*   Updated: 2025/08/29 19:14:07 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct s_unit_test
{
	char				test_name[256];
	void				*(*f)(void*);
	struct t_unit_test	*next;
}						t_unit_test;

void	load_test(t_unit_test *unit_test, char *test_name, void *(*f)(void*));
void	launch_tests(void);

#endif
