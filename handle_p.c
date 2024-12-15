/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:52:34 by mdaghouj          #+#    #+#             */
/*   Updated: 2024/12/15 11:34:15 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_len_p(int *len, t_flags *flags, unsigned long nb)
{
	if (flags->precision > *len)
		*len = flags->precision;
	if (flags->precision == 0 && nb == 0)
		*len = 0;
	flags->width -= *len;
}

void	handle_p(unsigned long nb, t_flags *flags, int *count)
{
	int	len;
	int	pad;

	len = calc_hex(nb) + 2;
	handle_len_p(&len, flags, nb);
	handle_pad(*flags, &pad);
	check_bonus_flags(flags, count, nb);
	if (!flags->dash && pad == ' ' && flags->width > 0)
		handle_width_d(flags, count, pad);
	if (!flags->dash && pad == '0' && flags->width > 0)
		handle_width_d(flags, count, pad);
	flags->precision -= calc_hex(nb);
	handle_precision_d(flags, count);
	if (len > 0)
		putnbr_base(nb, *flags, count, 'p');
	if (flags->dash)
		handle_width_d(flags, count, pad);
}
