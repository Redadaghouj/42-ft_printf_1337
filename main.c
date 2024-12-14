/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda <reda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:51:57 by mdaghouj          #+#    #+#             */
/*   Updated: 2024/12/13 21:49:16 by reda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	// DONE:
	// TEST: %s
	// // 0
	// TEST: %p
	// CHECK:
	// int a = 123;


	// int x = printf("|%20p|\n", &a); // |      0x7ffeef4f2780|
	// int b = ft_printf("|%20p|\n", &a);
	// x+=printf("|%-20p|\n", &a); // |0x7ffeecceb780      |
	// b+=ft_printf("|%-20p|\n", &a);
	// x+=printf("|%0p|\n", &a); // 0 is ignored
	// b+=ft_printf("|%0p|\n", &a);

	// FIXME:
	// END TEST;

	printf("|%05d|\n", 7);
	printf("|%-05d|\n", 7);
	printf("|%05.3d|\n", 7);
	printf("|%03.5d|\n", 7);
	printf("|%03.d|\n", 0);
	return (0);
}

// precision - len
// width - precision