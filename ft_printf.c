/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:14:20 by mdaghouj          #+#    #+#             */
/*   Updated: 2024/12/14 20:16:35 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags(const char *format, int *count, va_list ap, t_flags *flags)
{
	void	*ptr;

	if (*format == 'c')
		(*count) += handle_char(va_arg(ap, int), flags);
	else if (*format == 's')
		(*count) += handle_string(va_arg(ap, char *), flags);
	else if (*format == 'd' || *format == 'i')
		handle_d(va_arg(ap, int), flags, count);
	else if (*format == 'u')
		handle_u(va_arg(ap, unsigned int), flags, count);
	else if (*format == 'x')
		handle_x(va_arg(ap, unsigned int), flags, count, 'x');
	else if (*format == 'X')
		handle_x(va_arg(ap, unsigned int), flags, count, 'X');
	else if (*format == 'p')
	{
		ptr = va_arg(ap, void *);
		handle_p((unsigned long) ptr, flags, count);
	}
	else if (*format == '%')
		(*count) += ft_putchar('%');
}

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

void	handle_pad(t_flags flags, int *pad)
{
	*pad = ' ';
	if (flags.precision > -1)
		*pad = ' ';
	else if (flags.zero && !flags.dash)
		*pad = '0';
}

void	handle_d(int nb, t_flags *flags, int *count)
{
	int	len;
	int	pad;

	len = calc_decimal(nb);
	handle_len(nb, flags, &len);
	handle_pad(*flags, &pad);	
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

void	handle_u(unsigned int nb, t_flags *flags, int *count)
{
	int	len;
	int	pad;

	len = calc_decimal(nb);
	handle_len(nb, flags, &len);
	handle_pad(*flags, &pad);	
	check_bonus_flags(flags, count, nb);
	if (!flags->dash && pad == ' ' && flags->width > 0)
		handle_width_d(flags, count, pad);
	if (nb < 0)
		(*count) += ft_putchar('-');
	if (!flags->dash && pad == '0' && flags->width > 0)
		handle_width_d(flags, count, pad);
	flags->precision -= calc_decimal(nb);
	handle_precision_d(flags, count);
	if (len > 0)
		putnbr_base_rec(nb, DECIMAL, count);
	if (flags->dash)
		handle_width_d(flags, count, pad);
}

void	handle_p(unsigned long nb, t_flags *flags, int *count)
{
	int	len;
	int	pad;
	len = calc_hex(nb);
	len += 2;
	handle_len(nb, flags, &len);
	handle_pad(*flags, &pad);	
	check_bonus_flags(flags, count, nb);
	if (!flags->dash && pad == ' ' && flags->width > 0)
		handle_width_d(flags, count, pad);
	if (nb < 0)
		(*count) += ft_putchar('-');
	if (!flags->dash && pad == '0' && flags->width > 0)
		handle_width_d(flags, count, pad);
	flags->precision -= calc_hex(nb);
	handle_precision_d(flags, count);
	if (len > 0)
		putnbr_base(nb, *flags, count, 'p');
	if (flags->dash)
		handle_width_d(flags, count, pad);
}

void	handle_x(unsigned int nb, t_flags *flags, int *count, int type)
{
	int	len;
	int	pad;

	len = calc_hex(nb);
	if (flags->precision > len)
		len = flags->precision;
	if (flags->hash && nb)
		len += 2;
	flags->width -= len;
	handle_pad(*flags, &pad);	
	check_bonus_flags(flags, count, nb);
	if (!flags->dash && pad == ' ' && flags->width > 0)
		handle_width_d(flags, count, pad);
	if (flags->hash && nb != 0)
	{
		if (type == 'x')
			*(count) += ft_putstr("0x", 2);
		else
			*(count) += ft_putstr("0X", 2);
	}
	if (!flags->dash && pad == '0' && flags->width > 0)
		handle_width_d(flags, count, pad);
	flags->precision -= calc_hex(nb);
	handle_precision_d(flags, count);
	if (len > 0)
		putnbr_base(nb, *flags, count, type);
	if (flags->dash)
		handle_width_d(flags, count, pad);
}

void	check_and_skip(const char **format, t_flags *flags)
{
	while (**format == '#' || **format == '+'
		|| **format == ' ' || **format == '.'
		|| (**format >= '0' && **format <= '9') || **format == '-')
	{
		if (**format == '#')
			set_flag(&flags->hash, format, 0);
		if (**format == '+')
			set_flag(&flags->plus, format, 0);
		if (**format == ' ')
			set_flag(&flags->space, format, 0);
		if (**format == '.')
		{
			flags->precision = 0;
			(*format)++;
			set_flag(&flags->precision, format, 1);
		}
		if (**format == '-')
			set_flag(&flags->dash, format, 0);
		if (**format == '0')
			set_flag(&flags->zero, format, 0);
		set_flag(&flags->width, format, 1);
	}
}

int	all(const char *format, va_list ap)
{
	int		count;
	t_flags	flags;

	init_flags(&flags);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			check_and_skip(&format, &flags);
			check_flags(format, &count, ap, &flags);
			init_flags(&flags);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, format);
	count = all(format, ap);
	va_end(ap);
	return (count);
}
