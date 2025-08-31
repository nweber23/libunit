/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:12:13 by nmihaile          #+#    #+#             */
/*   Updated: 2025/08/31 15:24:06 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	ftu_total_test_count(bool count_it)
{
	static int	count;

	if (count_it)
		++count;
	return (count);
}

int	ftu_total_test_passed(bool count_it)
{
	static int	passed_count;

	if (count_it)
		++passed_count;
	return (passed_count);
}

bool	ftu_count_routine_result(int count, int passed, bool count_it)
{
	static size_t	total_count;
	static size_t	total_passed;

	if (count_it)
	{
		total_count += count;
		total_passed += passed;
	}
	return (total_count == total_passed);
}
