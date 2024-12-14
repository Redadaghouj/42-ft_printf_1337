/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:51:57 by mdaghouj          #+#    #+#             */
/*   Updated: 2024/12/14 16:59:02 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	// CHECK:

	// FIXME:

	// printf(" %.12p ", 0);
	// puts("\n");
	// ft_printf(" %.12p ", 0);
	// int x = printf("%-1x", 0);
	int x = printf("|%-4x|", 9);
	printf("\nx = %d", x);
	puts("\n");
	x = 0;
	// x += ft_printf("%-1x", 0);
	x += ft_printf("|%-4x|", 9);
	printf("\nx = %d", x);
	// printf(" %-1x ", 10);
	// printf(" %-3x ", 15);
	// printf(" %-4x ", 16);
	// printf(" %-5x ", 17);
	// printf(" %-1x ", 99);
	// printf(" %-1x ", -9);
	// printf(" %-10x ", INT_MIN);
	// printf(" %-11x ", LONG_MAX);
	// printf(" %-12x ", LONG_MIN);
	// printf(" %-13x ", UINT_MAX);
	// printf(" %-14x ", ULONG_MAX);
	// printf(" %-15x ", 9223372036854775807LL);
	return (0);
}
