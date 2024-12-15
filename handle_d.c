/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:51:42 by mdaghouj          #+#    #+#             */
/*   Updated: 2024/12/15 12:23:31 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_len(long nb, t_flags *flags, int *len)
{
	if (flags->precision > *len)
		*len = flags->precision;
	if (nb < 0 || flags->space || flags->plus)
		(*len)++;
	if (flags->precision == 0 && nb == 0)
		*len = 0;
	flags->width -= *len;
}

void	handle_width_d(t_flags *flags, int *count, int pad)
{
	while (flags->width > 0)
	{
		(*count) += ft_putchar(pad);
		flags->width--;
	}
}

void	handle_precision_d(t_flags *flags, int *count)
{
	while (flags->precision > 0)
	{
		(*count) += ft_putchar('0');
		flags->precision--;
	}
}

void	handle_d(int nb, t_flags *flags, int *count)
{
	int	len;
	int	pad;

	len = calc_decimal(nb);
	handle_len(nb, flags, &len);
	handle_pad(*flags, &pad);
	if (flags->precision == 0 && nb == 0 && (flags->space || flags->plus))
		flags->width--;
	if (!flags->dash && pad == ' ' && flags->width > 0)
		handle_width_d(flags, count, pad);
	if (nb < 0)
		(*count) += ft_putchar('-');
	check_bonus_flags(flags, count, nb);
	if (!flags->dash && pad == '0' && flags->width > 0)
		handle_width_d(flags, count, pad);
	flags->precision -= calc_decimal(nb);
	handle_precision_d(flags, count);
	if (len > 0)
		ft_putnbr(nb, DECIMAL, *flags, count);
	if (flags->dash)
		handle_width_d(flags, count, pad);
}