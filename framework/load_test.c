/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:55:24 by nmihaile          #+#    #+#             */
/*   Updated: 2025/08/31 18:05:25 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	load_test(t_list **lst, char *test_name, int (*f)(void))
{
	t_unit_test	*unit_test;
	t_list		*lst_item;

	unit_test = ft_calloc(1, sizeof(t_unit_test));
	if (unit_test == NULL)
	{
		ftu_print_error_fd(FAILED_CREATE_UNITTEST, test_name, 1);
		return ;
	}
	ft_strlcpy(unit_test->name, test_name, 255);
	unit_test->f = f;
	unit_test->sig_num = -1;
	unit_test->exit_code = -1;
	lst_item = ft_lstnew(&unit_test);
	if (lst_item == NULL)
	{
		free(unit_test);
		unit_test = NULL;
		ftu_print_error_fd(FAILED_ADD_UNITTEST, test_name, 1);
		return ;
	}
	lst_item->content = (void *)unit_test;
	lst_item->next = NULL;
	ft_lstadd_back(lst, lst_item);
}
