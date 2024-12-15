/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:54:33 by mdaghouj          #+#    #+#             */
/*   Updated: 2024/12/15 14:46:49 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_u(unsigned int nb, t_flags *flags, int *count)
{
	int	len;
	int	pad;

	len = calc_decimal(nb);
	handle_len(nb, flags, &len);
	handle_pad(*flags, &pad);
	check_bonus_flags(flags, count, nb);
	if (!flags->dash && pad == ' ' && flags->width > 0)
		print_width(flags, count, pad);
	if (!flags->dash && pad == '0' && flags->width > 0)
		print_width(flags, count, pad);
	flags->precision -= calc_decimal(nb);
	print_precision(flags, count);
	if (len > 0)
		putnbr_base_rec(nb, DECIMAL, count);
	if (flags->dash)
		print_width(flags, count, pad);
}
