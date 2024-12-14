/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:14:16 by mdaghouj          #+#    #+#             */
/*   Updated: 2024/12/14 15:45:29 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	putnbr_base_rec(unsigned long nb, char *base, int *count)
{
	int base_len;

	base_len = ft_strlen(base);
	if (nb / base_len != 0)
		putnbr_base_rec((nb / base_len), base, count);
	*(count) += ft_putchar(base[nb % base_len]);
}

void	putnbr_base(unsigned long nb, t_flags flags, int *count, int type)
{
	char	*base;

	if (type == 'X')
		base = HEX_UP;
	else
		base = HEX_LW;
	if (type == 'p')
	{
		if (!nb)
		{
			*(count) += (ft_putstr("0x0", 3));
			return ;
		}
		if (flags.precision < 0)
			*(count) += ft_putstr("0x", 2);
	}
	if (flags.hash && nb != 0 && (type == 'x' || type == 'X'))
	{
		if (type == 'x')
			*(count) += ft_putstr("0x", 2);
		else
			*(count) += ft_putstr("0X", 2);
	}
	putnbr_base_rec(nb, base, count);
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

int	calc_decimal(long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
void	ft_putnbr(int nb, char *base, t_flags flags, int *count)
{
	if (nb == -2147483648)
	{
		(*count) += ft_putstr("2147483648", 10);
		return ;
	}
	if (nb < 0)
		nb = -nb;
	if (nb / 10 != 0)
		ft_putnbr((nb / 10), base, flags, count);
	(*count) += ft_putchar(base[nb % 10]);
}
