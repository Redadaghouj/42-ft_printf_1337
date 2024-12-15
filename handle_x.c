/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:52:39 by mdaghouj          #+#    #+#             */
/*   Updated: 2024/12/15 11:34:38 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_len_x(int *len, t_flags *flags, unsigned long nb)
{
	if (flags->precision > *len)
		*len = flags->precision;
	if (flags->hash && nb)
		(*len) += 2;
	if (flags->precision == 0 && nb == 0)
		*len = 0;
	flags->width -= *len;
}

void	check_hash(t_flags flags, int *count, unsigned int nb, int type)
{
	if (flags.hash && nb != 0)
	{
		if (type == 'x')
			*(count) += ft_putstr("0x", 2);
		else
			*(count) += ft_putstr("0X", 2);
	}
}

void	handle_x(unsigned int nb, t_flags *flags, int *count, int type)
{
	int	len;
	int	pad;

	len = calc_hex(nb);
	handle_len_x(&len, flags, nb);
	handle_pad(*flags, &pad);
	check_bonus_flags(flags, count, nb);
	if (!flags->dash && pad == ' ' && flags->width > 0)
		handle_width_d(flags, count, pad);
	check_hash(*flags, count, nb, type);
	if (!flags->dash && pad == '0' && flags->width > 0)
		handle_width_d(flags, count, pad);
	flags->precision -= calc_hex(nb);
	handle_precision_d(flags, count);
	if (len > 0)
		putnbr_base(nb, *flags, count, type);
	if (flags->dash)
		handle_width_d(flags, count, pad);
}
