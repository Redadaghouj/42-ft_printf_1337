/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:51:57 by mdaghouj          #+#    #+#             */
/*   Updated: 2024/12/14 18:45:41 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	// CHECK:

	// FIXME:
	printf("|%#62.12x|", -701921728);
	// printf(" %-2p ", 15);
	// printf(" %-3p ", 16);
	// printf(" %-4p ", 17);
	// printf(" %-11p %-12p ", INT_MIN, INT_MAX);
	// printf(" %-13p %-14p ", ULONG_MAX, -ULONG_MAX);
	puts("\n");
	ft_printf("|%#62.12x|", -701921728);
	// ft_printf(" %-2p ", 15);
	// ft_printf(" %-3p ", 16);
	// ft_printf(" %-4p ", 17);
	// ft_printf(" %-11p %-12p ", INT_MIN, INT_MAX);
	// ft_printf(" %-13p %-14p ", ULONG_MAX, -ULONG_MAX);
	return (0);
}
