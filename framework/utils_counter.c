/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:12:13 by nmihaile          #+#    #+#             */
/*   Updated: 2025/08/30 16:22:51 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

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
