/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:14:20 by mdaghouj          #+#    #+#             */
/*   Updated: 2024/12/15 15:58:25 by mdaghouj         ###   ########.fr       */
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
		handle_percentage(flags, count);
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

void	handle_percentage(t_flags *flags, int *count)
{
	int	pad;

	flags->width--;
	handle_pad(*flags, &pad);
	if (!flags->dash)
		print_width(flags, count, pad);
	(*count) += ft_putchar('%');
	if (flags->dash)
		print_width(flags, count, pad);
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
