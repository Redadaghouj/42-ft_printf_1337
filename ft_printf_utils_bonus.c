/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:25:59 by mdaghouj          #+#    #+#             */
/*   Updated: 2024/12/15 10:53:27 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flag(int *flag, const char **format, int do_while)
{
	if (do_while)
	{
		while (**format >= '0' && **format <= '9')
		{
			*flag = *flag * 10 + (**format - '0');
			(*format)++;
		}
	}
	else
	{
		*flag = 1;
		(*format)++;
	}
}

void	check_bonus_flags(t_flags *flags, int *count, int nb)
{
	if (flags->plus && nb >= 0)
	{
		*(count) += ft_putchar('+');
		flags->plus = 0;
		flags->space = 0;
	}
	if (flags->space && nb >= 0)
	{
		*(count) += ft_putchar(' ');
		flags->space = 0;
	}
}

int	calc_hex(unsigned long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

void	init_flags(t_flags *flags)
{
	flags->hash = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->precision = -1;
	flags->zero = 0;
	flags->dash = 0;
	flags->width = 0;
}

void	handle_pad(t_flags flags, int *pad)
{
	*pad = ' ';
	if (flags.precision > -1)
		*pad = ' ';
	else if (flags.zero && !flags.dash)
		*pad = '0';
}
