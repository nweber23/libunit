/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:43:50 by nweber            #+#    #+#             */
/*   Updated: 2025/08/29 22:08:37 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../framework/libunit.h"
#include "test_functions.h"
#include <unistd.h>

int main(void)
{
	write(1, "Let the testing begin ...\n", 27);
	
	return (0);
}
