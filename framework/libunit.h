/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:41:34 by nweber            #+#    #+#             */
/*   Updated: 2025/08/31 13:12:55 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdbool.h>
# include "colors.h"
# include "../libft/libft.h"

// Test result codes
# define OK			0
# define KO			1
# define SEGV		2
# define BUSE		3
# define ABRT		4
# define PIPE		5
# define TIMEOUT	6

# ifndef TIMEOUT_PERIOD
#  define TIMEOUT_PERIOD 10
# endif

# define FAILED_CREATE_UNITTEST	"Failed to create (and add) unit_test: "
# define FAILED_ADD_UNITTEST	"Failed to add unit_test test: "

typedef struct s_unit_test	t_unit_test;

typedef struct s_unit_test
{
	char		name[256];
	int			(*f)(void);
	int			status;
	t_unit_test	*next;
}				t_unit_test;

void	load_test(t_list **lst, char *test_name, int (*f)(void));
int		launch_tests(char *func_name, t_list *lst);

// utils.c
void	ftu_print_error_fd(char *error_msg, char *test_name, int fd);
void	ftu_print_result(char *func_name, t_unit_test *unit_test);
void	ftu_print_routine_results(int count, int passed);
void	ftu_print_final_result(void);

// utils-counter.c
bool	ftu_count_routine_result(int count, int passed, bool count_it);

// utils-signal.c
void	timeout_handler(int sig);

#endif
