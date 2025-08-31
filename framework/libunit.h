/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:41:34 by nweber            #+#    #+#             */
/*   Updated: 2025/08/31 18:51:31 by nmihaile         ###   ########.fr       */
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
# include <fcntl.h>
# include "colors.h"
# include "../libft/libft.h"

// Test result codes
# define OK			0
# define KO			1
# define SEGV		2
# define BUSE		3
# define ABRT		4
# define SFPE		5
# define PIPE		6
# define SILL		7
# define TIMEOUT	8

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
	int			exit_code;
	int			sig_num;
	t_unit_test	*next;
}				t_unit_test;

void	load_test(t_list **lst, char *test_name, int (*f)(void));
int		launch_tests(char *func_name, t_list *lst);

// utils.c
void	ftu_print_error_fd(char *error_msg, char *test_name, int fd);
void	ftu_print_result(char *func_name, t_unit_test *unit_test);
void	ftu_print_routine_results(int count, int passed);
void	ftu_print_final_result(void);
void	ftu_write_log(char *func_name, t_list *lst, int count, int passed);

// utils-counter.c
int		ftu_total_test_count(bool count_it);
int		ftu_total_test_passed(bool count_it);
bool	ftu_count_routine_result(int count, int passed, bool count_it);

// utils-signal.c
void	ftu_timeout_handler(int sig);

#endif
