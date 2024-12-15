/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:44:44 by mdaghouj          #+#    #+#             */
/*   Updated: 2024/12/15 10:57:12 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_dash_s(t_flags *flags, char *str, int *count, int len)
{
	flags->width -= len;
	(*count) += ft_putstr(str, len);
	while (flags->width > 0)
	{
		(*count) += ft_putchar(' ');
		flags->width--;
	}
	init_flags(flags);
	return (*count);
}

void	handle_width_s(t_flags *flags, int *count, int len)
{
	if (flags->width > 0 && flags->precision > 0)
	{
		flags->width -= flags->precision;
		while (flags->width > 0)
		{
			(*count) += ft_putchar(' ');
			flags->width--;
		}
		flags->width = 0;
	}
	flags->width -= len;
	while (flags->width > 0)
	{
		(*count) += ft_putchar(' ');
		flags->width--;
	}
}

void	handle_precision_s(t_flags *flags, int *len)
{
	if (flags->precision >= 0 && flags->precision < *len)
		*len = flags->precision;
	else
		flags->precision = *len;
}
