/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:14:26 by mdaghouj          #+#    #+#             */
/*   Updated: 2024/12/15 19:43:23 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str, int len)
{
	write(1, str, len);
	return (len);
}

int	handle_string(char *str, t_flags *flags)
{
	int	count;
	int	len;

	count = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	handle_precision_s(flags, &len);
	if (flags->dash && flags->width)
		return (handle_dash_s(flags, str, &count, len));
	handle_width_s(flags, &count, len);
	if (!str && flags->precision == 0)
		return (0);
	count += ft_putstr(str, len);
	return (count);
}

int	handle_char(int c, t_flags *flags)
{
	int	count;

	count = 0;
	flags->width--;
	if (flags->dash)
		count += ft_putchar(c);
	while (flags->width > 0)
	{
		if (flags->zero)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
		flags->width--;
	}
	if (!flags->dash)
		count += ft_putchar(c);
	return (count);
}
