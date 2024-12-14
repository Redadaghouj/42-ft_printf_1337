/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda <reda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:14:20 by mdaghouj          #+#    #+#             */
/*   Updated: 2024/12/13 22:26:12 by reda             ###   ########.fr       */
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
		handle_d(ap, flags, count);
	else if (*format == 'u')
		putnbr_base(va_arg(ap, unsigned int), *flags, count, 'u');
	else if (*format == 'x')
		putnbr_base(va_arg(ap, unsigned int), *flags, count, 'x');
	else if (*format == 'X')
		putnbr_base(va_arg(ap, unsigned int), *flags, count, 'X');
	else if (*format == 'p')
	{
		ptr = va_arg(ap, void *);
		putnbr_base((unsigned long) ptr, *flags, count, 'p');
	}
	else if (*format == '%')
		(*count) += ft_putchar('%');
}

int	handle_len(int nb, t_flags flags)
{
	int len;

	len = calc_decimal(nb);
	if (flags.precision > len)
		len = flags.precision;
	flags.width -= len;
	if (flags.precision == 0 && nb == 0)
		len = 0;
	return (len)
}

void	handle_d(va_list ap, t_flags *flags, int *count)
{
	int	nb;
	int	len;

	len = 0;
	nb = va_arg(ap, int);
	len = handle_len(nb, *flags);
	ft_putnbr(nb, DECIMAL, *flags, count);
}

void	check_and_skip(const char **format, t_flags *flags)
{
	while (**format == '#' || **format == '+'
		|| **format == ' ' || **format == '.'
		|| (**format >= '0' && **format <= '9') || **format == '-')
	{
		if (**format == '#')
			set_flag(&flags->hash, format, 0);
		else if (**format == '+')
			set_flag(&flags->plus, format, 0);
		else if (**format == ' ')
			set_flag(&flags->space, format, 0);
		else if (**format == '.')
		{
			flags->precision = 0;
			(*format)++;
			set_flag(&flags->precision, format, 1);
		}
		else if (**format == '-')
			set_flag(&flags->dash, format, 0);
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
